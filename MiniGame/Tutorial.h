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

	void Update		()override;//更新
	void Draw		()override;//描画
	void EndProcess	()override;//終了処理
private:
	int fontHandle;
	int imageHandle;
	int movieHandle;
};

