//=============================================
//ロード画面クラス
//=============================================
#pragma once

class LoadScene
{
public:
	LoadScene();//コンストラクタ
	~LoadScene();//デストラクタ

	void Init();//初期化
	void Final();//最終処理
	void Update();//更新
	void Draw();//描画
private:
	/*メンバ変数*/
	int		alpha;					//アルファ
	int		isIncWaitFrameCount;	//フレームカウント
	int		updateWaitFrameCount;	//フレームカウント
	bool	isIncTheValue;			//値が増加しているか(TRUE:増加 FALSE:減少 )
};

