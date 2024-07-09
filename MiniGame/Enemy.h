//=====================================================
// @brief �G�l�~�[�N���X
// �e�G�l�~�[�N���X�͂��̃N���X���p��
//=====================================================
#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(const int _modelHandle);	//�R���X�g���N�^
	virtual ~Enemy();				//�f�X�g���N�^
	void Move();//�ړ�
	void MoveOffScreen();//��ʊO�ֈړ�
	const bool GetIsStop()const { return this->isStop; }
protected:
	WrapVECTOR moveTargetPos;//�ړ��ڕW���W
	bool isStop;//��~������
	int breakModelHandle;
	int normalModelHandle;
};

