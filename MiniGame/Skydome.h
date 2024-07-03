#pragma once
#include "Object.h"
class Skydome : public Object
{
public:
	Skydome(const int _modelHandle);	//コンストラクタ
	~Skydome();	//デストラクタ
	void Init()override;	//初期化
	void Update()override;	//更新
private:
	/*内部処理関数*/
	const void Draw()const;

	/*メンバ変数*/
	int modelHandle;//モデルのハンドル
};


