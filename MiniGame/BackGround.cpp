#include "Common.h"

BackGround* BackGround::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
BackGround::BackGround()
	: alpha(MAX_ALPHA)
	, isEraseImage(false)
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto&	asset		= LoadingAsset::GetInstance();
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::BACKGROUND);
	
	/*�摜�n���h���̎擾*/
	this->imageHandle.emplace_back(asset.GetImage(static_cast<int>(LoadingAsset::ImageType::TITLE_IMAGE)));
	this->imageHandle.emplace_back(asset.GetImage(static_cast<int>(LoadingAsset::ImageType::CLOUD)));
	Vec2d pos;
	Vec2d size;
	float velocity = 0.0f;
	for (int i = 0; i < json.GetJson(jsonIndex)["MAX_CLOUD_NUM"]; i++)
	{
		pos.x = GetRandom(json.GetJson(jsonIndex)["CLOUD_INIT_X"], false,0);
		pos.y = GetRandom(json.GetJson(jsonIndex)["CLOUD_Y_RANGE"], false, 0);
		velocity = GetRandom(json.GetJson(jsonIndex)["CLOUD_MAX_VELOCITY"], false, json.GetJson(jsonIndex)["CLOUD_MAX_VELOCITY"]);
		size.x = GetRandom(json.GetJson(jsonIndex)["CLOUD_MAX_WIDTH_SIZE"], false, json.GetJson(jsonIndex)["CLOUD_MAX_WIDTH_SIZE_OFFSET"]);
		size.y = GetRandom(json.GetJson(jsonIndex)["CLOUD_MAX_HEIGHT_SIZE"], false, json.GetJson(jsonIndex)["CLOUD_MAX_HEIGHT_SIZE_OFFSET"]);

		this->cloudPos.emplace_back(pos);
		this->cloudSize.emplace_back(size);
		this->cloudVelocity.emplace_back(velocity);
	}
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
BackGround::~BackGround()
{
	this->cloudPos		.clear();
	this->cloudSize		.clear();
	this->cloudVelocity	.clear();
}

/// <summary>
/// ������
/// </summary>
void BackGround::Init()
{
	this->alpha			= this->MAX_ALPHA;
	this->isEraseImage	= false;
	
}

/// <summary>
/// �X�V
/// </summary>
void BackGround::Update()
{
	/*�ړ�*/
	Move();

	/*�A���t�@�l�̍X�V*/
	UpdateAlpha();
}

/// <summary>
/// �ړ�
/// </summary>
void BackGround::Move()
{
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::BACKGROUND);

	for (int i = 0; i < this->cloudPos.size(); i++)
	{
		this->cloudPos[i].x -= this->cloudVelocity[i];
		if (this->cloudPos[i].x <= json.GetJson(jsonIndex)["CLOUD_END_X"])
		{
			ChangeCloudInfo(i);
		}
	}
}

/// <summary>
/// �w�i�̕ύX
/// </summary>
void BackGround::ChangeCloudInfo(const int _index)
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::BACKGROUND);

	this->cloudPos[_index].x	= GetRandom(json.GetJson(jsonIndex)["CLOUD_X_RANGE"]				, false, json.GetJson(jsonIndex)["CLOUD_INIT_X"]);
	this->cloudPos[_index].y	= GetRandom(json.GetJson(jsonIndex)["CLOUD_Y_RANGE"]				, false, 0);
	this->cloudVelocity[_index]	= GetRandom(json.GetJson(jsonIndex)["CLOUD_MAX_VELOCITY"]	, false, json.GetJson(jsonIndex)["CLOUD_MAX_VELOCITY"]);
	this->cloudSize[_index].x	= GetRandom(json.GetJson(jsonIndex)["CLOUD_MAX_WIDTH_SIZE"]	, false, json.GetJson(jsonIndex)["CLOUD_MAX_WIDTH_SIZE_OFFSET"]);
	this->cloudSize[_index].y	= GetRandom(json.GetJson(jsonIndex)["CLOUD_MAX_HEIGHT_SIZE"]	, false, json.GetJson(jsonIndex)["CLOUD_MAX_HEIGHT_SIZE_OFFSET"]);
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
	DrawBox(0, 0, 1920, 1080, GetColor(24, 235, 249), TRUE);
	for (int i = 0; i < this->cloudPos.size(); i++)
	{
		DrawExtendGraph(this->cloudPos[i].x, this->cloudPos[i].y, this->cloudPos[i].x + this->cloudSize[i].x, this->cloudPos[i].y + this->cloudSize[i].y, this->imageHandle[static_cast<int>(ImageType::CLOUD)], TRUE);
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->MAX_ALPHA);
}

/// <summary>
/// �����_���l�̎擾
/// </summary>
/// <param name="_range"></param>
/// <param name="_isSign"></param>
int BackGround::GetRandom(const int _range, const bool _isSign, const int _offset)
{
	int out = GetRand(_range);

	if (_isSign && GetRand(1) == 1)
	{
		return out * -1;
	}
	return out + _offset;
}