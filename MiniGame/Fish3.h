//==============================================
// @brief �����ȂR�N���X
//==============================================
#pragma once
#include "Amo.h"

class Fish3 : public Amo
{
public:
	Fish3(const int _modelHandle, const int _imageHandle);	//�R���X�g���N�^
	virtual ~Fish3();				//�f�X�g���N�^

	void Init()		override;//������
	void Update()	override;//�X�V
	void Move()		override;//�ړ�
protected:
};

