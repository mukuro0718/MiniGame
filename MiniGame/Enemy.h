//=====================================================
// @brief エネミークラス
// 各エネミークラスはこのクラスを継承
//=====================================================
#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(const int _modelHandle);	//コンストラクタ
	virtual ~Enemy();				//デストラクタ
	void Move();//移動
	void MoveOffScreen();//画面外へ移動
	const bool GetIsStop()const { return this->isStop; }
protected:
	WrapVECTOR moveTargetPos;//移動目標座標
	bool isStop;//停止したか
	int breakModelHandle;
	int normalModelHandle;
};

