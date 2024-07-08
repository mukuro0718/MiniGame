#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
GameStage::GameStage(const int _modelHandle,const WrapVECTOR& _pos)
	: modelHandle	(0)
	, initPos		(0.0f)
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::STAGE);

	/*���f���̕���*/
	this->modelHandle = MV1DuplicateModel(_modelHandle);
	Init();
	this->transform.pos = _pos;
}
void GameStage::Init()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::STAGE);

	/*�g�����X�t�H�[���̐ݒ�*/
	this->transform.scale	.Convert(json.GetJson(jsonIndex)["ROAD_SCALE"]);
	this->transform.rotate	.Convert(json.GetJson(jsonIndex)["ROAD_ROTATE"]);
	this->transform.rotate	.DegToRad(this->transform.rotate);
	this->transform.pos.value.x = 240.0f;
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
GameStage::~GameStage()
{
}
/// <summary>
/// �X�V
/// </summary>
void GameStage::Update()
{
	this->transform.pos.value.x -= 2.0f;
	if (this->transform.pos.value.x <= -240.0f)
	{
		Init();
	}
	/*���f���̐ݒ�*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
}
/// <summary>
/// �`��
/// </summary>
const void GameStage::Draw()const
{
	/*�n�ʂ̕`��*/
	MV1DrawModel(this->modelHandle);
}
