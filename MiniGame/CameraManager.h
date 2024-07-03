//================================================================
// @brief camera管理クラス
//================================================================
#pragma once
#include <cassert>

class GameCamera;
class CameraManager
{
public:
	virtual ~CameraManager();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new CameraManager();
	}

	/*インスタンスの取得*/
	static CameraManager& GetInstance()
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
	CameraManager(); //コンストラクタ

	/*メンバ変数*/
	static CameraManager*	instance;	//唯一のインスタンス
	GameCamera*				camera;		//ゲームカメラ
};

