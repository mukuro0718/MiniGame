#include "Common.h"

CharacterManager* CharacterManager::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
CharacterManager::CharacterManager()
	: player(nullptr)
	, isShowBoss(false)
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& asset = LoadingAsset::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::ENEMY);

	/*�C���X�^���X�̍쐬*/
	this->player = new GamePlayer(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::CAR)));
	this->enemy.emplace_back(new Normal(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::BLUE_CAR)), json.GetJson(jsonIndex)["CAR_MOVE_POS1"]));
	this->enemy.emplace_back(new Normal(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::GRY_CAR)), json.GetJson(jsonIndex)["CAR_MOVE_POS2"]));
	this->enemy.emplace_back(new Normal(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::GREEN_CAR)), json.GetJson(jsonIndex)["CAR_MOVE_POS3"]));
	this->enemy.emplace_back(new Normal(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::RED_CAR)), json.GetJson(jsonIndex)["CAR_MOVE_POS4"]));
	this->enemy.emplace_back(new Boss(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::POLICE_CAR)), json.GetJson(jsonIndex)["BOSS_MOVE_POS"]));
	
	Init();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CharacterManager::~CharacterManager()
{
	if (this->player != nullptr)
	{
		delete(this->player);
		this->player = nullptr;
	}
	for (int i = 0; i < this->enemy.size(); i++)
	{
		if (this->enemy[i] != nullptr)
		{
			delete(this->enemy[i]);
			this->enemy[i] = nullptr;
		}
	}
}

/// <summary>
/// ������
/// </summary>
void CharacterManager::Init()
{
	this->nowMoveEnemy = 0;
	this->isShowBoss = false;
}

/// <summary>
/// �X�V
/// </summary>
void CharacterManager::Update()
{
	ChangeNowMoveEnemy();
	this->player->Update();
	for (int i = 0; i < this->nowMoveEnemy; i++)
	{
		this->enemy[i]->Update();
	}
}

/// <summary>
/// �ғ����Ă���G�l�~�[���̕ύX
/// </summary>
void CharacterManager::ChangeNowMoveEnemy()
{
	auto& timer = GameTimer::GetInstance();

	/*�����ғ����Ă���G�l�~�[�̐������������������*/
	if (this->nowMoveEnemy < this->enemy.size())
	{
		if (timer.GetElapsetFrame() == 0 &&
			timer.GetElapsetTime() % 2 == 0)
		{
			this->nowMoveEnemy++;
			//����ȏ�ɂȂ�����
			if (this->nowMoveEnemy >= enemy.size())
			{
				this->isShowBoss = true;
			}
		}
	}
}

/// <summary>
/// �v���C���[���W��getter
/// </summary>
const WrapVECTOR& CharacterManager::GetPlayerPos()const
{
	return this->player->GetTransform().pos;
}

/// <summary>
/// �G�̐���getter
/// </summary>
const int CharacterManager::GetEnemyNum()const
{
	return this->enemy.size();
}

/// <summary>
/// �G�̍��W��getter
/// </summary>
const WrapVECTOR& CharacterManager::GetEnemyPos(const int _index)const
{
	return this->enemy[_index]->GetTransform().pos;
}


const int CharacterManager::GetNowMoveEnemyNum()const
{
	return this->nowMoveEnemy;
}


const bool CharacterManager::GetIsShowBoss()const
{
	return this->isShowBoss;
}


const bool CharacterManager::GetIsStop(const int _index)const
{
	return this->enemy[_index]->GetIsStop();
}


const int CharacterManager::GetPlayerPrice()const
{
	return this->player->GetPrice();
}

const GamePlayer& CharacterManager::GetPlayerInstance()
{
	return *this->player;
}
