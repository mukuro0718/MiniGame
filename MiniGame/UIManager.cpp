#include "Common.h"

UIManager* UIManager::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
UIManager::UIManager()
	:price(nullptr)
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& asset = LoadingAsset::GetInstance();
	

	price = new Price(asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI)));
}

/// <summary>
/// デストラクタ
/// </summary>
UIManager::~UIManager()
{

}

/// <summary>
/// 更新
/// </summary>
void UIManager::Update()
{
	price->Update();
}