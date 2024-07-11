//=============================================
// @brief　タイトルシーン
//=============================================
#pragma once
#include "SceneBase.h"

class Transform;
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
		TITLE_IMAGE = 0,
	};
	//モデルの種類
	enum class ModelType
	{
		FISH_1 = 0,
		FISH_2 = 1,
		FISH_3 = 2,
		PLAYER = 3,
	};
	static constexpr int MAX_ALPHA = 255;

	/*内部処理関数*/
	void		ChangeLogoSizeOffset	();//ロゴサイズオフセットの変更
	void		ChangeTransitionAlpha	();//遷移アルファ値の変更
	void		Create					();//作成
	void		SetTransform			();
	const void	DrawLogo				()const;
	const void	DrawTitleImage			()const;
	const void	DrawTransition			()const;

	/*メンバ変数*/
	int					imageHandle;
	int					fontHandle;
	int					buttonFontHandle;
	int					alpha;
	int					logoAlpha;
	int					buttonAlpha;
	int					sizeOffset;
	bool				isEnd;
	bool				isAddButtonAlpha;
	vector<Transform>	transform;
	vector<int>			modelHandle;
};

