//====================================================
// @brief 値段UIクラス
//====================================================
#pragma once

class Price final
{
public:
	Price(const int _fontHandle);//コンストラクタ
	~Price();//デストラクタ

	void Init();	//初期化
	void Update();	//更新

private:
	/*内部処理関数*/
	const void Draw()const;

	/*メンバ変数*/
	int fontHandle;
	vector<int> pos;
	int color;
};

