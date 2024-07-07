#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Bazooka::Bazooka(const int _modelHandle)
	: Weapon(_modelHandle)
	, posOffset(0.0f)
{
	Init();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Bazooka::~Bazooka()
{

}

/// <summary>
/// ������
/// </summary>
void Bazooka::Init()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::WEAPON);

	/*�����o�ϐ��̏�����*/
	this->transform.scale	.Convert(json.GetJson(jsonIndex)["BAZOOKA_INIT_SCALE"]);
	this->transform.rotate	.Convert(json.GetJson(jsonIndex)["BAZOOKA_INIT_ROTATE"]);
	this->transform.rotate	.DegToRad(this->transform.rotate);
	this->posOffset			.Convert(json.GetJson(jsonIndex)["BAZOOKA_POS_OFFSET"]);
	/*���f���̐ݒ�*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);

}

/// <summary>
/// �X�V
/// </summary>
void Bazooka::Update()
{
	WrapVECTOR pos = this->transform.pos + this->posOffset;

	/*���f���̐ݒ�*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, pos.value);
}