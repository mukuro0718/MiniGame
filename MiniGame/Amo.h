//==============================================
// @brief 弾クラス（今回はさかなが弾）
//==============================================
#pragma once
#include "Object.h"
class Amo abstract: public Object
{
public:
	Amo(const int _modelHandle);//コンストラクタ
	virtual ~Amo();				//デストラクタ
	virtual void	Move			()abstract;						//移動
	void			SetPos			(const WrapVECTOR& _pos);		//座標のsetter
	void			MoveOffScreen	();								//画面外へ移動
	void			OnIsHit			() { this->isHit = true; }		//isHitフラグを立てる
	const bool		GetIsHit		()const { return this->isHit; }	//isHitフラグを取得
	const bool		GetIsSet		()const { return this->isSet; }	//セットフラグのgetter
	const bool		GetIsOut		()const { return this->isOut; }
	const bool		GetIsRebel		()const { return this->isRebel;}//反逆フラグのgetter
	const int		GetPrice		()const { return this->price; }	//値段のgetter
protected:
	/*内部処理関数*/
	void		SetTransform(vector<float> _pos, vector<float> _rotate, vector<float> _scale);//トランスフォームの設定
	const void	Draw()						const;	//描画
	void		ChangeRotate();						//回転率の変更
	void		ChangeScale();						//スケールの変更
	const float GetRandom(const int _range)	const;	//ランダムなfloat値の取得
	void		HitCheck();//当たり判定
	/*メンバ変数*/
	WrapVECTOR	moveVec;	//移動ベクトル
	WrapVECTOR	posOffset;	//位置補正値
	WrapVECTOR	hitPos;		//当たり判定位置
	float		velocity;	//速度
	int			modelHandle;//モデルハンドル
	int			price;		//値段
	bool		isHit;		//プレイヤーに当たったか
	bool		isOut;		//画面外へ出たか
	bool		isSet;		//設定フラグ
	bool		isRebel;	//反逆するか
};

