//================================================================
// @brief json読み込みクラス
// 指定されたjsonファイルを読み込む
//================================================================
#pragma once
#include<cassert>

// for convenience
using json = nlohmann::json;
class JsonLoader
{
public:
	virtual ~JsonLoader();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new JsonLoader();
	}

	/*インスタンスの取得*/
	static JsonLoader& GetInstance()
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

	/*指定されたJsonファイルを読み込みデータを返す*/
	const json GetJsonData(std::string _jsonName)const;
private:
	/*内部処理関数*/
	JsonLoader(); //コンストラクタ

	/*メンバ変数*/
	static JsonLoader* instance;//唯一のインスタンス
};

