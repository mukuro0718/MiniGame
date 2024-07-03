//===============================================
// @brief 当たり判定結果クラス
// 当たり判定の結果を保持する
//===============================================
#pragma once

class WrapVECTOR;
class HitResult
{
public:
	HitResult();	//コンストラクタ
	~HitResult();	//デストラクタ
	bool		isHit;	//当たり判定
	WrapVECTOR	fixVec;	//
};

