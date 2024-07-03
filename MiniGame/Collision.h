//===============================================
// @brief 当たり判定クラス
// カプセルとカプセル
// の当たり判定を実装する
// このクラスは値を保持せず、
// 結果のみを返す関数を実装する
//===============================================
#pragma once

class Object;
class HitResult;
class Collision final
{
public:
	Collision(); //コンストラクタ
	~Collision();//デストラクタ

	/*球と球の当たり判定*/
	HitResult SphereAndSphereCollision(const Object& _in1,const Object& _in2);
};

