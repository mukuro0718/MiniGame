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

	void Init		();			//初期化
	void Update		()override;	//更新
	void Draw		()override;	//描画
	void EndProcess	()override;	//終了処理
private:
	int alpha;
	bool isEnd;
};

