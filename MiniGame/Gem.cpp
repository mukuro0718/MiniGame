#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Gem::Gem(const int _modelHandle,const int _price)
    : isSet(false)
    , isHit(false)
    , isShow(true)
    , modelHandle(0)
    , price(0)
    , prevPos(0.0f)
    , percent(0.0f)

{
    this->modelHandle = MV1DuplicateModel(_modelHandle);
    this->price = _price;
    Init();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Gem::~Gem()
{

}

/// <summary>
/// ������
/// </summary>
void Gem::Init()
{
    /*�V���O���g���N���X�̃C���X�^���X�̎擾*/
    auto&   json        = JsonManager::GetInstance();
    int     jsonIndex   = json.GetFileNameType(JsonManager::FileNameType::GEM);
    this->transform.pos     .Convert(json.GetJson(jsonIndex)["INIT_POS"]);
    this->transform.scale   .Convert(json.GetJson(jsonIndex)["INIT_SCALE"]);
    this->transform.rotate  .Convert(json.GetJson(jsonIndex)["INIT_ROTATE"]);
    this->transform.rotate  .DegToRad(this->transform.rotate);
    this->isSet             = false;
    this->isHit             = false;
    this->isShow            = true;
    this->radius            = json.GetJson(jsonIndex)["GEM_RADIUS"];
    this->hitPosOffset      .Convert(json.GetJson(jsonIndex)["GEM_HITPOS_OFFSET"]);
    this->prevPos           = this->transform.pos;
    this->percent           = 0.0f;

    /*���f���̐ݒ�*/
    MV1SetScale         (this->modelHandle, this->transform.scale.value);
    MV1SetRotationXYZ   (this->modelHandle, this->transform.rotate.value);
    MV1SetPosition      (this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// �X�V
/// </summary>
void Gem::Update()
{
    if (this->isShow)
    {
        /*�����蔻��*/
        HitCheck();

        /*�ړ�*/
        Move();

        /*���f���̉�]*/
        this->transform.rotate.value.y += 10.0f;
        this->transform.rotate.DegToRad(this->transform.rotate);

        /*���f���̐ݒ�*/
        MV1SetRotationXYZ   (this->modelHandle, this->transform.rotate.value);
        MV1SetPosition      (this->modelHandle, this->transform.pos.value);
    }
}

/// <summary>
/// �ړ�
/// </summary>
void Gem::Move()
{
    /*�V���O���g���N���X�̃C���X�^���X�̎擾*/
    auto&   json        = JsonManager::GetInstance();
    int     jsonIndex   = json.GetFileNameType(JsonManager::FileNameType::GEM);
    if (!this->isHit)
    {
        this->transform.pos.value.x += json.GetJson(jsonIndex)["MOVE_VELOCITY"];

        if (this->transform.pos.value.x <= json.GetJson(jsonIndex)["STOP_MOVE_X_POS"])
        {
            this->transform.pos.value.x = json.GetJson(jsonIndex)["STOP_MOVE_X_POS"];
        }
        this->prevPos = this->transform.pos;
    }
    else
    {
        WrapVECTOR targetPos = 0.0f;
        targetPos.Convert(json.GetJson(jsonIndex)["GEM_TARGET_POS"]);

        WrapVECTOR posToTargetVec = targetPos - this->prevPos;
        
        WrapVECTOR middlePos = 0.0f;
        middlePos.value = VTransform(posToTargetVec.value, MGetRotZ(-90.0f * (DX_PI_F / 180.0f)));
        middlePos += this->prevPos;
        
        this->transform.pos = BezirPoint(this->percent, this->prevPos, middlePos, targetPos);
        this->percent += 0.05f;
        if (this->percent > 1.0f)
        {
            this->isShow = false;
        }
        DrawSphere3D(targetPos.value, this->radius, 16, GetColor(255, 0, 0), GetColor(255, 0, 0), FALSE);
    }
}

/// <summary>
/// �`��
/// </summary>
const void Gem::Draw()const
{
    if (this->isShow)
    {
        MV1DrawModel(this->modelHandle);
//#ifdef _DEBUG
//        WrapVECTOR centerPos = this->transform.pos;
//        centerPos += this->hitPosOffset;
//        DrawSphere3D(centerPos.value, this->radius, 16, GetColor(255, 0, 0), GetColor(255, 0, 0), FALSE);
//#endif // _DEBUG
    }
}

/// <summary>
/// �����蔻��
/// </summary>
void Gem::HitCheck()
{
    /*�V���O���g���N���X�̃C���X�^���X�̎擾*/
    auto& collision = Collision::GetInstance();
    auto& character = CharacterManager::GetInstance();

    if (!this->isHit)
    {
        this->isHit = collision.SphereAndSphereCollision(*this, character.GetPlayerInstance())->isHit;
    }
}

const void Gem::SetPrice(const int _in)
{
    this->price = _in;
}

const void Gem::SetPos(const WrapVECTOR& _in)
{
    this->transform.pos = _in;
    this->isSet         = true;
}
WrapVECTOR& Gem::BezirPoint(const float _percent, const WrapVECTOR& _pos1, const WrapVECTOR& _pos2, const WrapVECTOR& _pos3)
{
    WrapVECTOR out = { 0.0f,0.0f,0.0f };
    float t = (1.0f - _percent);
    out.value.x = t * t * _pos1.value.x + 2 * _percent * t * _pos2.value.x + _pos3.value.x * _percent * _percent;
    out.value.y = t * t * _pos1.value.y + 2 * _percent * t * _pos2.value.y + _pos3.value.y * _percent * _percent;
    return out;
}
