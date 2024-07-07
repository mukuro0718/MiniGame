#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Shark::Shark(const int _modelHandle)
	: Amo(_modelHandle)
{
	Init();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Shark::~Shark()
{

}

/// <summary>
/// ������
/// </summary>
void Shark::Init()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::AMO);

	/*�����o�ϐ��̏�����*/
	this->posOffset.Convert(json.GetJson(jsonIndex)["SHARK_POS_OFFSET"]);
	this->isHit		= false;
	this->isOut		= false;
	this->isSet		= false;
	this->isRebel	= false;
	this->velocity	= json.GetJson(jsonIndex)["SHARK_VELOCITY"];
	this->radius = json.GetJson(jsonIndex)["SHARK_RADIUS"];
	this->hitPosOffset.Convert(json.GetJson(jsonIndex)["SHARK_HIT_POS_OFFSET"]);
	this->price = json.GetJson(jsonIndex)["SHARK_PRICE"];

	/*�g�����X�t�H�[���̐ݒ�*/
	SetTransform(json.GetJson(jsonIndex)["INIT_POS"], json.GetJson(jsonIndex)["INIT_ROTATE"], json.GetJson(jsonIndex)["INIT_SCALE"]);

	/*���f���̐ݒ�*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// �X�V
/// </summary>
void Shark::Update()
{
	HitCheck();

	Move();

	/*���f���̐ݒ�*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// �ړ�
/// </summary>
void Shark::Move()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::AMO);

	if (!this->isOut)
	{
		MoveOffScreen();
		if (this->transform.pos.value.x >= 100.0f || this->transform.pos.value.y >= 100.0f)
		{
			this->transform.pos = { 120.0,-20.0f,0.0 };
			this->isOut = true;
		}
	}
	else
	{
		if (this->isRebel)
		{
			this->moveVec = { 2.0f,0.0f,0.0f };
			this->transform.rotate = { 0.0f,0.0f,0.0f };
			this->transform.pos += this->moveVec.Scale(this->velocity);
		}
		else
		{
			ChangeScale();
			ChangeRotate();

			this->moveVec = { -2.0f,0.0f,0.0f };
			this->transform.rotate = { 0.0f,180.0f,0.0f };
			this->transform.rotate.DegToRad(this->transform.rotate);
			this->transform.pos += this->moveVec.Scale(this->velocity);
			if (this->transform.pos.value.x < -250.0f)
			{
				this->hitPosOffset.Convert(json.GetJson(jsonIndex)["SHARK_HIT_POS_OFFSET_REBEL"]);
				this->transform.pos = { -250.0,-50.0f,50.0 };
				this->isRebel = true;
			}
		}
	}
}