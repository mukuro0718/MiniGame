#include "Common.h"

LoadingAsset* LoadingAsset::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
LoadingAsset::LoadingAsset()
{
	/*json�ǂݍ��݃N���X�̃C���X�^���X���擾*/
	auto& json = JsonManager::GetInstance();
	/*json���̃p�X���擾����*/
	vector<string> modelPath = json.GetJson(static_cast<int>(JsonManager::FileNameType::MODEL_PATH))["PATH"];
	vector<string> imagePath = json.GetJson(static_cast<int>(JsonManager::FileNameType::IMAGE_PATH))["PATH"];
	/*���f���̃��[�h*/
	for (int i = 0; i < modelPath.size(); i++)
	{
		this->modelHandle.emplace_back(MV1LoadModel(modelPath[i].c_str()));
	}

	/*�摜�̃��[�h*/
	for (int i = 0; i < imagePath.size(); i++)
	{
		this->imageHandle.emplace_back(LoadGraph(imagePath[i].c_str()));
	}
	/*�t�H���g�̃��[�h*/
	AddFontResourceEx("Data/Font/ThaleahFat.ttf", FR_PRIVATE, NULL);
	AddFontResourceEx("Data/Font/gomarice_mukasi_mukasi.ttf", FR_PRIVATE, NULL);
	this->fontHandle.emplace_back(CreateFontToHandle("�́X�ӂ����", 64, 64, DX_FONTTYPE_EDGE, DX_CHARSET_DEFAULT,4));
	this->fontHandle.emplace_back(CreateFontToHandle("�́X�ӂ����", 256, 64, DX_FONTTYPE_EDGE, DX_CHARSET_DEFAULT, 4));
	this->fontHandle.emplace_back(CreateFontToHandle("�́X�ӂ����", 128, 64, DX_FONTTYPE_EDGE, DX_CHARSET_DEFAULT, 4));
	this->fontHandle.emplace_back(CreateFontToHandle("ThaleahFat", 128, 64, DX_FONTTYPE_EDGE, DX_CHARSET_DEFAULT, 4));
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
LoadingAsset::~LoadingAsset()
{
	/*���f���̍폜*/
	for (int i = 0; i < this->modelHandle.size(); i++)
	{
		MV1DeleteModel(this->modelHandle[i]);
	}

	/*�摜�̍폜*/
	for (int i = 0; i < this->imageHandle.size(); i++)
	{
		DeleteGraph(this->imageHandle[i]);
	}

	/*�t�H���g�̍폜*/
	for (int i = 0; i < fontHandle.size(); i++)
	{
		DeleteFontToHandle(this->fontHandle[i]);
	}
	RemoveFontResourceEx("Data/Font/gomarice_mukasi_mukasi.ttf", FR_PRIVATE, NULL);
}
