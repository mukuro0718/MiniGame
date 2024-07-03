//================================================================
// @brief 弾管理クラス
//================================================================
#pragma once
#include <cassert>

class Amo;
class AmoManager
{
public:
	virtual ~AmoManager();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new AmoManager();
	}

	/*インスタンスの取得*/
	static AmoManager& GetInstance()
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
	/*列挙体*/
	enum class AmoType
	{
		NONE	= -1,
		FISH1	= 0,
		FISH2	= 1,
		FISH3	= 2,
		FISH4	= 3,
		SHARK	= 4,
	};

	/*内部処理関数*/
	AmoManager(); //コンストラクタ
	const int GetRandomAmoType()const;//弾の種類をランダムで取得
	void InitUseCurrentlyNum();//対応する変数の初期化

	/*メンバ変数*/
	static AmoManager*	instance;	//唯一のインスタンス
	vector<vector<Amo*>>amo;		//弾
	vector<int>			useCurrentlyNum;//今vector内の何番目までが使用されているか
	int					prevTime;//以前の時間
	vector<int>			currentlyAmoPrice;
};


