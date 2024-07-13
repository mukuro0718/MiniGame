//=============================================
// @brief リザルトシーン
//=============================================
#pragma once
#include "SceneBase.h"

class Transform;
class WrapVECTOR;
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
	static constexpr int EXPLOSIONT_SIZE = 400;
	static const int COLOR_BLACK;
	static const int COLOR_WHITE;

	/*内部処理関数*/
	void UpdateGameOver	();
	void DrawScore();
	void DrawGameOver	();
	void DrawGameClear	();
	void UpdateButtonAlpha();
	void Create();
	void SetTransform();
	void SetText();
	void InitSmoke();
	Vec2d Convert(const vector<int> _in);
	void SetSmoke(const int _index);
	int GetRandom(const int _range, const bool _isSign,const int _offset);
	void UpdateSmoke();

	/*メンバ変数*/
	vector<Transform>	transform;			//トランスフォーム
	vector<Vec2d>		textPos;			//テキスト座標
	vector<int>			fontHandle;			//フォントハンドル
	vector<int>			explosionHandle;	//爆発画像ハンドル
	vector<int>			modelHandle;		//モデルハンドル
	WrapVECTOR			explosionPos;		//爆発描画座標
	bool				isGameOver;			//ゲームオーバーフラグ
	bool				isGameClear;		//ゲームクリアフラグ
	bool				isEnd;				//シーン終了フラグ
	bool				isAddAlpha;			//α追加フラグ
	bool				isExplosion;		//爆発フラグ
	bool				isDrawClearText;	//クリア文字の描画
	bool				isShowScore;		//スコアの表示
	int					textColor;			//テキストカラー
	int					transitionAlpha;	//遷移α
	int					color;				//色
	int					explosionIndex;		//爆発インデックス
	int					explosionFrameCount;//爆発フレーム数
	int					smokeHandle;		//煙画像ハンドル
	int					buttonAlpha;		//ボタン用α
	vector<WrapVECTOR>	smokeMoveVec;
	vector<WrapVECTOR>  smokePos;
	vector<float>		smokeVelocity;
	vector<int>			smokeSize;
	int					showScoreFrameCount;
};

