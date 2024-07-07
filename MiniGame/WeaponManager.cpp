#include "Common.h"

WeaponManager* WeaponManager::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
WeaponManager::WeaponManager()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& asset = LoadingAsset::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::ENEMY);
	auto& character = CharacterManager::GetInstance();

	/*�C���X�^���X�̍쐬*/
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
/// �f�X�g���N�^
/// </summary>
WeaponManager::~WeaponManager()
{

}

/// <summary>
/// �X�V
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
/// �`��
/// </summary>
const void WeaponManager::Draw()const
{
	for (int i = 0; i < weapon.size(); i++)
	{
		weapon[i]->Draw();
	}
}
/// <summary>
/// ����̐���getter
/// </summary>
const int WeaponManager::GetWeaponNum()const
{
	return this->weapon.size();
}

/// <summary>
/// ����̍��W��getter
/// </summary>
const WrapVECTOR& WeaponManager::GetWeaponPos(const int _index)const
{
	return this->weapon[_index]->GetTransform().pos;
}
