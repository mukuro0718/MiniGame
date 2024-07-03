#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Skydome::Skydome(const int _modelHandle)
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::SKYDOME);

	/*�g�����X�t�H�[���̐ݒ�*/
	this->transform.pos.Convert(json.GetJson(jsonIndex)["ORIGIN"]);
	this->transform.scale.Convert(json.GetJson(jsonIndex)["SCALE"]);
	this->transform.rotate.Convert(json.GetJson(jsonIndex)["ROTATE"]);

	/*���f���̕���*/
	this->modelHandle = MV1DuplicateModel(_modelHandle);

	/*���f���̐ݒ�*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Skydome::~Skydome()
{

}

/// <summary>
/// ������
/// </summary>
void Skydome::Init()
{

}

/// <summary>
/// �X�V
/// </summary>
void Skydome::Update()
{

	/*�`��*/
	Draw();
}

/// <summary>
/// �`��
/// </summary>
const void Skydome::Draw()const
{
	MV1DrawModel(this->modelHandle);
}