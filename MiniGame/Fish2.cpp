#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Fish2::Fish2(const int _modelHandle, const int _imageHandle)
	: Amo(_modelHandle, _imageHandle)
{
	Init();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Fish2::~Fish2()
{

}

/// <summary>
/// ������
/// </summary>
void Fish2::Init()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::AMO);

	/*�����o�ϐ��̏�����*/
	this->posOffset.Convert(json.GetJson(jsonIndex)["FISH_POS_OFFSET"]);
	this->isHit		= false;
	this->isOut		= false;
	this->isSet = false;
	this->isSetMoveTargetPos = false;

	this->velocity = json.GetJson(jsonIndex)["FISH2_VELOCITY"];
	this->radius = json.GetJson(jsonIndex)["FISH2_RADIUS"];
	this->hitPosOffset.Convert(json.GetJson(jsonIndex)["FISH2_HIT_POS_OFFSET"]);

	SetTransform(json.GetJson(jsonIndex)["INIT_POS"], json.GetJson(jsonIndex)["CHANGE_ROTATE"], json.GetJson(jsonIndex)["CHANGE_SCALE"]);

	/*���f���̐ݒ�*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// �X�V
/// </summary>
void Fish2::Update()
{
	HitCheck();

	Move();
	ChangeRotate();
	ChangeScale();
	Swim();

	/*���f���̐ݒ�*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// �ړ�
/// </summary>
void Fish2::Move()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::AMO);

	if (!this->isOut)
	{
		//�ړ��ڕW���W��ݒ肵�Ă��Ȃ�������ݒ肷��
		if (!this->isSetMoveTargetPos)
		{
			//x,z���͌��߂�ꂽ�ʒu�ŁAy���̂݃����_���ɂ���
			this->moveTargetPos = { json.GetJson(jsonIndex)["MOVE_TARGET_X_POS"],GetRandom(10),0.0 };
			//�t���O�𗧂Ă�
			this->isSetMoveTargetPos = true;
		}
		else
		{
			WrapVECTOR moveTargetToPosVec = this->moveTargetPos - this->transform.pos;
			this->moveVec = moveTargetToPosVec.Norm();
			float moveTargetToPosVecSize = moveTargetToPosVec.Size();
			if (moveTargetToPosVecSize <= 5.0f)
			{
				this->isOut = true;
				this->transform.pos = this->moveTargetPos;
			}
			else
			{
				this->transform.pos += this->moveVec;
			}

			/*MoveOffScreen();
			if (this->transform.pos.value.x >= 100.0f || this->transform.pos.value.y >= 100.0f)
			{
				this->transform.pos = { 120.0,GetRandom(10),0.0 };
				this->isOut = true;
			}*/
		}
	}
	else
	{
		this->moveVec = { -2.0f,0.0f,0.0f };
		this->transform.rotate = { 0.0f,180.0f,0.0f };
		this->transform.rotate.DegToRad(this->transform.rotate);
		this->transform.pos += this->moveVec.Scale(this->velocity);
	}

}