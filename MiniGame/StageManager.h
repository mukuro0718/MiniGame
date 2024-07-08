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
	void		Init	();		//初期化
	void		Update	();		//更新
	const void	Draw	()const;//描画
private:
	/*列挙体*/
	enum class BuildingType
	{
		A = 0,
		B = 1,
		C = 2,
		D = 3,
		E = 4,
		F = 5,
		G = 6,
		H = 7,
	};

	/*内部処理関数*/
	StageManager();				//コンストラクタ
	void CreateRoad();			//道の作成
	void CreateBuilding();		//建物の作成
	void CreateBase();			//建物のベースの作成
	void SetMoveBuildingType();	//移動する建物の設定

	/*メンバ変数*/
	static StageManager*	instance;	//唯一のインスタンス
	vector<GameStage*>		frontRoad;	//前の道
	vector<GameStage*>		backRoad;	//後ろの道
	vector<GameStage*>		frontBase;	//前の道
	vector<GameStage*>		backBase;	//後ろの道
	Skydome*				skydome;	//スカイドーム
	vector<Building*>		building;	//建物
};

