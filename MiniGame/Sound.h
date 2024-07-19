//===================================
// @brief サウンドクラス
//===================================
#pragma once
#include <cassert>

class Sound
{
public:
	virtual ~Sound();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new Sound();
	}

	/*インスタンスの取得*/
	static Sound& GetInstance()
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

private:
	/*内部処理関数*/
	Sound();
	/*メンバ変数*/
	static Sound* instance;
};

