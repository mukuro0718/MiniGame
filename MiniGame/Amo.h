//==============================================
// @brief �e�N���X�i����͂����Ȃ��e�j
//==============================================
#pragma once
#include "Object.h"
class Amo abstract: public Object
{
public:
	Amo(const int _modelHandle, const int _imageHandle);//�R���X�g���N�^
	virtual ~Amo();				//�f�X�g���N�^
	const void		Draw			()const;						//�`��
	virtual void	Move			()abstract;						//�ړ�
	void			SetPos			(const WrapVECTOR& _pos);		//���W��setter
	void			MoveOffScreen	();								//��ʊO�ֈړ�
	void			OnIsHit			() { this->isHit = true; }		//isHit�t���O�𗧂Ă�
	const bool		GetIsHit		()const { return this->isHit; }	//isHit�t���O���擾
	const bool		GetIsSet		()const { return this->isSet; }	//�Z�b�g�t���O��getter
	const bool		GetIsOut		()const { return this->isOut; }	//��x�ł���ʊO�ɏo����
	const bool		GetIsRebel		()const { return this->isRebel;}//���t�t���O��getter
protected:
	/*���������֐�*/
	void		SetTransform(vector<float> _pos, vector<float> _rotate, vector<float> _scale);	//�g�����X�t�H�[���̐ݒ�
	void		ChangeRotate();																	//��]���̕ύX
	void		ChangeScale	();																	//�X�P�[���̕ύX
	const float GetRandom	(const int _range)const;											//�����_����float�l�̎擾
	void		HitCheck	();																	//�����蔻��
	void Swim();
	/*�����o�ϐ�*/
	WrapVECTOR	moveVec;			//�ړ��x�N�g��
	WrapVECTOR	posOffset;			//�ʒu�␳�l
	WrapVECTOR	hitPos;				//�����蔻��ʒu
	WrapVECTOR	moveTargetPos;		//�ړ��ڕW���W
	float		velocity;			//���x
	int			modelHandle;		//���f���n���h��
	int			imageHandle;		//�摜�n���h��
	int			swimFrameCount;
	bool		isSwimAdd;
	float		swimAngle;
	bool		isHit;				//�v���C���[�ɓ���������
	bool		isOut;				//��ʊO�֏o����
	bool		isSet;				//�ݒ�t���O
	bool		isSetMoveTargetPos;	//�ړ��ڕW���W�̐ݒ�t���O
	bool		isRebel;			//���t���邩
};

