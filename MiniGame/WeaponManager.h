//================================================================
// @brief 武器管理クラス
//================================================================
#pragma once
#include <cassert>

class Weapon;
class WeaponManager
{
public:
	virtual ~WeaponManager();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new WeaponManager();
	}

	/*インスタンスの取得*/
	static WeaponManager& GetInstance()
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
	const void Draw()const;//描画

	const int GetWeaponNum()const;
	const WrapVECTOR& GetWeaponPos(const int _index)const;

private:
	/*内部処理関数*/
	WeaponManager(); //コンストラクタ

	/*メンバ変数*/
	static WeaponManager*	instance;	//唯一のインスタンス
	vector<Weapon*>			weapon;		//エネミー
};


