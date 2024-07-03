//=================================================
// @brief ��ʂ̐ݒ�N���X
// window/fullScreen�̐؂�ւ�
// �J���[�r�b�g�̐ݒ�
// ��ʃT�C�Y�̐ݒ�
//=================================================

#pragma once
#include <cassert>

class SetUpScreen
{
public:
	virtual ~SetUpScreen();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new SetUpScreen();
	}

	/*�C���X�^���X�̎擾*/
	static SetUpScreen& GetInstance()
	{
		assert(instance != nullptr);
		return *instance;
	}

	/*�C���X�^���X�̍폜*/
	static void DeleteInstance()
	{
		//�C���X�^���X��null����Ȃ�������
		if (instance != nullptr)
		{
			//�C���X�^���X���J�����āAnull����������
			delete(instance);
			instance = nullptr;
		}
	}

	void Init();
private:
	/*���������֐�*/
	SetUpScreen();

	/*�����o�ϐ�*/
	static SetUpScreen* instance;//�B��̃C���X�^���X
};

