#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
GamePlayer::GamePlayer(int _modelHandle)
	: Character		(_modelHandle)
	, jumpPower		(0.0f)
	, height		(0.0f)
	, floatPower	(0.0f)
	, isSit			(false)
	, isStun		(false)
	, isOnGround	(false)
	, isJump		(false)
	, countStartTime(0)
	, aliveTime		(0)
	, stunFrameCount(0)
{	
	/*������*/
	Init();

	/*�A�j���[�V�����̒ǉ�*/
	AddAnim();
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
GamePlayer::~GamePlayer()
{
}
/// <summary>
/// ������
/// </summary>
void GamePlayer::Init()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::PLAYER);

	/*�����o�ϐ��̏�����*/
	this->transform.pos.	Convert(json.GetJson(jsonIndex)["INIT_POS"]);
	this->transform.rotate.	Convert(json.GetJson(jsonIndex)["INIT_ROTATE"]);
	this->transform.rotate.	DegToRad(this->transform.rotate);
	this->transform.scale.	Convert(json.GetJson(jsonIndex)["INIT_SCALE"]);
	this->moveVec.			Convert(json.GetJson(jsonIndex)["ORIGIN"]);
	this->fixVec.			Convert(json.GetJson(jsonIndex)["ORIGIN"]);
	this->isOnGround		= false;
	this->isStun			= false;
	this->countStartTime	= GetNowCount();
	this->aliveTime			= 0;
	this->stunFrameCount	= 0;
	this->jumpPower			= 0.0f;
	this->height			= json.GetJson(jsonIndex)["STAND_HEIGHT"];
	this->radius			= json.GetJson(jsonIndex)["RADISU"];
	this->floatPower		= 0.0f;

	/*���f���̐ݒ�*/
	MV1SetScale			(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ	(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition		(this->modelHandle, this->transform.pos.value);

}
/// <summary>
/// �A�j���[�V�����̒ǉ�
/// </summary>
void GamePlayer::AddAnim()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::PLAYER);

	vector<int> animIndex = json.GetJson(jsonIndex)["ANIM_INDEX"];
	for (int i = 0; i < animIndex.size(); i++)
	{
		this->anim->Add(-1, animIndex[i]);
	}
}
/// <summary>
/// �A�j���[�V�����̕ύX
/// </summary>
void GamePlayer::ChangeAnim()
{
	if (this->isJump)
	{
		this->anim->Play(&this->modelHandle, static_cast<int>(AnimType::JUMP), 0.2f);
	}
	else if (this->isSit)
	{
		this->anim->Play(&this->modelHandle, static_cast<int>(AnimType::SIT), 1.0f);
	}
	else
	{
		this->anim->Play(&this->modelHandle, static_cast<int>(AnimType::IDLE), 0.5f);
	}
}
/// <summary>
/// �X�V
/// </summary>
void GamePlayer::Update()
{
	/*�ړ�*/
	Move();

	/*���f���̐ݒ�*/
	MV1SetPosition		(this->modelHandle, this->transform.pos.value);
	MV1SetRotationXYZ	(this->modelHandle, this->transform.rotate.value);

	/*�`��*/
	Draw();
}
/// <summary>
/// �ړ��x�N�g���̕␳(�����,�M�~�b�N)
/// </summary>
void GamePlayer::FixMoveVec()
{
	//this->fixVec = _info.fixVec;
	//if (!this->isStun)
	//{
	//	this->isStun = _info.isHitAttack;
	//	if (this->isStun)
	//	{
	//		this->hitCount++;
	//	}
	//}
	//this->moveVec = VAdd(this->moveVec, this->fixVec);
}
/// <summary>
/// �ړ�
/// </summary>
void GamePlayer::Move()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& input = InputManager::GetInstance();
	auto& json = JsonManager::GetInstance();

	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::PLAYER);
	int pad = input.GetPadState();

	/*�㏸�i����A�{�^����������Ă�����j*/
	if (pad & PAD_INPUT_2 || CheckHitKey(KEY_INPUT_SPACE))
	{
		zAngle += static_cast<float>(json.GetJson(jsonIndex)["ADD_ANGLE"]);
		floatPower += static_cast<float>(json.GetJson(jsonIndex)["ADD_JUMP_POWER"]);
	}
	
	/*���~�iA�{�^����������Ă��Ȃ�������j*/
	else
	{
		zAngle -= static_cast<float>(json.GetJson(jsonIndex)["DECREASE_ANGLE"]);
		floatPower -= static_cast<float>(json.GetJson(jsonIndex)["DECREASE_JUMP_POWER"]);
	}

	/*���̍��W�̏��/�����l*/
	if (floatPower >= json.GetJson(jsonIndex)["MAX_JUMP_POWER"])
	{
		floatPower = json.GetJson(jsonIndex)["MAX_JUMP_POWER"];
	}
	else if (floatPower < json.GetJson(jsonIndex)["MIN_JUMP_POWER"])
	{
		floatPower = json.GetJson(jsonIndex)["MIN_JUMP_POWER"];
	}
	if (zAngle >= json.GetJson(jsonIndex)["MAX_ANGLE"])
	{
 		zAngle = json.GetJson(jsonIndex)["MAX_ANGLE"];
	}
	else if (zAngle < json.GetJson(jsonIndex)["MIN_ANGLE"])
	{
		zAngle = json.GetJson(jsonIndex)["MIN_ANGLE"];
	}

	/*�ړ��x�N�g���̍X�V*/
	this->moveVec.value.y = floatPower;

	/*��]���̍X�V*/
	this->transform.rotate.value.z = zAngle * (DX_PI_F / 180.0f);

	/*���W�̍X�V*/
	this->transform.pos += this->moveVec;

	/*���̍��W�̏��/�����l*/
	if (this->transform.pos.value.y >= json.GetJson(jsonIndex)["MAX_Y"])
	{
		this->transform.pos.value.y = json.GetJson(jsonIndex)["MAX_Y"];
	}
	else if (this->transform.pos.value.y <= json.GetJson(jsonIndex)["MIN_Y"])
	{
		this->transform.pos.value.y = json.GetJson(jsonIndex)["MIN_Y"];
	}
}
/// <summary>
/// �t���O�̏�Ԃ�ύX
/// </summary>
void GamePlayer::ChangeFlagsState()
{
	
}

/// <summary>
/// ���Ԃ̌v��
/// </summary>
void GamePlayer::CountTime()
{
	this->aliveTime = GetNowCount() - this->countStartTime;
}