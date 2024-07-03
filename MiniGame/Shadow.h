//========================================
// 影クラス
// プレイヤーとエネミーに対して丸影の描画を行う
//========================================

#pragma once
class Shadow
{
public:
	Shadow();	//コンストラクタ
	~Shadow();	//デストラクタ
	void Final();//最終処理
	void Draw(const int _stageModelHandle, const VECTOR _targetPos, const float _shadowHeight, const float _shadowSize);//影を描画
private:
	int imageHandle;//影画像ハンドル
};

