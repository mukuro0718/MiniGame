//===============================================
// @brief �����蔻��N���X
// �J�v�Z���ƃJ�v�Z��
// �̓����蔻�����������
// ���̃N���X�͒l��ێ������A
// ���ʂ݂̂�Ԃ��֐�����������
//===============================================
#pragma once

class Object;
class HitResult;
class Collision final
{
public:
	Collision(); //�R���X�g���N�^
	~Collision();//�f�X�g���N�^

	/*���Ƌ��̓����蔻��*/
	HitResult SphereAndSphereCollision(const Object& _in1,const Object& _in2);
};

