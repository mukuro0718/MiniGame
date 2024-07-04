#include "Common.h"

GemManager* GemManager::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
GemManager::GemManager()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& asset = LoadingAsset::GetInstance();
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::STAGE);

	/*�C���X�^���X�̍쐬*/
	//gem.emplace_back(new Gem(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::GEM_1)),0));
	gem.emplace_back(new Gem(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::GEM_2)),0));
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
GemManager::~GemManager()
{

}

/// <summary>
/// �X�V
/// </summary>
void GemManager::Update()
{
	for (int i = 0; i < gem.size(); i++)
	{
		gem[i]->Update();
	}
}

