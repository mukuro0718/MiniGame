#include "Common.h"

WeaponManager* WeaponManager::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
WeaponManager::WeaponManager()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& asset = LoadingAsset::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::ENEMY);
	auto& character = CharacterManager::GetInstance();

	/*インスタンスの作成*/
	for (int i = 0; i < character.GetEnemyNum(); i++)
	{
		if (i != character.GetEnemyNum() - 1)
		{
			this->weapon.emplace_back(new Bazooka(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::BAZOOKA))));
		}
		else
		{
			this->weapon.emplace_back(new Cannon(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::CANNON))));
		}
	}
}

/// <summary>
/// デストラクタ
/// </summary>
WeaponManager::~WeaponManager()
{

}

/// <summary>
/// 更新
/// </summary>
void WeaponManager::Update()
{
	auto& character = CharacterManager::GetInstance();
	for (int i = 0; i < character.GetEnemyNum(); i++)
	{
		weapon[i]->SetPos(character.GetEnemyPos(i));
	}

	for (int i = 0; i < weapon.size(); i++)
	{
		weapon[i]->Update();
	}
}

/// <summary>
/// 描画
/// </summary>
const void WeaponManager::Draw()const
{
	for (int i = 0; i < weapon.size(); i++)
	{
		weapon[i]->Draw();
	}
}
/// <summary>
/// 武器の数のgetter
/// </summary>
const int WeaponManager::GetWeaponNum()const
{
	return this->weapon.size();
}

/// <summary>
/// 武器の座標のgetter
/// </summary>
const WrapVECTOR& WeaponManager::GetWeaponPos(const int _index)const
{
	return this->weapon[_index]->GetTransform().pos;
}
