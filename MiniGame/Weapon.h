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
	const void Draw()const;//描画
protected:
	/*メンバ変数*/
	int modelHandle;//モデルハンドル
};

