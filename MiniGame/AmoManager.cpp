#include "Common.h"

AmoManager* AmoManager::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
AmoManager::AmoManager()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& asset = LoadingAsset::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::AMO);
	auto& character = CharacterManager::GetInstance();

	vector<Amo*> fish1;
	vector<Amo*> fish2;
	vector<Amo*> fish3;
	vector<Amo*> fish4;
	vector<Amo*> shark;
	/*�C���X�^���X�̍쐬*/
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
/// �f�X�g���N�^
/// </summary>
AmoManager::~AmoManager()
{

}

/// <summary>
/// �X�V
/// </summary>
void AmoManager::Update()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& timer = GameTimer::GetInstance();
	auto& weapon = WeaponManager::GetInstance();
	auto& character = CharacterManager::GetInstance();

	int time = timer.GetElapsetTime();

	int weaponNum = 0;
	/*�g�p����C���f�b�N�X�����߂�*/
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
/// �����_���Œe�̎�ނ����߂�
/// </summary>
const int AmoManager::GetRandomAmoType()const
{
	return GetRand(3);
}

/// <summary>
/// �g�p����C���f�b�N�X�̏�����
/// </summary>
void AmoManager::InitUseCurrentlyNum()
{
	auto& character = CharacterManager::GetInstance();
	//�C���f�b�N�X�̏�����
	for (int i = 0; i < this->useCurrentlyNum.size(); i++)
	{
		this->useCurrentlyNum[i] = 0;
	}

	//���������{�X���o�Ă�����
	if (character.GetIsShowBoss())
	{
		this->useCurrentlyNum[static_cast<int>(AmoType::SHARK)]++;
	}
	else
	{
		//���݉ғ����Ă���G�̐������e�̃C���f�b�N�X��p�ӂ���
		for (int i = 0; i < character.GetNowMoveEnemyNum(); i++)
		{
			this->useCurrentlyNum[GetRandomAmoType()]++;
		}
	}
}