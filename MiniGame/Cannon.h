//==================================================
// @brief�@��C�N���X
//==================================================
#pragma once
#include "Weapon.h"

class Cannon : public Weapon
{
public:
	Cannon(const int _modelHandle);//�R���X�g���N�^
	~Cannon();						//�f�X�g���N�^

	void Init()		override;//������
	void Update()	override;//�X�V
private:
	WrapVECTOR posOffset;//�␳���W

};

