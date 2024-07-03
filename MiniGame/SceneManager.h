//=======================================
// @brief シーンマネージャークラス
// シーンの管理を行う
//=======================================
#pragma once
#include <cassert>

class SceneBase;
class FPSController;
class LoadScene;
class SceneManager final
{
public:
	virtual ~SceneManager();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new SceneManager();
	}

	/*インスタンスの取得*/
	static SceneManager& GetInstance()
	{
		//インスタンスがnullだったら例外を発生させる
		assert(instance != nullptr);
		return *instance;
	}

	/*インスタンスの削除*/
	static void DeleteInstance()
	{
		//もしインスタンスがnullじゃなかったら
		if (instance != nullptr)
		{
			//インスタンスを開放し、nullを代入する
			delete(instance);
			instance = nullptr;
		}
	}

	void Update();//更新
private:
	/*内部処理関数*/
	SceneManager();//コンストラクタ
	void SceneChange();//シーンの変更

	/*メンバ変数*/
	static SceneManager* instance;//唯一のインスタンス
	SceneBase*		scene;//シーンインスタンス
	FPSController*  fps;//fpsコントローラー
	LoadScene*		load;
};

