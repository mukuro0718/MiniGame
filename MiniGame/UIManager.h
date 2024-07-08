//================================================================
// @brief UI管理クラス
//================================================================
#pragma once
#include<cassert>

class Operation;
class UnderBar;
class UIManager
{
public:
	virtual ~UIManager();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new UIManager();
	}

	/*インスタンスの取得*/
	static UIManager& GetInstance()
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
	void		Init	();		//初期化
	void		Update	();		//更新
	const void	Draw	()const;//描画
private:
	/*内部処理関数*/
	UIManager(); //コンストラクタ

	/*メンバ変数*/
	static UIManager* instance;//唯一のインスタンス
	Operation* operation;//値段UI
	UnderBar* bar;//バーUI
};

