//==============================================
// @brief ������2�N���X
//==============================================
#pragma once
#include "Amo.h"

class Fish2 : public Amo
{
public:
	Fish2(const int _modelHandle);	//�R���X�g���N�^
	virtual ~Fish2();				//�f�X�g���N�^

	void Init()		override;//������
	void Update()	override;//�X�V
	void Move()		override;//�ړ�
protected:
};

