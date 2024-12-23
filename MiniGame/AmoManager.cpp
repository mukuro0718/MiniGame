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
		fish1.emplace_back(new Fish1(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::FISH_1)), asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BUBBLE))));
		fish2.emplace_back(new Fish2(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::FISH_2)), asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BUBBLE))));
		fish3.emplace_back(new Fish3(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::FISH_3)), asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BUBBLE))));
		fish4.emplace_back(new Fish4(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::FISH_4)), asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BUBBLE))));
		shark.emplace_back(new Shark(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::BOSS_FISH)), asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BUBBLE))));
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
	for (int i = 0; i < amo.size(); i++)
	{
		for (int j = 0; j < amo[i].size(); j++)
		{
			if (amo[i][j] != nullptr)
			{
				delete(amo[i][j]);
				amo[i][j] = nullptr;
			}
		}
		amo[i].clear();
	}
	amo.clear();
}

/// <summary>
/// 初期化
/// </summary>
void AmoManager::Init()
{
	for (int i = 0; i < amo.size(); i++)
	{
		for (int j = 0; j < amo[i].size(); j++)
		{
			amo[i][j]->Init();
		}
	}
	for (int i = 0; i < this->useCurrentlyNum.size(); i++)
	{
		this->useCurrentlyNum[i] = 0;
	}
	prevTime = 0;

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
	auto& sound = Sound::GetInstance();
	int time = timer.GetElapsetTime();

	int weaponNum = 0;
	int priceNum = 0;
	/*使用するインデックスを決める*/
	if (time % 5 == 0 && timer.GetElapsetFrame() == 0)
	{
		InitUseCurrentlyNum();
		if (character.GetIsShowBoss())
		{
			weaponNum = static_cast<int>(AmoType::SHARK);
		}
		for (int i = 0; i < this->useCurrentlyNum.size(); i++)
		{
			for (int j = 0; j < this->useCurrentlyNum[i]; j++)
			{
				if (!this->amo[i][j]->GetIsHit() && character.GetIsStop(weaponNum) && !this->amo[i][j]->GetIsRebel())
				{
					this->amo[i][j]->Init();
					this->amo[i][j]->SetPos(weapon.GetWeaponPos(weaponNum));
					priceNum++;
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
			if (character.GetIsStop(weaponNum) && amo[i][j]->GetIsSet())
			{
				amo[i][j]->Update();
				weaponNum++;
			}
		}
	}

	sound.PlayBossShotSound();
	sound.PlayNormalShotSound();
}

/// <summary>
/// 更新
/// </summary>
const void AmoManager::Draw()const
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& character = CharacterManager::GetInstance();
	int weaponNum = 0;
	for (int i = 0; i < useCurrentlyNum.size(); i++)
	{
		for (int j = 0; j < useCurrentlyNum[i]; j++)
		{
			if (character.GetIsStop(weaponNum) && amo[i][j]->GetIsSet())
			{
				amo[i][j]->Draw();
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
	if (!character.GetIsShowBoss())
	{
		for (int i = 0; i < useCurrentlyNum.size(); i++)
		{
			for (int j = 0; j < useCurrentlyNum[i]; j++)
			{
				amo[i][j]->Init();
			}
		}
	}
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

const int AmoManager::GetAmoTypeNum()const
{
	return static_cast<int>(this->amo.size());
}

const vector<int> AmoManager::GetNowUseNum()const
{
	return this->useCurrentlyNum;
}
const Amo& AmoManager::GetAmoInstance(const int _type,const int _use)const
{
	return *this->amo[_type][_use];
}
