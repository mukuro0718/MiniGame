#include "Common.h"

BackGround* BackGround::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
BackGround::BackGround()
	: imageWidth(0)
	, imageHeight(0)
	, alpha(0)
	, maxAlpha(0)
	, isEraseImage(false)
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& asset = LoadingAsset::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::BACKGROUND);

	imageWidth = json.GetJson(jsonIndex)["IMAGE_WIDTH"];
	imageHeight = json.GetJson(jsonIndex)["IMAGE_HEIGHT"];

	/*�摜�n���h���̎擾*/
	imageHandle.emplace_back(asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BACKGROUND_1)));
	imageHandle.emplace_back(asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BACKGROUND_2)));
	imageHandle.emplace_back(asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BACKGROUND_3)));
	imageHandle.emplace_back(asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BACKGROUND_4)));
	imageHandle.emplace_back(asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BACKGROUND_5)));
	imageHandle.emplace_back(asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BACKGROUND_6)));
	imageHandle.emplace_back(asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BACKGROUND_7)));
	imageHandle.emplace_back(asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BACKGROUND_8)));
	imageHandle.emplace_back(asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BACKGROUND_9)));
	imageHandle.emplace_back(asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BACKGROUND_10)));
	imageHandle.emplace_back(asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BACKGROUND_11)));
	imageHandle.emplace_back(asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BACKGROUND_12)));
	imageHandle.emplace_back(asset.GetImage(static_cast<int>(LoadingAsset::ImageType::BACKGROUND_13)));
	int addVelocity = 0;
	for (int i = 0; i < this->imageHandle.size(); i++)
	{
		this->moveX.emplace_back(0);
		this->velocity.emplace_back(addVelocity);
		addVelocity++;
	}

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
BackGround::~BackGround()
{
	moveX.clear();
	velocity.clear();
	imageHandle.clear();
}

/// <summary>
/// ������
/// </summary>
void BackGround::Init()
{

	this->maxAlpha		= 255;
	this->alpha			= this->maxAlpha;
	this->isEraseImage	= false;
	this->velocity[10]	= this->velocity[9];
	this->alpha			= this->maxAlpha;
	for (int i = 0; i < this->moveX.size(); i++)
	{
		this->moveX[i] = 0;
	}
}

/// <summary>
/// �X�V
/// </summary>
void BackGround::Update()
{
	/*�ړ�*/
	Move();

	/*�`�悷��摜�̕ύX*/
	ChangeBackGround();

	/*�A���t�@�l�̍X�V*/
	UpdateAlpha();
}

/// <summary>
/// �ړ�
/// </summary>
void BackGround::Move()
{
	for (int i = 0; i < this->moveX.size(); i++)
	{
		this->moveX[i] += this->velocity[i];
		if (this->moveX[i] >= this->imageWidth)
		{
			this->moveX[i] = 0;
		}
	}
}

/// <summary>
/// �w�i�̕ύX
/// </summary>
void BackGround::ChangeBackGround()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	auto& timer = GameTimer::GetInstance();

	/*�l�̎擾*/
	//int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::BACKGROUND);
	//int time = timer.GetElapsetTime();
	//int targetTime = json.GetJson(jsonIndex)["OCEAN_TIME"];
	//if (time >= targetTime)
	//{
	//	this->isEraseImage = true;
	//}
}

/// <summary>
/// �A���t�@�l�̕ύX
/// </summary>
void BackGround::UpdateAlpha()
{
	if (this->isEraseImage)
	{
		this->alpha--;
		if (this->alpha < 0)
		{
			this->alpha = 0;
		}
	}
}
/// <summary>
/// �`��
/// </summary>
const void BackGround::Draw()const
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->alpha);
	for (int i = 0; i < this->imageHandle.size(); i++)
	{
		DrawExtendGraph(0 - this->moveX[i]					, 0, this->imageWidth - this->moveX[i]		, this->imageHeight, this->imageHandle[i], TRUE);
		DrawExtendGraph(this->imageWidth - this->moveX[i]	, 0, (this->imageWidth * 2) - this->moveX[i], this->imageHeight, this->imageHandle[i], TRUE);
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->maxAlpha);
}