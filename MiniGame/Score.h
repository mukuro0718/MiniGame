//====================================================
// @brief スコアクラス
//====================================================
#pragma once

class Score
{
public:
	Score(const int _forPrice, const int _forSpecialPrice, const int _moneyBag);	//コンストラクタ
	virtual ~Score();										//デストラクタ
	const void	Draw()const;								//描画
private:
	/*列挙隊*/
	//構造体
	struct Vec2d
	{
		int x = 0;
		int y = 0;
	};

	//フォントの種類
	enum class PosType
	{
		PRICE		  = 0,
		SPECIAL_SCORE = 1,
		IMAGE		  = 2,
	};
	/*静的定数*/
	static const int TEXT_COLOR_WHITE;//白文字カラー

	/*内部処理関数*/
	const void DrawPrice		(const int _price)const;//価格の描画
	const void DrawSpetialScore ()const;//特別なスコアの描画
	Vec2d Convert(const vector<int> _in);

	/*メンバ変数*/
	vector<int> fontHandle;
	vector<Vec2d> pos;
	int imageHandle;
};

