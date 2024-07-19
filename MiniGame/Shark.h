//==============================================
// @brief さめクラス
//==============================================
#pragma once
#include "Amo.h"

class Shark : public Amo
{
public:
	Shark(const int _modelHandle, const int _imageHandle);	//コンストラクタ
	virtual ~Shark();				//デストラクタ

	void Init()		override;//初期化
	void Update()	override;//更新
	void Move()		override;//移動
};

