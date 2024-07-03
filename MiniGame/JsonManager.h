//================================================================
// @brief json管理クラス
// JsonLoaderクラスを使用してJsonファイルを読み込み保持する
//================================================================
#pragma once
#include<cassert>

class JsonManager
{
public:
	virtual ~JsonManager();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new JsonManager();
	}

	/*インスタンスの取得*/
	static JsonManager& GetInstance()
	{
		//インスタンスがnullだったら例外を発生させる
		assert(instance != nullptr);
		return *instance;
	}

	/*インスタンスの削除*/
	static void DeleteInstance()
	{
		if (instance != nullptr)
		{
			delete(instance);
			instance = nullptr;
		}
	}

	/*jsonファイルの読み込み*/
	void LoadJsonFile();

	/*ファイルの種類*/
	enum class FileNameType
	{
		STAGE			= 0,	//ステージ
		FONT_PATH		= 1,	//フォント
		FPS_CONTROLLER	= 2,	//FPS
		LOAD_SCENE		= 3,	//ロードシーン
		MODEL_PATH		= 4,	//モデル
		PLAYER			= 5,	//プレイヤー
		SCENE_CHANGER	= 6,	//シーンチェンジャー
		SET_UP_SCREEN	= 7,	//スクリーン設定
		CAMERA			= 8,	//カメラ
		IRON_BAR		= 9,	//鉄棒
		IMAGE_PATH		= 10,	//画像
		SKYDOME			= 11,	//スカイドーム
		TIMER			= 12,	//タイマー
		BACKGROUND		= 13,	//背景
		ENEMY			= 14,	//エネミー
		WEAPON			= 15,	//武器
		AMO				= 16,	//弾
		UI				= 17,	//UI
		GEM				= 18,	//宝石
	};

	/*jsonデータのgetter*/
	const int GetFileNameType(const FileNameType _index)const { return static_cast<int>(_index); }
	const json GetJson(const int _index) { return json[_index]; }
private:
	/*内部処理関数*/
	JsonManager(); //コンストラクタ

	/*メンバ変数*/
	static JsonManager* instance;//唯一のインスタンス
	std::vector<json> json;
	nlohmann::json baseJson;
};

