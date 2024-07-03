//==================================================
// @brief　武器クラス
//==================================================
#pragma once
#include "Object.h"

class Weapon : public Object
{
public:
	Weapon(const int _modelHandle);	//コンストラクタ
	virtual ~Weapon();				//デストラクタ
	void SetPos(const WrapVECTOR& _pos);//座標のsetter
protected:
	/*内部処理関数*/
	const void Draw()const;//描画
	/*メンバ変数*/
	int modelHandle;//モデルハンドル
};

