//================================================================
// @brief ��ΊǗ��N���X
//================================================================
#pragma once
#include <cassert>

class Gem;
class GemManager
{
public:
	virtual ~GemManager();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new GemManager();
	}

	/*�C���X�^���X�̎擾*/
	static GemManager& GetInstance()
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

	void Update();//�X�V
private:
	/*���������֐�*/
	GemManager(); //�R���X�g���N�^

	/*�����o�ϐ�*/
	static GemManager*	instance;	//�B��̃C���X�^���X
	vector<Gem*>		gem;		//���
};


