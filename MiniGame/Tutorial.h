//=============================================
// @brief チュートリアルシーン
//=============================================
#pragma once
#include "SceneBase.h"

class Tutorial : public SceneBase
{
public:
	Tutorial();	//コンストラクタ
	~Tutorial();	//デストラクタ

	void Update()override;//更新
	void EndProcess()	override;//終了処理

};

