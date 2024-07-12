#pragma once
//===========================================
// @brief タイトルカメラクラス
//===========================================
#pragma once
#include "Object.h"

class WrapVECTOR;
class ResultCamera
{
public:
	ResultCamera();//コンストラクタ
	~ResultCamera();//デストラクタ

	void Init		();//初期化
	void ClearUpdate();//ゲームクリア時更新
	void OverUpdate	();//ゲームオーバー時更新
private:
	/*メンバ変数*/
	WrapVECTOR pos;			//カメラ座標
	WrapVECTOR targetPos;	//ターゲット座標
};

