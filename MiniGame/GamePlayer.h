//==============================================
// @brief プレイヤークラス
// キャラクターベースクラスを継承し、
// 純粋仮想関数に実態を持たせる。
// また、プレイヤー独自のメソッドや変数を保持し、
// のちに作るCharacterManagerクラスで管理される。
//==============================================
#pragma once
#include "Character.h"

class GamePlayer : public Character
{
public:
	GamePlayer(const int _modelHandle,const int _breakModelHandle);	//コンストラクタ
	~GamePlayer();						//デストラクタ

	/*継承もとの純粋仮想関数に実態を持たせる*/
	void Init()				override;//初期化
	void Update()			override;//更新
	void HitCheck()			;//当たり判定
	void Move()				;//移動
	void ChangeFlagsState()	;//フラグの状態を変更

	void CountTime();//時間の計測
	
	/*getter*/
	const bool	GetIsStan	()const { return this->isStun;	 }//気絶フラグのgetter
	const float	GetHeight	()const { return this->height;	 }//高さのgetter
	const int	GetAliveTime()const { return this->aliveTime;}//生存時間のgetter
	const bool	GetIsHit	()const { return this->isHit;	 }//当たり判定フラグのgetter
	const bool	GetIsStop	()const { return this->isStop;	 }
	/*フラグを立てる*/
	const void OnIsStun() { this->isStun = true; }//気絶フラグを立てる
	const int GetPrice()const { return this->price; }
private:
	/*構造体・列挙体*/
	//アニメーションの種類
	enum class AnimType
	{
		SIT,
		IDLE,
		JUMP,
	};

	/*メンバ変数*/
	float jumpPower;		//ジャンプ力
	float height;			//身長
	float floatPower;		//浮力
	float zAngle;			//Z軸をもとにしたアングル
	
	bool isStun;			//気絶したか
	bool isOnGround;		//地面にいるか
	bool isHit;				//弾や地面に当たったか
	bool isStop;			//停止フラグ（ボタン入力があったらfalseにする）

	int countStartTime;		//計測開始時間
	int stunFrameCount;		//気絶を解除するまでのフレーム数
	int normalModelHandle;	
	int breakModelHandle;	//壊れたモデルハンドル
	int aliveTime;			//生存時間
	int price;				//宝石の合計金額
};

