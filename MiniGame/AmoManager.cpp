#include "Common.h"

AmoManager* AmoManager::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
AmoManager::AmoManager()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& asset = LoadingAsset::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::AMO);
	auto& character = CharacterManager::GetInstance();

	vector<Amo*> fish1;
	vector<Amo*> fish2;
	vector<Amo*> fish3;
	vector<Amo*> fish4;
	vector<Amo*> shark;
	/*インスタンスの作成*/
	for (int i = 0; i < json.GetJson(jsonIndex)["MAX_AMO_NUM"]; i++)
	{
		fish1.emplace_back(new Fish1(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::FISH_1))));
		fish2.emplace_back(new Fish2(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::FISH_2))));
		fish3.emplace_back(new Fish3(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::FISH_3))));
		fish4.emplace_back(new Fish4(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::FISH_4))));
		shark.emplace_back(new Shark(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::BOSS_FISH))));
	}
	this->amo.emplace_back(fish1);
	this->amo.emplace_back(fish2);
	this->amo.emplace_back(fish3);
	this->amo.emplace_back(fish4);
	this->amo.emplace_back(shark);

	for (int i = 0; i < amo.size(); i++)
	{
		useCurrentlyNum.emplace_back(0);
	}

	InitUseCurrentlyNum();
}

/// <summary>
/// デストラクタ
/// </summary>
AmoManager::~AmoManager()
{

}

/// <summary>
/// 更新
/// </summary>
void AmoManager::Update()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& timer = GameTimer::GetInstance();
	auto& weapon = WeaponManager::GetInstance();
	auto& character = CharacterManager::GetInstance();

	int time = timer.GetElapsetTime();

	int weaponNum = 0;
	/*使用するインデックスを決める*/
	if (time % 5 == 0 && timer.GetElapsetFrame() == 0)
	{
		InitUseCurrentlyNum();
		if (character.GetIsShowBoss())
		{
			weaponNum = static_cast<int>(AmoType::SHARK);
		}
		for (int i = 0; i < useCurrentlyNum.size(); i++)
		{
			for (int j = 0; j < useCurrentlyNum[i]; j++)
			{
				if (!amo[i][j]->GetIsHit() && character.GetIsStop(weaponNum) && !amo[i][j]->GetIsRebel())
				{
					amo[i][j]->Init();
					amo[i][j]->SetPos(weapon.GetWeaponPos(weaponNum));
					weaponNum++;
				}
			}
		}
	}

	weaponNum = 0;
	if (character.GetIsShowBoss())
	{
		weaponNum = static_cast<int>(AmoType::SHARK);
	}
	for (int i = 0; i < useCurrentlyNum.size(); i++)
	{
		for (int j = 0; j < useCurrentlyNum[i]; j++)
		{
			if (!amo[i][j]->GetIsHit() && character.GetIsStop(weaponNum) && amo[i][j]->GetIsSet())
			{
				amo[i][j]->Update();
				weaponNum++;
			}
		}
	}
}

/// <summary>
/// ランダムで弾の種類を決める
/// </summary>
const int AmoManager::GetRandomAmoType()const
{
	return GetRand(3);
}

/// <summary>
/// 使用するインデックスの初期化
/// </summary>
void AmoManager::InitUseCurrentlyNum()
{
	auto& character = CharacterManager::GetInstance();
	//インデックスの初期化
	for (int i = 0; i < this->useCurrentlyNum.size(); i++)
	{
		this->useCurrentlyNum[i] = 0;
	}

	//もしもしボスが出ていたら
	if (character.GetIsShowBoss())
	{
		this->useCurrentlyNum[static_cast<int>(AmoType::SHARK)]++;
	}
	else
	{
		//現在稼働している敵の数だけ弾のインデックスを用意する
		for (int i = 0; i < character.GetNowMoveEnemyNum(); i++)
		{
			this->useCurrentlyNum[GetRandomAmoType()]++;
		}
	}
}