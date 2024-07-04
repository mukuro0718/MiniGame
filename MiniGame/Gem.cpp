#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Gem::Gem(const int _modelHandle,const int _price)
    : isSet(false)
    , modelHandle(0)
    , price(0)
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
    this->isSet = false;
    
    /*���f���̐ݒ�*/
    MV1SetScale(this->modelHandle, this->transform.scale.value);
    MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
    MV1SetPosition(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// �X�V
/// </summary>
void Gem::Update()
{
    Move();

    /*���f���̐ݒ�*/
    MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
    MV1SetPosition(this->modelHandle, this->transform.pos.value);

    /*�`��*/
    Draw();
}

/// <summary>
/// �ړ�
/// </summary>
void Gem::Move()
{
    /*�V���O���g���N���X�̃C���X�^���X�̎擾*/
    auto& json = JsonManager::GetInstance();
    int     jsonIndex = json.GetFileNameType(JsonManager::FileNameType::GEM);

    this->transform.pos.value.x += json.GetJson(jsonIndex)["MOVE_VELOCITY"];

    if (this->transform.pos.value.x <= json.GetJson(jsonIndex)["STOP_MOVE_X_POS"])
    {
        this->transform.pos.value.x = json.GetJson(jsonIndex)["STOP_MOVE_X_POS"];
    }
}

/// <summary>
/// �`��
/// </summary>
const void Gem::Draw()const
{
    MV1DrawModel(this->modelHandle);
}

const void Gem::SetPrice(const int _in)
{
    this->price = _in;
}

const void Gem::SetPos(const WrapVECTOR& _in)
{
    this->transform.pos = _in;
    this->isSet = true;
}
