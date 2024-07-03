#include "Common.h"

UIManager* UIManager::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
UIManager::UIManager()
	:price(nullptr)
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& asset = LoadingAsset::GetInstance();
	

	price = new Price(asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI)));
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
UIManager::~UIManager()
{

}

/// <summary>
/// �X�V
/// </summary>
void UIManager::Update()
{
	price->Update();
}