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
	//画像の種類
	enum class ImageType
	{
		TITLE_IMAGE,
		CLOUD,
	};

	/*静的定数*/
	static constexpr int MAX_ALPHA = 255;

	/*内部処理関数*/
	BackGround();			//コンストラクタ
	void Move();
	void ChangeCloudInfo(const int _index);//背景の変更
	void UpdateAlpha();
	int GetRandom(const int _range, const bool _isSign,const int _offset);//ランダム値の取得

	/*メンバ変数*/
	static BackGround*	instance;		//唯一のインスタンス
	std::vector<Vec2d>	cloudPos;		//描画座標
	std::vector<Vec2d>	cloudSize;		//画像サイズ
	std::vector<int>	cloudVelocity;	//移動速度
	vector<int>			imageHandle;	//画像ハンドル
	bool				isEraseImage;	//画像を消すか
	int					alpha;			//アルファ
};

