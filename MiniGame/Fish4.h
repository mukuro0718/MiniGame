//==============================================
// @brief さかな４クラス
//==============================================
#pragma once
#include "Amo.h"

class Fish4 : public Amo
{
public:
	Fish4(const int _modelHandle);	//コンストラクタ
	virtual ~Fish4();				//デストラクタ

	void Init()		override;//初期化
	void Update()	override;//更新
	void Move()		override;//移動
protected:
};

