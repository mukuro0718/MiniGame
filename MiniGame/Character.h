//========================================================
// @brief キャラクタークラス
// キャラクター（エネミー・プレイヤー）はこのクラスを継承する
// 純粋仮想
//========================================================
#pragma once
#include "Object.h"

class WrapVECTOR;
class Transform;
class Shadow;
class Character abstract : public Object
{
public:
	Character(const int _modelHandle);	//コンストラクタ
	virtual ~Character();				//デストラクタ

	/*getter*/
	const Transform&	GetTransform()const { return this->transform; }	//プレイヤー座標のgetter
	const WrapVECTOR	GetMoveVec	()const { return this->moveVec;}	//移動ベクトルのgetter
	const float			GetRadius	()const { return this->radius; }	//半径のgetter
	const void			Draw		()const;							//描画

protected:
	/*内部処理関数*/
	/*メンバ変数*/
	WrapVECTOR	initPos;	//初期座標
	WrapVECTOR	moveVec;	//移動ベクトル
	WrapVECTOR	fixVec;		//補正ベクトル
	Shadow*		shadow;		//影
	int			modelHandle;//モデルハンドル
	float		radius;		//モデルの半径
};

