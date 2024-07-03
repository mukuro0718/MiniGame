#include "DashEffect.h"
#include "DashEffectBase.h"
#include "DashEffectConst.h"
#include "LoadingData.h"
/// <summary>
/// コンストラクタ
/// </summary>
DashEffect::DashEffect()
	: m_const(nullptr)
	, m_nowEffectNum(0)
	, m_waitInitNum(0)
{
	auto& load = LoadingData::GetInstance();
	m_const = new DashEffectConst();
	for (int i = 0; i < m_const->GetEffectNum(); i++)
	{
		m_base.push_back(new DashEffectBase(m_const->GetCX(), m_const->GetCY(), m_const->GetMaxSize(), m_const->GetAngle(), load.GetSmokeImageHandle(), m_const->GetMinAlpha(), m_const->GetMaxAlpha(), m_const->GetAddAlpha()));
	}
}
/// <summary>
/// デストラクタ
/// </summary>
DashEffect::~DashEffect()
{

}
/// <summary>
/// 更新
/// </summary>
const void DashEffect::Update(const bool _isRun, const VECTOR _targetPos)
{
	for (int i = 0; i < m_const->GetEffectNum(); i++)
	{
		m_base[i]->Update(_isRun,_targetPos);
	}
	if (_isRun)
	{
		m_waitInitNum++;
		if (m_waitInitNum >= 10)
		{
			m_base[m_nowEffectNum]->Init(_targetPos);
			m_nowEffectNum++;
			m_waitInitNum = 0;
		}
		if (m_nowEffectNum == m_const->GetEffectNum())
		{
			m_nowEffectNum = m_const->GetEffectNum() - 1;
		}
	}
	else
	{
		m_nowEffectNum = 0;
		m_waitInitNum = 0;
	}
}
/// <summary>
/// 描画
/// </summary>
const void DashEffect::Draw()
{
	for (int i = 0; i < m_const->GetEffectNum(); i++)
	{
		m_base[i]->Draw();
	}
}