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
	

	this->operation = new Operation(asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI)),asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::BUTTON)), asset.GetModel(asset.GetModelType(LoadingAsset::ModelType::BOSS_FISH)));
	this->bar		= new UnderBar();
	this->score		= new Score(asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI)), asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI)), asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::MONEY_BAG)));
}

/// <summary>
/// �f�X�g���N�^
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
/// �X�V
/// </summary>
void UIManager::Init()
{
	this->bar->Init();
	this->operation->Init();
}

/// <summary>
/// �X�V
/// </summary>
void UIManager::Update()
{
	this->bar->Update();
	this->operation->Update();
}

/// <summary>
/// �`��
/// </summary>
const void UIManager::Draw()const
{
	this->score->Draw();
	this->operation->Draw();
	this->bar->Draw();
}