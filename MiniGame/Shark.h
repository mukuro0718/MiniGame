//==============================================
// @brief ���߃N���X
//==============================================
#pragma once
#include "Amo.h"

class Shark : public Amo
{
public:
	Shark(const int _modelHandle, const int _imageHandle);	//�R���X�g���N�^
	virtual ~Shark();				//�f�X�g���N�^

	void Init()		override;//������
	void Update()	override;//�X�V
	void Move()		override;//�ړ�
};

