//==============================================
// @brief さかな１クラス
//==============================================
#pragma once
#include "Amo.h"

class Fish1 : public Amo
{
public:
	Fish1(const int _modelHandle);	//コンストラクタ
	virtual ~Fish1();				//デストラクタ

	void Init()		override;//初期化
	void Update()	override;//更新
	void Move()		override;//移動
protected:
};

