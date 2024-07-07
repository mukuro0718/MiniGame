//=======================================
// @brief ゲームクラス
//=======================================
#pragma once
#include "SceneBase.h"

class Game : public SceneBase
{
public:
	Game();		//コンストラクタ
	~Game();	//デストラクタ

	void Update		()override;//更新
	void Draw		()override;//描画
	void EndProcess	()override;//終了処理
private:
};

