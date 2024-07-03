//==================================================
// @brief　バズーカクラス
//==================================================
#pragma once
#include "Weapon.h"

class Bazooka : public Weapon
{
public:
	Bazooka(const int _modelHandle);//コンストラクタ
	~Bazooka();						//デストラクタ

	void Init()		override;//初期化
	void Update()	override;//更新
private:
	WrapVECTOR posOffset;//補正座標
};

