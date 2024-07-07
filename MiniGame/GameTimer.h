//======================================================
// @brief タイマークラス
// 現実の時間ではなく、６０フレームが立った時点で１秒とする
//======================================================
#pragma once
#include <cassert>
class GameTimer
{
public:
	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new GameTimer();
	}
	
	/*インスタンスの取得*/
	static GameTimer& GetInstance()
	{
		assert(instance != nullptr);
		return *instance;
	}

	/*インスタンスの解放*/
	static void DeleteInstance()
	{
		if (instance != nullptr)
		{
			delete(instance);
			instance = nullptr;
		}
	}

	/*その他関数*/
	virtual ~GameTimer();	//デストラクタ
	void	Update();		//更新
	void	Init();			//初期化
	const void Draw()const;	//描画

	/*getter*/
	const int GetElapsetTime	()const { return this->elapsetTime; }
	const int GetElapsetFrame	()const { return this->elapsetFrame; }
private:
	/*内部処理関数*/
	GameTimer();	//コンストラクタ

	/*メンバ変数*/
	static GameTimer* instance;//唯一のインスタンス
	int elapsetTime;//経過時間
	int elapsetFrame;//経過フレーム
};

