#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Normal::Normal(const int _modelHandle, const vector<float> _movePos)
	: Enemy(_modelHandle)
	, velocity(0.0f)
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::ENEMY);
		
	/*�g�����X�t�H�[���̐ݒ�*/
	this->transform.pos		.Convert(json.GetJson(jsonIndex)["INIT_POS"]);
	this->transform.scale	.Convert(json.GetJson(jsonIndex)["NORMAL_INIT_SCALE"]);
	this->transform.rotate	.Convert(json.GetJson(jsonIndex)["NORMAL_INIT_ROTATE"]);
	this->transform.rotate	.DegToRad(this->transform.rotate);
	this->moveTargetPos		.Convert(_movePos);

	Init();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Normal::~Normal()
{

}

/// <summary>
/// ������
/// </summary>
void Normal::Init()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::ENEMY);

	/*�����o�ϐ��̏�����*/
	this->initPos		.Convert(json.GetJson(jsonIndex)["INIT_POS"]);
	this->transform.pos = this->initPos;
	this->state			= StateType::MOVE;
	this->velocity		= 0.0f;
	this->isStop		= false;

	/*���f���̐ݒ�*/
	MV1SetScale			(this->modelHandle,this->transform.scale.value);
	MV1SetRotationXYZ	(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition		(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// �X�V
/// </summary>
void Normal::Update()
{
	auto& character = CharacterManager::GetInstance();

	if (character.GetIsShowBoss())
	{
		MoveOffScreen();
	}
	else
	{
		/*�ړ�*/
		Move();
	}
	/*���f���̐ݒ�*/
	MV1SetScale			(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ	(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition		(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// ��Ԃ̕ω�
/// </summary>
void Normal::ChangeFlagsState()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto&	timer		= GameTimer::GetInstance();
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::ENEMY);


	
}