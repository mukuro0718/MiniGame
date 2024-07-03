//====================================================
// @brief オブジェクトベースクラス
//====================================================
#pragma once

class WrapVECTOR;
class Transform
{
public:
	Transform();			//コンストラクタ
	virtual ~Transform(){}	//デストラクタ

	void showInfo(const std::string _name);//メンバ変数に保持されている値の表示

	/*メンバ変数*/
	WrapVECTOR pos;		//座標
	WrapVECTOR scale;	//拡大率
	WrapVECTOR rotate;	//回転率
};

