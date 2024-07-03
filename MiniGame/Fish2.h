//==============================================
// @brief さかな2クラス
//==============================================
#pragma once
#include "Amo.h"

class Fish2 : public Amo
{
public:
	Fish2(const int _modelHandle);	//コンストラクタ
	virtual ~Fish2();				//デストラクタ

	void Init()		override;//初期化
	void Update()	override;//更新
	void Move()		override;//移動
protected:
};

