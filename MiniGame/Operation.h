//====================================================
// @brief 値段UIクラス
//====================================================
#pragma once

class Operation final
{
public:
	Operation(const int _fontHandle);//コンストラクタ
	~Operation();//デストラクタ

	void		Init	();		//初期化
	void		Update	();		//更新
	const void	Draw	()const;//描画

private:
	static constexpr int POS_Y_OFFSET = 100;

	/*内部処理関数*/

	/*メンバ変数*/
	int fontHandle;
	vector<int> pos;
	vector<string> text;
	vector<int> endPosX;
	int moveX;
	bool isStart;
	bool isStop;
	bool isEnd;
	bool isFinish;
	int color;
	int textIndex;
	int stopFrameCount;
};

