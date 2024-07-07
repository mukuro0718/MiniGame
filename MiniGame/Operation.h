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
	const void	Draw	()const;//描画

private:
	/*内部処理関数*/

	/*メンバ変数*/
	int fontHandle;
	vector<int> pos;
	int color;
};

