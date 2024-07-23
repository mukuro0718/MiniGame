//========================================================
// @brief �L�����N�^�[�N���X
// �L�����N�^�[�i�G�l�~�[�E�v���C���[�j�͂��̃N���X���p������
// �������z
//========================================================
#pragma once
#include "Object.h"

class WrapVECTOR;
class Transform;
class Shadow;
class Character abstract : public Object
{
public:
	Character(const int _modelHandle);	//�R���X�g���N�^
	virtual ~Character();				//�f�X�g���N�^

	/*getter*/
	const Transform&	GetTransform()const { return this->transform; }	//�v���C���[���W��getter
	const WrapVECTOR	GetMoveVec	()const { return this->moveVec;}	//�ړ��x�N�g����getter
	const float			GetRadius	()const { return this->radius; }	//���a��getter
	const void			Draw		()const;							//�`��

protected:
	/*���������֐�*/
	/*�����o�ϐ�*/
	WrapVECTOR	initPos;	//�������W
	WrapVECTOR	moveVec;	//�ړ��x�N�g��
	WrapVECTOR	fixVec;		//�␳�x�N�g��
	Shadow*		shadow;		//�e
	int			modelHandle;//���f���n���h��
	float		radius;		//���f���̔��a
};

