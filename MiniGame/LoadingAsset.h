//================================================================
// @brief アセットのロードクラス
//================================================================
#pragma once
#include <cassert>

class LoadingAsset
{
public:
	virtual ~LoadingAsset();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new LoadingAsset();
	}

	/*インスタンスの取得*/
	static LoadingAsset& GetInstance()
	{
		//インスタンスがnullの時、例外を発生させる
		assert(instance != nullptr);
		return *instance;
	}

	/*インスタンスの削除*/
	static void DeleteInstance()
	{
		//もしインスタンスがnullじゃなかったら
		if (instance != nullptr)
		{
			//インスタンスを開放し、nullで初期化する
			delete(instance);
			instance = nullptr;
		}
	}


	/*モデルの種類*/
	enum class ModelType
	{
		CAR			= 0,
		CAR_BREAK	= 1,
		BAZOOKA		= 2,
		CANNON		= 3,
		BLUE_CAR	= 4,
		GRY_CAR		= 5,
		GREEN_CAR	= 6,
		RED_CAR		= 7,
		POLICE_CAR	= 8,
		FISH_1		= 9,
		FISH_2		= 10,
		FISH_3		= 11,
		FISH_4		= 12,
		BOSS_FISH	= 13,
		SKYDOME		= 14,
		ROAD		= 15,
		GEM_1		= 16,
		GEM_2		= 17,
	};

	/*画像の種類*/
	enum class ImageType
	{
		BACKGROUND_1	= 0,
		BACKGROUND_2	= 1,
		BACKGROUND_3	= 2,
		BACKGROUND_4	= 3,
		BACKGROUND_5	= 4,
		BACKGROUND_6	= 5,
		BACKGROUND_7	= 6,
		BACKGROUND_8	= 7,
		BACKGROUND_9	= 8,
		BACKGROUND_10	= 9,
		BACKGROUND_11	= 10,
		BACKGROUND_12	= 11,
		BACKGROUND_13	= 12,
		CAR				= 13,
		HOUSE			= 14,
		NOW_BAR			= 15,
		PREV_BAR		= 16,
		JET_FLAME		= 17,
		JET_FLASH		= 18,
		JET_SMOKE		= 19,
	};

	enum class FontType
	{
		MUKASI	= 0,
	};
	/*モデルのgetter*/
	const int GetModel(const int _index) { return modelHandle[_index]; }
	const int GetModelType(const ModelType _index) { return static_cast<int>(_index); }

	/*画像のgetter*/
	const int GetImage(const int _index) { return imageHandle[_index]; }
	const int GetImageType(const ImageType _index) { return static_cast<int>(_index); }

	/*フォントのgetter*/
	const int GetFont(const int _index) { return fontHandle[_index]; }
	const int GetFontType(const FontType _index) { return static_cast<int>(_index); }
private:
	/*内部処理関数*/
	LoadingAsset();	 //コンストラクタ

	/*メンバ変数*/
	static LoadingAsset* instance;//唯一のインスタンス

	vector<int> modelHandle;//モデルハンドル
	vector<int> imageHandle;//画像ハンドル
	vector<int>	fontHandle; //フォントハンドル
};

