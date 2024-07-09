//========================================================
// @brief カニクラス
// ロケーションが海の時の敵
//========================================================
#pragma once
#include "Enemy.h"

class WrapVECTOR;
class Normal : public Enemy
{
public:
	Normal(const int _modelHandle, const int _breakModelHandle, const vector<float> _movePos);	//コンストラクタ
	~Normal();														//デストラクタ

	void Init()				override;//初期化
	void Update()			override;//更新
	void ChangeFlagsState()	;//フラグの状態を変更

private:
	/*列挙体*/
	//状態の種類
	enum class StateType
	{
		MOVE	= 0,//移動
		ATTACK1	= 1,//攻撃
		DEATH	= 2,//死亡
	};

	/*メンバ変数*/
	float velocity;	//移動速度
	StateType state;//状態
};

