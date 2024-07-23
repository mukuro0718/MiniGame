#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Boss::Boss(const int _modelHandle, const int _breakModelHandle, const vector<float> _movePos)
	: Enemy(_modelHandle)
	, velocity(0.0f)
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::ENEMY);

	/*�g�����X�t�H�[���̐ݒ�*/
	this->transform.pos		.Convert(json.GetJson(jsonIndex)["INIT_POS"]);
	this->transform.scale	.Convert(json.GetJson(jsonIndex)["BOSS_INIT_SCALE"]);
	this->transform.rotate	.Convert(json.GetJson(jsonIndex)["BOSS_INIT_ROTATE"]);
	this->transform.rotate	.DegToRad(this->transform.rotate);
	this->moveTargetPos		.Convert(_movePos);
	this->breakModelHandle = MV1DuplicateModel(_breakModelHandle);

	Init();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Boss::~Boss()
{

}

/// <summary>
/// ������
/// </summary>
void Boss::Init()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::ENEMY);

	/*�����o�ϐ��̏�����*/
	this->initPos		.Convert(json.GetJson(jsonIndex)["INIT_POS"]);
	this->transform.pos = this->initPos;
	this->velocity		= 0.0f;
	this->state			= StateType::MOVE;
	this->modelHandle	= this->normalModelHandle;
	this->isHit			= false;
	this->isStop = false;
	/*���f���̐ݒ�*/
	MV1SetScale			(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ	(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition		(this->modelHandle, this->transform.pos.value);

}

/// <summary>
/// �X�V
/// </summary>
void Boss::Update()
{
	auto& timer = GameTimer::GetInstance();
	auto& sound = Sound::GetInstance();

	/*���x�̍X�V*/
	UpdateVelocity();

	/*��Ԃ̐؂�ւ�*/
	ChangeFlagsState();

	if(this->isHit)
	{
		this->transform.pos.value.x -= 2.0f;
	}
	else
	{
		/*�ړ�*/
		Move();
		HitCheck();
	}

	sound.PlayPlayerExplosionSound();
	/*���f���̐ݒ�*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
}

void Boss::HitCheck()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& collision = Collision::GetInstance();
	auto& amo = AmoManager::GetInstance();
	/*�e�Ƃ̓����蔻��*/
//�g�p���Ă��鋅�̐����擾
	vector<int> useAmoNum = amo.GetNowUseNum();
	//�e�̐��������[�v
	for (int i = 0; i < useAmoNum.size(); i++)
	{
		for (int j = 0; j < useAmoNum[i]; j++)
		{
			//�v���C���[�ƒe�̓����蔻����X�t�B�A�łƂ�i�e�̂ق��̓J�v�Z���̂ق����ǂ������j
			this->hitResult = collision.SphereAndSphereCollision(*this, amo.GetAmoInstance(i, j));
			//�������Ă�����
			if (this->hitResult->isHit)
			{
				if (!this->isHit)
				{
					auto& sound = Sound::GetInstance();
					sound.OnIsPlayPlayerExplosionSound();
				}
				this->isHit = true;
				this->modelHandle = this->breakModelHandle;
			}
		}
	}
}

/// <summary>
/// ���x�̍X�V
/// </summary>
void Boss::UpdateVelocity()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::ENEMY);

}

/// <summary>
/// ���x�̍X�V
/// </summary>
float Boss::RandomY()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::ENEMY);
	float	out			= static_cast<float>(GetRand(json.GetJson(jsonIndex)["RANDOM_Y_RANGE"]));

	if (GetRand(0) == 0)
	{
		return out * -1.0f;
	}
	return out;
}
/// <summary>
/// ��Ԃ̕ω�
/// </summary>
void Boss::ChangeFlagsState()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto&	timer		= GameTimer::GetInstance();
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::ENEMY);
	
	/*�ړ����*/
	if (this->state == StateType::MOVE && this->transform.pos.value.x >= 0.0f)
	{
		this->state = StateType::ATTACK;
	}
	/*�U����*/
	else if (this->state == StateType::ATTACK)
	{
		this->state = StateType::MOVE;
		this->transform.pos = initPos;
		this->transform.pos.value.y = RandomY();
	}


}