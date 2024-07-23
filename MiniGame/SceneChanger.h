//===============================================
// @brief シーンチェンジャークラス
// シーンタイプの変更関数を実装
// シーンのタイプを保持
// シングルトンで実装
//===============================================
#pragma once
#include <cassert>

class SceneChanger final
{
public:
	virtual ~SceneChanger();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance() 
	{
		instance = new SceneChanger();
	}
	/*インスタンスの取得*/
	static SceneChanger& GetInstance()
	{
		//インスタンスがnullだった時、例外を発生させる)
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
	//シーンタイプ
	enum class SceneType :int
	{
		TITLE    = 0,//タイトル
		GAME	 = 1,//ゲーム
		RESULT   = 2,//リザルト
		TUTORIAL = 3,
	};

	//シーンの同期
	const void SynchroScene();
	const void ChangeScene(const SceneType _nextScene);
	/*getter*/
	const SceneType GetNowSceneType()const { return this->nowScene; }		//現在のシーンタイプのgetter
	const SceneType GetNextSceneType()const { return this->nextSceneType; } //次のシーンタイプのgetter
private:
	/*内部処理関数*/
	SceneChanger();//コンストラクタ

	/*メンバ変数*/
	static SceneChanger* instance;//唯一のインスタンス
	SceneType nowScene;
	SceneType nextSceneType;
};

