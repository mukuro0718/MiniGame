//=========================================
// @brief ダッシュエフェクトベースクラス
// ダッシュ時の煙を表示する
// 歩いているときは表示しない
//=========================================
#pragma once
#include<DxLib.h>
class DashEffectBase
{
public:
	DashEffectBase(
		const float _cx, 
		const float _cy, 
		const float _size, 
		const float _angle, 
		const int _handle,
		const int	_minAlpha,
		const int	_maxAlpha,
		const int	_addAlpha
	);	//コンストラクタ
	~DashEffectBase();	//デストラクタ

	const void Init(const VECTOR _targetPos);	//初期化
	const void Update(const bool _isRun, const VECTOR _targetPos);//更新
	const void Draw();	//描画
private:
	VECTOR m_pos;		//座標
	float  m_cx;		//画像の中心座標
	float  m_cy;		//画像の中心座標
	float  m_size;		//大きさ
	float  m_angle;		//回転率
	int	   m_handle;	//画像ハンドル
	int	   m_minAlpha;	//最小アルファ
	int	   m_maxAlpha;	//最大アルファ
	int	   m_addAlpha;	//追加アルファ（マイナスも許可）
	int    m_alpha;		//アルファ
};

