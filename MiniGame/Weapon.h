//==================================================
// @brief�@����N���X
//==================================================
#pragma once
#include "Object.h"

class Weapon : public Object
{
public:
	Weapon(const int _modelHandle);	//�R���X�g���N�^
	virtual ~Weapon();				//�f�X�g���N�^
	void SetPos(const WrapVECTOR& _pos);//���W��setter
protected:
	/*���������֐�*/
	const void Draw()const;//�`��
	/*�����o�ϐ�*/
	int modelHandle;//���f���n���h��
};

