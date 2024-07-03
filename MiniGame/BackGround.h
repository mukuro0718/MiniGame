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
	virtual ~BackGround();	//デストラクタ
	void	Update();		//更新
	void	Init();			//初期化
private:
	/*構造体・列挙体*/
	struct Vec2d
	{
		int x = 0;
		int y = 0;
	};
	enum class BackGroundType
	{
		NIGHT	= 0,//夜
		CAVE	= 1,//洞窟
		FOREST	= 2,//森
		OCEAN	= 3,//海
	};
	/*内部処理関数*/
	BackGround();			//コンストラクタ
	void Move();
	void ChangeBackGround();//背景の変更
	void UpdateAlpha();
	const void	Draw()const;	//描画
	/*メンバ変数*/
	static BackGround*	instance;							//唯一のインスタンス
	int imageWidth;//画像の横の大きさ
	int imageHeight;//画像の縦の大きさ
	std::vector<int> moveX;		//移動サイズ
	std::vector<int> velocity;		//移動速度
	std::vector<int> imageHandle;	//画像ハンドル
	int alpha;
	int maxAlpha;
	bool isEraseImage;//画像を消すか

};

