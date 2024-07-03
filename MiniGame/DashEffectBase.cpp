#include "DashEffectBase.h"
/// <summary>
/// コンストラクタ
/// </summary>
DashEffectBase::DashEffectBase(
	const float _cx,
	const float _cy,
	const float _size,
	const float _angle, 
	const int _handle,
	const int	_minAlpha,
	const int	_maxAlpha,
	const int	_addAlpha)
	: m_pos{0.0f,0.0f,0.0f}
	, m_cx(_cx)
	, m_cy(_cy)
	, m_size(_size)
	, m_angle(_angle)
	, m_handle(_handle)
	, m_minAlpha(_minAlpha)
	, m_maxAlpha(_maxAlpha)
	, m_addAlpha(_addAlpha)
	, m_alpha(_minAlpha)
{

}
/// <summary>
/// デストラクタ
/// </summary>
DashEffectBase::~DashEffectBase()
{

}
/// <summary>
/// 更新
/// </summary>
const void DashEffectBase::Init(const VECTOR _targetPos)
{
	m_pos = _targetPos;
	m_alpha = m_maxAlpha;
}
/// <summary>
/// 更新
/// </summary>
const void DashEffectBase::Update(const bool _isRun, const VECTOR _targetPos)
{
	//アルファが最小以下だったら
	if (m_alpha <= m_minAlpha)
	{
		//もし走っていたら初期化する
		if (_isRun)
		{
			m_pos = _targetPos;
			m_alpha = m_maxAlpha;
		}
	}
	else
	{
		//アルファを減らす
		m_alpha -= m_addAlpha;
	}
}
/// <summary>
/// 描画
/// </summary>
const void DashEffectBase::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
	DrawBillboard3D(m_pos,m_cx,m_cy,m_size,m_angle,m_handle,TRUE);
	//DrawSphere3D(m_pos, 10.0f, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}