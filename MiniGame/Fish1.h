//==============================================
// @brief �����ȂP�N���X
//==============================================
#pragma once
#include "Amo.h"

class Fish1 : public Amo
{
public:
	Fish1(const int _modelHandle);	//�R���X�g���N�^
	virtual ~Fish1();				//�f�X�g���N�^

	void Init()		override;//������
	void Update()	override;//�X�V
	void Move()		override;//�ړ�
protected:
};

