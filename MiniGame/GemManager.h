//================================================================
// @brief 宝石管理クラス
//================================================================
#pragma once
#include <cassert>

class Gem;
class GemManager
{
public:
	virtual ~GemManager();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new GemManager();
	}

	/*インスタンスの取得*/
	static GemManager& GetInstance()
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

	void Update();//更新
private:
	/*内部処理関数*/
	GemManager(); //コンストラクタ

	/*メンバ変数*/
	static GemManager*	instance;	//唯一のインスタンス
	vector<Gem*>		gem;		//宝石
};


