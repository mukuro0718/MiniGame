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
	

	this->operation = new Operation(asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI)));
	this->bar = new UnderBar();
}

/// <summary>
/// デストラクタ
/// </summary>
UIManager::~UIManager()
{
	if (this->bar != nullptr)
	{
		delete(this->bar);
		this->bar = nullptr;
	}
	if (this->operation != nullptr)
	{
		delete(this->operation);
		this->operation = nullptr;
	}
}

/// <summary>
/// 更新
/// </summary>
void UIManager::Init()
{
	this->bar->Init();
	this->operation->Init();
}

/// <summary>
/// 更新
/// </summary>
void UIManager::Update()
{
	this->bar->Update();
}

/// <summary>
/// 描画
/// </summary>
const void UIManager::Draw()const
{
	this->operation->Draw();
	this->bar->Draw();
}