//=============================================
// @brief リザルトシーン
//=============================================
#pragma once
#include "SceneBase.h"

class Transform;
class Result : public SceneBase
{
public:
	Result();	//コンストラクタ
	~Result();	//デストラクタ

	void Update		()override;//更新
	void Draw		()override;//描画
	void EndProcess	()override;//終了処理
private:
	/*列挙体・構造体*/
	//フォントの種類
	enum class FontType
	{
		OVER   = 0,
		CLEAR  = 1,
		BUTTON = 2,
	};
	//モデルの種類
	enum class ModelType
	{
		CAR = 0,
		HOUSE = 1,
	};
	struct Vec2d
	{
		int x = 0;
		int y = 0;
	};
	/*静的定数*/
	static constexpr int MAX_ALPHA = 255;
	static constexpr int EXPLOSIONT_SIZE = 1920;
	static const int COLOR_BLACK;
	static const int COLOR_WHITE;

	/*内部処理関数*/
	void UpdateGameOver	();
	void UpdateGameClear();
	void DrawGameOver	();
	void DrawGameClear	();
	void UpdateButtonAlpha();
	void Create();
	void SetTransform();
	void SetText();
	/*メンバ変数*/
	vector<Vec2d> textPos;
	bool isGameOver;
	bool isGameClear;
	bool isEnd;
	bool isAddAlpha;
	int  textColor;
	int  transitionAlpha;
	int  color;
	vector<int>	 fontHandle;
	vector<int>	 explosionHandle;
	int explosionIndex;
	int explosionFrameCount;
	int smokeHandle;
	bool isExplosion;
	int  buttonAlpha;
	vector<int> modelHandle;
	vector<Transform> transform;
};

