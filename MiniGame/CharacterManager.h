//================================================================
// @brief player管理クラス
//================================================================
#pragma once
#include <cassert>

class GamePlayer;
class Enemy;
class CharacterManager
{
public:
	virtual ~CharacterManager();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new CharacterManager();
	}

	/*インスタンスの取得*/
	static CharacterManager& GetInstance()
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

	void				Init();								//初期化
	void				Update();							//更新
	const WrapVECTOR&	GetPlayerPos()const;				//プレイヤー座標のgetter
	const WrapVECTOR&	GetEnemyPos(const int _index)const;	//エネミー座標のgetter
	const int			GetEnemyNum()const;					//エネミーの数のgetter
	const int			GetNowMoveEnemyNum()const;			//現在移動している敵の数のgetter
	const bool GetIsShowBoss()const;
	const bool GetIsStop(const int _index)const;
private:
	/*内部処理関数*/
	CharacterManager();			//コンストラクタ
	void ChangeNowMoveEnemy();	//稼働しているエネミーの変更

	/*メンバ変数*/
	static CharacterManager*	instance;		//唯一のインスタンス
	GamePlayer*					player;			//ゲームプレイヤー
	vector<Enemy*>				enemy;			//エネミー
	int							nowMoveEnemy;	//現在稼働しているエネミーの数
	bool isShowBoss;//ボス登場フラグ
};

