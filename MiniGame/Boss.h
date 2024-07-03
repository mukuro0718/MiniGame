#pragma once
#include "Enemy.h"

class Boss : public Enemy
{
public:
	Boss(const int _modelHandle, const vector<float> _movePos);	//コンストラクタ
	~Boss();													//デストラクタ

	void Init()				override;//初期化
	void Update()			override;//更新
	void ChangeFlagsState()	;//フラグの状態を変更

private:
	/*列挙体*/
	//状態の種類
	enum class StateType
	{
		MOVE = 0,//移動
		ATTACK = 1,//攻撃
		DEATH = 2,//死亡
	};
	/*静的定数*/

	/*内部処理関数*/
	void UpdateVelocity();	//速度の更新
	float RandomY();	//ジャンプ力の更新

	/*メンバ変数*/
	float velocity;	//移動速度
	StateType state;//状態
};

