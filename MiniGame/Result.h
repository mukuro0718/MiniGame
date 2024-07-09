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
private:
	/*列挙体*/
	enum class TextType
	{
		MAIN,
		OVER,
		CLEAR,
	};

	/*静的定数*/
	static constexpr int MAX_ALPHA = 255;

	/*内部処理関数*/
	void GameOver();
	void GameClear();

	/*メンバ変数*/
	vector<vector<int>> textPos;
	int textColor;
	int alpha;
	int color;
	bool isGameOver;
	bool isGameClear;
	bool isEnd;
	bool isNext;
	int fontHandle;
	int waitFrameCount;
	int imageHandle;
	bool isAdd;
	int sizeOffset;
	int buttonAlpha;
};

