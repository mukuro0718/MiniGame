#pragma once
#include "Object.h"

class Transform;
class Building : public Object
{
public:
	Building(const int _modelHandle);//コンストラクタ
	~Building();//デストラクタ

	void		Init		()override;						//初期化
	void		Update		()override;						//更新
	const void	Draw		()const;						//描画
	void		OnIsMove	()		{ this->isMove = true; }//移動フラグを立てる
	const bool	GetIsMove	()const { return this->isMove; }//移動フラグのgetter
	const void SetPos(const WrapVECTOR& _pos) { this->transform.pos = _pos; }
private:
	int modelHandle;//モデルハンドル
	bool isMove;//移動フラグ
};

