//==============================================
// @brief プレイヤークラス
// キャラクターベースクラスを継承し、
// 純粋仮想関数に実態を持たせる。
// また、プレイヤー独自のメソッドや変数を保持し、
// のちに作るCharacterManagerクラスで管理される。
// コリジョン情報はCollisionクラスで作るため、
// ここではコリジョン情報の保持は行わない
//==============================================
#pragma once
#include "Character.h"

class GamePlayer : public Character
{
public:
	GamePlayer(const int _modelHandle);	//コンストラクタ
	~GamePlayer();						//デストラクタ

	/*継承もとの純粋仮想関数に実態を持たせる*/
	void Init()				override;//初期化
	void Update()			override;//更新
	void FixMoveVec()		;//移動ベクトルの補正
	void Move()				;//移動
	void ChangeFlagsState()	;//フラグの状態を変更

	void CountTime();//時間の計測
	
	/*getter*/
	bool	GetIsStan()		const { return this->isStun; }		//気絶フラグのgetter
	float	GetHeight()		const { return this->height; }		//高さのgetter
	int		GetAliveTime()	const { return this->aliveTime; }	//生存時間のgetter

	/*フラグを立てる*/
	const void OnIsStun() { isStun = true; }//気絶フラグを立てる
private:
	/*構造体・列挙体*/
	//アニメーションの種類
	enum class AnimType
	{
		SIT,
		IDLE,
		JUMP,
	};

	/*内部処理関数*/
	void AddAnim();		//アニメーションの追加
	void ChangeAnim();	//アニメーションの変更

	/*メンバ変数*/
	float jumpPower;	//ジャンプ力
	float height;		//身長
	float floatPower;	//浮力
	float zAngle;		//Z軸をもとにしたアングル
	
	bool isSit;
	bool isStun;		//気絶したか
	bool isOnGround;	//地面にいるか
	bool isJump;		//ジャンプしているか（敵がプレイヤーを発見したときに、ジャンプするためのもの）

	int countStartTime;	//計測開始時間
	int aliveTime;		//生存時間
	int stunFrameCount;	//気絶を解除するまでのフレーム数
};

