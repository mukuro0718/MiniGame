//======================================================
// @brief 背景クラス
// ４つの背景を時間経過で切り替えながら表示
// フェードで切り替える
//======================================================
#pragma once
#include <cassert>

class BackGround
{
public:
	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new BackGround();
	}

	/*インスタンスの取得*/
	static BackGround& GetInstance()
	{
		assert(instance != nullptr);
		return *instance;
	}

	/*インスタンスの解放*/
	static void DeleteInstance()
	{
		if (instance != nullptr)
		{
			delete(instance);
			instance = nullptr;
		}
	}

	/*その他関数*/
	virtual		~BackGround	();		//デストラクタ
	const void	Draw		()const;//描画
	void		Init		();		//初期化
	void		Update		();		//更新
private:
	/*構造体・列挙体*/
	struct Vec2d
	{
		int x = 0;
		int y = 0;
	};
	
	/*内部処理関数*/
	BackGround();			//コンストラクタ
	void Move();
	void ChangeBackGround();//背景の変更
	void UpdateAlpha();
	/*メンバ変数*/
	static BackGround*	instance;		//唯一のインスタンス
	std::vector<int>	moveX;			//移動サイズ
	std::vector<int>	velocity;		//移動速度
	std::vector<int>	imageHandle;	//画像ハンドル
	bool				isEraseImage;	//画像を消すか
	int					imageWidth;		//画像の横の大きさ
	int					imageHeight;	//画像の縦の大きさ
	int					alpha;			//アルファ
	int					maxAlpha;		//最大アルファ

};

