#include "Common.h"

GemManager* GemManager::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
GemManager::GemManager()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& asset = LoadingAsset::GetInstance();
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::STAGE);

	/*インスタンスの作成*/
	//gem.emplace_back(new Gem(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::GEM_1)),0));
	gem.emplace_back(new Gem(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::GEM_2)),0));
}

/// <summary>
/// デストラクタ
/// </summary>
GemManager::~GemManager()
{

}

/// <summary>
/// 更新
/// </summary>
void GemManager::Update()
{
	for (int i = 0; i < gem.size(); i++)
	{
		gem[i]->Update();
	}
}

