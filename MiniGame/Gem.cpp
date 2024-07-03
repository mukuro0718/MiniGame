#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Gem::Gem(const int _modelHandle,const int _price)
{
    this->modelHandle = MV1DuplicateModel(_modelHandle);
    this->price = _price;
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
    auto& json = JsonManager::GetInstance();
    int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::GEM);
    this->transform.pos.Convert(json.GetJson(jsonIndex)["INIT_POS"]);
    this->transform.scale.Convert(json.GetJson(jsonIndex)["INIT_SCALE"]);
    this->transform.rotate.Convert(json.GetJson(jsonIndex)["INIT_ROTATE"]);
    this->transform.rotate.DegToRad(this->transform.rotate);
}

/// <summary>
/// �X�V
/// </summary>
void Gem::Update()
{

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
}
