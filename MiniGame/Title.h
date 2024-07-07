//=============================================
// @brief　タイトルシーン
//=============================================
#pragma once
#include "SceneBase.h"

class Title : public SceneBase
{
public:
	Title();	//コンストラクタ
	~Title();	//デストラクタ

	void Update		()override;//更新
	void Draw		()override;//描画
	void EndProcess	()override;//終了処理

private:
	/*列挙体*/
	//画像の種類
	enum class ImageType
	{
		TITLE_LOGO,
		PUSH_BUTTON,
	};

	/*内部処理関数*/
	const void Draw()const;//描画

	/*メンバ変数*/
	int imageHandle;
};

