//==============================================
// @brief �����ȂS�N���X
//==============================================
#pragma once
#include "Amo.h"

class Fish4 : public Amo
{
public:
	Fish4(const int _modelHandle);	//�R���X�g���N�^
	virtual ~Fish4();				//�f�X�g���N�^

	void Init()		override;//������
	void Update()	override;//�X�V
	void Move()		override;//�ړ�
protected:
};

