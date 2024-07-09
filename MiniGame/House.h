#pragma once
#include "Object.h"
class House : public Object
{
public:
	House(const int _modelHandle);	//コンストラクタ
	~House();						//デストラクタ

	void		Init	()override;	//初期化
	void		Update	()override;	//更新
	const void	Draw	()const;	//描画
private:
	/*内部処理関数*/

	/*メンバ変数*/
	int modelHandle;//モデルハンドル
};

