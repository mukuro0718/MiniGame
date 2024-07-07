#include "Common.h"

UIManager* UIManager::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
UIManager::UIManager()
	:operation(nullptr)
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& asset = LoadingAsset::GetInstance();
	

	operation = new Operation(asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI)));
	bar = new UnderBar();
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
	bar->Update();
}

/// <summary>
/// �`��
/// </summary>
const void UIManager::Draw()const
{
	operation->Draw();
	bar->Draw();
}