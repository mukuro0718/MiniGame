//===========================================
// @brief ゲームカメラクラス
//===========================================
#pragma once
#include "Object.h"

class WrapVECTOR;
class GameCamera : public Object
{
public:
	GameCamera();//コンストラクタ
	~GameCamera();//デストラクタ

	void Init()		override;//初期化
	void Update()	override;//更新
private:
	/*メンバ変数*/
	WrapVECTOR pos;			//カメラ座標
	WrapVECTOR targetPos;	//ターゲット座標
};

