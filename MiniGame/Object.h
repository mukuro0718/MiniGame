//====================================================
// @brief �I�u�W�F�N�g�x�[�X�N���X
// �e�I�u�W�F�N�g�̃x�[�X�N���X�͂��̃N���X���p������
//====================================================
#pragma once

class WrapVECTOR;
class Transform;
class Object abstract
{
public:
	Object();			//�R���X�g���N�^
	virtual ~Object(){}//�f�X�g���N�^

	virtual void Update() abstract;//�X�V
	virtual void Init() abstract;//������

	/*getter*/
	const float GetR()const { return this->radius; }
	const WrapVECTOR& GetHitPosition()const;
	const Transform& GetTransform()const;
	const float GetRadius()const { return this->radius; }
	const float GetHeight()const { return this->height; }
protected:
	/*�����o�ϐ�*/
	Transform	transform;		//���W�E�g�嗦�E��]��
	WrapVECTOR	hitPosOffset;	//�����蔻����W
	float		radius;			//���a
	float		height;			//�L�����N�^�[�̍���
};

