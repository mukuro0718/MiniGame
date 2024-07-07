#include "Common.h"

UIManager* UIManager::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
UIManager::UIManager()
	:operation(nullptr)
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& asset = LoadingAsset::GetInstance();
	

	operation = new Operation(asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI)));
	bar = new UnderBar();
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
	bar->Update();
}

/// <summary>
/// 描画
/// </summary>
const void UIManager::Draw()const
{
	operation->Draw();
	bar->Draw();
}