#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Explosion::Explosion()
	: pos(0.0f)
	, imageSize(0)
	, nowDrawImage(0)
{
	/*シングルトンクラスのインスタンスを取得*/
	auto& asset = LoadingAsset::GetInstance();
	auto& json = JsonManager::GetInstance();
	int     jsonIndex = json.GetFileNameType(JsonManager::FileNameType::EFFECT);

	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_01)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_02)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_03)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_04)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_05)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_06)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_07)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_08)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_09)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_10)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_11)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_12)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_13)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_14)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_15)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_16)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_17)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_18)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_19)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_20)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_21)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_22)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_23)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_24)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_25)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_26)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_27)));
	this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_28)));

	imageSize = json.GetJson(jsonIndex)["EXPLOSION_IMAGE_SIZE"];
}

/// <summary>
/// デストラクタ
/// </summary>
Explosion::~Explosion()
{

}

/// <summary>
/// 更新
/// </summary>
void Explosion::Update()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& character = CharacterManager::GetInstance();

	if (character.GetPlayerIsHit())
	{
		this->pos = character.GetPlayerPos();

		this->drawFrameCount++;

		if (this->drawFrameCount % 5 == 0 && this->nowDrawImage < this->imageHandle.size() - 1)
		{
			this->nowDrawImage++;
		}
	}
}

/// <summary>
/// 描画
/// </summary>
const void Explosion::Draw()const
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& character = CharacterManager::GetInstance();

	if (character.GetPlayerIsHit())
	{
		DrawBillboard3D(this->pos.value, 0.5f, 0.5f, this->imageSize, 0.0f, this->imageHandle[this->nowDrawImage], TRUE);
	}
}