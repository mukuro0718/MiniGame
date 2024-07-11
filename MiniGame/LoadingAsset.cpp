#include "Common.h"

LoadingAsset* LoadingAsset::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
LoadingAsset::LoadingAsset()
{
	/*json読み込みクラスのインスタンスを取得*/
	auto& json = JsonManager::GetInstance();
	/*json内のパスを取得する*/
	vector<string> modelPath = json.GetJson(static_cast<int>(JsonManager::FileNameType::MODEL_PATH))["PATH"];
	vector<string> imagePath = json.GetJson(static_cast<int>(JsonManager::FileNameType::IMAGE_PATH))["PATH"];
	/*モデルのロード*/
	for (int i = 0; i < modelPath.size(); i++)
	{
		this->modelHandle.emplace_back(MV1LoadModel(modelPath[i].c_str()));
	}

	/*画像のロード*/
	for (int i = 0; i < imagePath.size(); i++)
	{
		this->imageHandle.emplace_back(LoadGraph(imagePath[i].c_str()));
	}
	/*フォントのロード*/
	AddFontResourceEx("Data/Font/ThaleahFat.ttf", FR_PRIVATE, NULL);
	AddFontResourceEx("Data/Font/gomarice_mukasi_mukasi.ttf", FR_PRIVATE, NULL);
	this->fontHandle.emplace_back(CreateFontToHandle("昔々ふぉんと", 64, 64, DX_FONTTYPE_EDGE, DX_CHARSET_DEFAULT,4));
	this->fontHandle.emplace_back(CreateFontToHandle("昔々ふぉんと", 256, 64, DX_FONTTYPE_EDGE, DX_CHARSET_DEFAULT, 4));
	this->fontHandle.emplace_back(CreateFontToHandle("昔々ふぉんと", 128, 64, DX_FONTTYPE_EDGE, DX_CHARSET_DEFAULT, 4));
	this->fontHandle.emplace_back(CreateFontToHandle("ThaleahFat", 128, 64, DX_FONTTYPE_EDGE, DX_CHARSET_DEFAULT, 4));
}

/// <summary>
/// デストラクタ
/// </summary>
LoadingAsset::~LoadingAsset()
{
	/*モデルの削除*/
	for (int i = 0; i < this->modelHandle.size(); i++)
	{
		MV1DeleteModel(this->modelHandle[i]);
	}

	/*画像の削除*/
	for (int i = 0; i < this->imageHandle.size(); i++)
	{
		DeleteGraph(this->imageHandle[i]);
	}

	/*フォントの削除*/
	for (int i = 0; i < fontHandle.size(); i++)
	{
		DeleteFontToHandle(this->fontHandle[i]);
	}
	RemoveFontResourceEx("Data/Font/gomarice_mukasi_mukasi.ttf", FR_PRIVATE, NULL);
}
