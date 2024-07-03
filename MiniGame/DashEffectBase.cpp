#include "DashEffectBase.h"
/// <summary>
/// �R���X�g���N�^
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
/// �f�X�g���N�^
/// </summary>
DashEffectBase::~DashEffectBase()
{

}
/// <summary>
/// �X�V
/// </summary>
const void DashEffectBase::Init(const VECTOR _targetPos)
{
	m_pos = _targetPos;
	m_alpha = m_maxAlpha;
}
/// <summary>
/// �X�V
/// </summary>
const void DashEffectBase::Update(const bool _isRun, const VECTOR _targetPos)
{
	//�A���t�@���ŏ��ȉ���������
	if (m_alpha <= m_minAlpha)
	{
		//���������Ă����珉��������
		if (_isRun)
		{
			m_pos = _targetPos;
			m_alpha = m_maxAlpha;
		}
	}
	else
	{
		//�A���t�@�����炷
		m_alpha -= m_addAlpha;
	}
}
/// <summary>
/// �`��
/// </summary>
const void DashEffectBase::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
	DrawBillboard3D(m_pos,m_cx,m_cy,m_size,m_angle,m_handle,TRUE);
	//DrawSphere3D(m_pos, 10.0f, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}