//=========================================
// @brief �_�b�V���G�t�F�N�g�x�[�X�N���X
// �_�b�V�����̉���\������
// �����Ă���Ƃ��͕\�����Ȃ�
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
	);	//�R���X�g���N�^
	~DashEffectBase();	//�f�X�g���N�^

	const void Init(const VECTOR _targetPos);	//������
	const void Update(const bool _isRun, const VECTOR _targetPos);//�X�V
	const void Draw();	//�`��
private:
	VECTOR m_pos;		//���W
	float  m_cx;		//�摜�̒��S���W
	float  m_cy;		//�摜�̒��S���W
	float  m_size;		//�傫��
	float  m_angle;		//��]��
	int	   m_handle;	//�摜�n���h��
	int	   m_minAlpha;	//�ŏ��A���t�@
	int	   m_maxAlpha;	//�ő�A���t�@
	int	   m_addAlpha;	//�ǉ��A���t�@�i�}�C�i�X�����j
	int    m_alpha;		//�A���t�@
};

