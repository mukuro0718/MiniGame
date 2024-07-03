//====================================================
// @brief オブジェクトベースクラス
// 各オブジェクトのベースクラスはこのクラスを継承する
//====================================================
#pragma once

class WrapVECTOR;
class Transform;
class Object abstract
{
public:
	Object();			//コンストラクタ
	virtual ~Object(){}//デストラクタ

	virtual void Update() abstract;//更新
	virtual void Init() abstract;//初期化

	/*getter*/
	const float GetR()const { return this->radius; }
	const WrapVECTOR& GetHitPosition()const;
	const Transform& GetTransform()const;
	const float GetRadius()const { return this->radius; }
	const float GetHeight()const { return this->height; }
protected:
	/*メンバ変数*/
	Transform	transform;		//座標・拡大率・回転率
	WrapVECTOR	hitPosOffset;	//当たり判定座標
	float		radius;			//半径
	float		height;			//キャラクターの高さ
};

