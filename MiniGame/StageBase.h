//========================================
// @brief �X�e�[�W�x�[�X�N���X
// ���̃N���X���x�[�X�ɃM�~�b�N��ǉ�����
// �e�X�e�[�W�����
//========================================
#pragma once
#include<DxLib.h>
class StageBase
{
public:
	StageBase();	//�R���X�g���N�^
	virtual ~StageBase(){}	//�f�X�g���N�^
	virtual const void Update() = 0;//�X�V
	virtual const void Draw() = 0;	//�`��
};

