//=================================================
// @brief 画面の設定クラス
// window/fullScreenの切り替え
// カラービットの設定
// 画面サイズの設定
//=================================================

#pragma once
#include <cassert>

class SetUpScreen
{
public:
	virtual ~SetUpScreen();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new SetUpScreen();
	}

	/*インスタンスの取得*/
	static SetUpScreen& GetInstance()
	{
		assert(instance != nullptr);
		return *instance;
	}

	/*インスタンスの削除*/
	static void DeleteInstance()
	{
		//インスタンスがnullじゃなかったら
		if (instance != nullptr)
		{
			//インスタンスを開放して、null初期化する
			delete(instance);
			instance = nullptr;
		}
	}

	void Init();
private:
	/*内部処理関数*/
	SetUpScreen();

	/*メンバ変数*/
	static SetUpScreen* instance;//唯一のインスタンス
};

