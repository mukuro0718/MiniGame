//========================================
// @brief ステージベースクラス
// このクラスをベースにギミックを追加して
// 各ステージを作る
//========================================
#pragma once
#include<DxLib.h>
class StageBase
{
public:
	StageBase();	//コンストラクタ
	virtual ~StageBase(){}	//デストラクタ
	virtual const void Update() = 0;//更新
	virtual const void Draw() = 0;	//描画
};

