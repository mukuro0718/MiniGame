#include "Common.h"

CharacterManager* CharacterManager::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
CharacterManager::CharacterManager()
	: player(nullptr)
	, isShowBoss(false)
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& asset = LoadingAsset::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::ENEMY);

	/*インスタンスの作成*/
	this->player = new GamePlayer(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::CAR)));
	this->enemy.emplace_back(new Normal(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::BLUE_CAR)), json.GetJson(jsonIndex)["CAR_MOVE_POS1"]));
	this->enemy.emplace_back(new Normal(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::GRY_CAR)), json.GetJson(jsonIndex)["CAR_MOVE_POS2"]));
	this->enemy.emplace_back(new Normal(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::GREEN_CAR)), json.GetJson(jsonIndex)["CAR_MOVE_POS3"]));
	this->enemy.emplace_back(new Normal(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::RED_CAR)), json.GetJson(jsonIndex)["CAR_MOVE_POS4"]));
	this->enemy.emplace_back(new Boss(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::POLICE_CAR)), json.GetJson(jsonIndex)["BOSS_MOVE_POS"]));
	
	Init();
}

/// <summary>
/// デストラクタ
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
/// 初期化
/// </summary>
void CharacterManager::Init()
{
	this->nowMoveEnemy = 0;
	this->isShowBoss = false;
}

/// <summary>
/// 更新
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
/// 稼働しているエネミー数の変更
/// </summary>
void CharacterManager::ChangeNowMoveEnemy()
{
	auto& timer = GameTimer::GetInstance();

	/*もし稼働しているエネミーの数が上限未満だったら*/
	if (this->nowMoveEnemy < this->enemy.size())
	{
		if (timer.GetElapsetFrame() == 0 &&
			timer.GetElapsetTime() % 2 == 0)
		{
			this->nowMoveEnemy++;
			//上限以上になったら
			if (this->nowMoveEnemy >= enemy.size())
			{
				this->isShowBoss = true;
			}
		}
	}
}

/// <summary>
/// プレイヤー座標のgetter
/// </summary>
const WrapVECTOR& CharacterManager::GetPlayerPos()const
{
	return this->player->GetTransform().pos;
}

/// <summary>
/// 敵の数のgetter
/// </summary>
const int CharacterManager::GetEnemyNum()const
{
	return this->enemy.size();
}

/// <summary>
/// 敵の座標のgetter
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
