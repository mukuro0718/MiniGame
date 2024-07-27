//====================================================
// @brief 値段UIクラス
//====================================================
#pragma once

class Transform;
class Operation final
{
public:
	Operation(const int _fontHandle,const int _imageHandle, const int _modelHandle);//コンストラクタ
	~Operation();//デストラクタ

	void		Init	();		//初期化
	void		Update	();		//更新
	const void	Draw	()const;//描画
	const bool GetIsShowRideButton()const { return this->isShowRideButton; }
private:
	enum class PosType
	{
		TUTORIAL = 0,
		RIDE = 1,
	};
	static constexpr int POS_Y_OFFSET = 100;
	static const int TEXT_COLOR_GREEN;
	static constexpr float BUTTON_POS_Y_OFFSET = 10.0f;
	static constexpr int MAX_ALPHA = 255;
	static constexpr int MIN_ALPHA = 0;
	/*内部処理関数*/

	/*メンバ変数*/
	int fontHandle;
	vector<int> pos;
	Transform transform;
	int moveX;
	bool isStart;
	bool isStop;
	bool isEnd;
	bool isFinish;

	bool isAddButtonSize;

	bool isShowTutorial;
	bool isShowTutorialButton;
	bool isShowRideButton;

	int color;
	int textIndex;
	int imageHandle;
	int modelHandle;
	int stopFrameCount;
	float buttonSize;
	int alpha;
	bool isAddAlpha;
};

