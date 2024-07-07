//=============================================
// @brief リザルトシーン
//=============================================
#pragma once
#include "SceneBase.h"

class Result : public SceneBase
{
public:
	Result();	//コンストラクタ
	~Result();	//デストラクタ

	void Update		()override;//更新
	void Draw		()override;//描画
	void EndProcess	()override;//終了処理

};

