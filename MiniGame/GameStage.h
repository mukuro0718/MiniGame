//====================================
// @brief 回避ステージクラス
//====================================
#pragma once
#include "Object.h"

class GameStage : public Object
{
public:
	GameStage			(const int _modelHandle, const WrapVECTOR& _pos);	//コンストラクタ
	~GameStage			();													//デストラクタ
	void		Update	()override;											//更新
	void		Init	()override;											//初期化
	const void	Draw	()const;											//描画
private:
	/*内部処理関数*/
	
	/*メンバ変数*/
	WrapVECTOR	initPos;	//初期座標
	int			modelHandle;//モデルハンドル
};

