//================================================================
// @brief エフェクトマネージャークラス
//================================================================
#pragma once
#include <cassert>

class Jet;
class Explosion;
class EffectManager
{
public:
	virtual ~EffectManager();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new EffectManager();
	}

	/*インスタンスの取得*/
	static EffectManager& GetInstance()
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

	void Update();
private:
	/*内部処理関数*/
	EffectManager();	 //コンストラクタ

	/*メンバ変数*/
	static EffectManager*	instance;	//唯一のインスタンス
	Jet*					jet;		//ジェットエフェクト
	Explosion*				explosion;	//爆発エフェクト
};

