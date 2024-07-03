//===========================================================================
//@brief �A�j���[�V�����N���X
//===========================================================================

#include"Animation.h"

/// <summary>
/// �R���X�g���N�^
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
/// �f�X�g���N�^
/// </summary>
Animation::~Animation()
{
	m_animModelHandle.clear();
	m_useAnimIndex.clear();
}
/// <summary>
/// �A�j���[�V�����̒ǉ�
/// </summary>
/// <param name="animModelHandle">�A�^�b�`�������A�j���[�V�����������Ă��郂�f���̃n���h��</param>
/// <param name="useAnimIndex">�A�^�b�`�������A�j���[�V�����̃C���f�b�N�X�ԍ�</param>
void Animation::Add(int _animModelHandle,int _AnimIndex)
{
	m_animModelHandle.push_back(_animModelHandle);
	m_useAnimIndex.push_back(_AnimIndex);
}
/// <summary>
/// �A�j���[�V�����̃A�^�b�`
/// </summary>
/// <param name="animKind">�A�j���[�V�������A�^�b�`���������f���̃n���h��</param>
void Animation::Attach(int* _modelHandle)
{
	//�A�j���[�V�����̃A�^�b�`
	m_animAttachIndex = MV1AttachAnim(*_modelHandle, m_useAnimIndex[m_nowAnim], m_animModelHandle[m_nowAnim], FALSE);
	//�A�j���[�V�����̑��Đ����Ԃ�ݒ�
	m_animTotalTime = MV1GetAttachAnimTotalTime(*_modelHandle, m_animAttachIndex);
}
/// <summary>
/// �A�j���[�V�����̍Đ�
/// </summary>
void Animation::Play(int *_modelHandle, const int _useAnimIndex, const float _addAnimPlayTime)
{
	//�������܂ŃA�^�b�`���Ă����A�j���[�V�����Ǝ��̃A�j���[�V�������Ⴄ�Ȃ�
	if (m_nowAnim != _useAnimIndex)
	{
		m_prevAnim = m_nowAnim;
		m_nowAnim = _useAnimIndex;
		m_isChangeAnim = false;
		m_animPlayTime = 0.0f;
		//���܂ŃA�^�b�`���Ă����A�j���[�V�������Ń^�b�`����
		MV1DetachAnim(*_modelHandle, m_animAttachIndex);
		//�A�j���[�V�����̃A�^�b�`
		Attach(_modelHandle);
	}
	//�A�j���[�V�����Đ����Ԃ�ݒ�
	MV1SetAttachAnimTime(*_modelHandle, m_animAttachIndex, m_animPlayTime);
	//�A�j���[�V����
	m_animPlayTime += _addAnimPlayTime;//�Đ����Ԃ�i�߂�
	//�Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (m_animPlayTime >= m_animTotalTime)
	{
		m_animPlayTime = 0.0f;
		m_isChangeAnim = true;
	}
}
