//=======================================
// @brief アイリスイン・アウトクラス
// 円が画面の真ん中に向かって縮まったり、
// 逆に真ん中から円形に広がる感じ
//=======================================
class IrisTransitor : public Transitor
{
private:
	int handleForMaskScreen_;//マスク転送用グラフィックハンドル
	int maskH_;//マスクハンドル
	float diagonalLength_;//対角線の長さ
	bool irisOut_ = false;//アイリスアウトフラグ(falseならアイリスイン)
public:
	IrisTransitor(bool irisOut = false, int interval = 60, bool isTiled = false, int gHandle = -1);
	~IrisTransitor();
	virtual void Update() override;
	virtual void Draw() override;
};


