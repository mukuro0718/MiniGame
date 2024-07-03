//==================================================
// @brief　大砲クラス
//==================================================
#pragma once
#include "Weapon.h"

class Cannon : public Weapon
{
public:
	Cannon(const int _modelHandle);//コンストラクタ
	~Cannon();						//デストラクタ

	void Init()		override;//初期化
	void Update()	override;//更新
private:
	WrapVECTOR posOffset;//補正座標

};

