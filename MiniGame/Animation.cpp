//===========================================================================
//@brief アニメーションクラス
//===========================================================================

#include"Animation.h"

/// <summary>
/// コンストラクタ
/// </summary>
Animation::Animation()
	: m_animAttachIndex(0)
	, m_prevAnim(0)
	, m_nowAnim(0)
	, m_animTotalTime(0.0f)
	, m_animPlayTime(0.0f)
	, m_isChangeAnim(false)
{
}
/// <summary>
/// デストラクタ
/// </summary>
Animation::~Animation()
{
	m_animModelHandle.clear();
	m_useAnimIndex.clear();
}
/// <summary>
/// アニメーションの追加
/// </summary>
/// <param name="animModelHandle">アタッチしたいアニメーションを持っているモデルのハンドル</param>
/// <param name="useAnimIndex">アタッチしたいアニメーションのインデックス番号</param>
void Animation::Add(int _animModelHandle,int _AnimIndex)
{
	m_animModelHandle.push_back(_animModelHandle);
	m_useAnimIndex.push_back(_AnimIndex);
}
/// <summary>
/// アニメーションのアタッチ
/// </summary>
/// <param name="animKind">アニメーションをアタッチしたいモデルのハンドル</param>
void Animation::Attach(int* _modelHandle)
{
	//アニメーションのアタッチ
	m_animAttachIndex = MV1AttachAnim(*_modelHandle, m_useAnimIndex[m_nowAnim], m_animModelHandle[m_nowAnim], FALSE);
	//アニメーションの総再生時間を設定
	m_animTotalTime = MV1GetAttachAnimTotalTime(*_modelHandle, m_animAttachIndex);
}
/// <summary>
/// アニメーションの再生
/// </summary>
void Animation::Play(int *_modelHandle, const int _useAnimIndex, const float _addAnimPlayTime)
{
	//もし今までアタッチしていたアニメーションと次のアニメーションが違うなら
	if (m_nowAnim != _useAnimIndex)
	{
		m_prevAnim = m_nowAnim;
		m_nowAnim = _useAnimIndex;
		m_isChangeAnim = false;
		m_animPlayTime = 0.0f;
		//今までアタッチしていたアニメーションをでタッチする
		MV1DetachAnim(*_modelHandle, m_animAttachIndex);
		//アニメーションのアタッチ
		Attach(_modelHandle);
	}
	//アニメーション再生時間を設定
	MV1SetAttachAnimTime(*_modelHandle, m_animAttachIndex, m_animPlayTime);
	//アニメーション
	m_animPlayTime += _addAnimPlayTime;//再生時間を進める
	//再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	if (m_animPlayTime >= m_animTotalTime)
	{
		m_animPlayTime = 0.0f;
		m_isChangeAnim = true;
	}
}
