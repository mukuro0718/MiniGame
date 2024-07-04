//===============================================
// @brief 当たり判定クラス
// カプセルとカプセル
// の当たり判定を実装する
// このクラスは値を保持せず、
// 結果のみを返す関数を実装する
//===============================================
#pragma once
#include <cassert>

class Object;
class HitResult;
class Collision final
{
public:
	virtual ~Collision();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new Collision();
	}

	/*インスタンスの取得*/
	static Collision& GetInstance()
	{
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

	/*球と球の当たり判定*/
	HitResult* SphereAndSphereCollision(const Object& _in1,const Object& _in2);
private:
	/*内部処理関数*/
	Collision(); //コンストラクタ

	/*メンバ変数*/
	static Collision* instance;//唯一のインスタンス
};

