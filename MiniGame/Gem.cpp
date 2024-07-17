#include "Common.h"

/// <summary>
/// コンストラクタ
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
/// デストラクタ
/// </summary>
Gem::~Gem()
{

}

/// <summary>
/// 初期化
/// </summary>
void Gem::Init()
{
    /*シングルトンクラスのインスタンスの取得*/
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

    /*モデルの設定*/
    MV1SetScale         (this->modelHandle, this->transform.scale.value);
    MV1SetRotationXYZ   (this->modelHandle, this->transform.rotate.value);
    MV1SetPosition      (this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// 更新
/// </summary>
void Gem::Update()
{
    if (this->isShow)
    {
        /*当たり判定*/
        HitCheck();

        /*移動*/
        Move();

        /*モデルの回転*/
        this->transform.rotate.value.y += 10.0f;
        this->transform.rotate.DegToRad(this->transform.rotate);

        /*モデルの設定*/
        MV1SetRotationXYZ   (this->modelHandle, this->transform.rotate.value);
        MV1SetPosition      (this->modelHandle, this->transform.pos.value);
    }
}

/// <summary>
/// 移動
/// </summary>
void Gem::Move()
{
    /*シングルトンクラスのインスタンスの取得*/
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
/// 描画
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
/// 当たり判定
/// </summary>
void Gem::HitCheck()
{
    /*シングルトンクラスのインスタンスの取得*/
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
