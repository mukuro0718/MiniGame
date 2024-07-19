//===================================
// @brief �T�E���h�N���X
//===================================
#pragma once
#include <cassert>

class Sound
{
public:
	virtual ~Sound();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new Sound();
	}

	/*�C���X�^���X�̎擾*/
	static Sound& GetInstance()
	{
		//�C���X�^���X��null���������O�𔭐�������
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

private:
	/*���������֐�*/
	Sound();
	/*�����o�ϐ�*/
	static Sound* instance;
};

