//==================================================
// @brief�@�o�Y�[�J�N���X
//==================================================
#pragma once
#include "Weapon.h"

class Bazooka : public Weapon
{
public:
	Bazooka(const int _modelHandle);//�R���X�g���N�^
	~Bazooka();						//�f�X�g���N�^

	void Init()		override;//������
	void Update()	override;//�X�V
private:
	WrapVECTOR posOffset;//�␳���W
};

