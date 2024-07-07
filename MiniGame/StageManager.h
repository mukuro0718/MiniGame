//================================================================
// @brief ステージ管理クラス
//================================================================
#pragma once
#include <cassert>

class GameStage;
class Skydome;
class StageManager
{
public:
	virtual ~StageManager();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new StageManager();
	}

	/*インスタンスの取得*/
	static StageManager& GetInstance()
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
private:
	/*内部処理関数*/
	StageManager(); //コンストラクタ

	/*メンバ変数*/
	static StageManager*	instance;	//唯一のインスタンス
	vector<GameStage*>		frontRoad;	//前の道
	vector<GameStage*>		backRoad;	//後ろの道
	Skydome*				skydome;	//スカイドーム
};

