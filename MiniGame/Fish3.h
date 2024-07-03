//==============================================
// @brief さかな３クラス
//==============================================
#pragma once
#include "Amo.h"

class Fish3 : public Amo
{
public:
	Fish3(const int _modelHandle);	//コンストラクタ
	virtual ~Fish3();				//デストラクタ

	void Init()		override;//初期化
	void Update()	override;//更新
	void Move()		override;//移動
protected:
};

