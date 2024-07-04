//===============================================
// @brief �����蔻��N���X
// �J�v�Z���ƃJ�v�Z��
// �̓����蔻�����������
// ���̃N���X�͒l��ێ������A
// ���ʂ݂̂�Ԃ��֐�����������
//===============================================
#pragma once
#include <cassert>

class Object;
class HitResult;
class Collision final
{
public:
	virtual ~Collision();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new Collision();
	}

	/*�C���X�^���X�̎擾*/
	static Collision& GetInstance()
	{
		assert(instance != nullptr);
		return *instance;
	}

	/*�C���X�^���X�̍폜*/
	static void DeleteInstance()
	{
		if (instance != nullptr)
		{
			delete(instance);
			instance = nullptr;
		}
	}

	/*���Ƌ��̓����蔻��*/
	HitResult* SphereAndSphereCollision(const Object& _in1,const Object& _in2);
private:
	/*���������֐�*/
	Collision(); //�R���X�g���N�^

	/*�����o�ϐ�*/
	static Collision* instance;//�B��̃C���X�^���X
};

