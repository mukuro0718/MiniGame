//========================================================
// @brief 爆発エフェクトクラス
// ２８枚の画像を切り替えて描画
//========================================================
#pragma once
class Explosion
{
public:
	Explosion();//コンストラクタ
	~Explosion();//デストラクタ

	void		Init	();		//初期化
	void		Update	();		//更新
	const void	Draw	()const;//描画
private:

	WrapVECTOR pos;
	float imageSize;
	vector<int> imageHandle;//画像ハンドル
	int drawFrameCount;//描画用フレームカウント（描画が開始されたときに計測を開始し、定数で割った余りが０の時に描画画像を切り替える）
	int nowDrawImage;//現在描画中の画像
};

