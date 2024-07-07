//================================================================
// @brief �G�t�F�N�g�}�l�[�W���[�N���X
//================================================================
#pragma once
#include <cassert>

class Jet;
class Explosion;
class EffectManager
{
public:
	virtual ~EffectManager();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new EffectManager();
	}

	/*�C���X�^���X�̎擾*/
	static EffectManager& GetInstance()
	{
		//�C���X�^���X��null�̎��A��O�𔭐�������
		assert(instance != nullptr);
		return *instance;
	}

	/*�C���X�^���X�̍폜*/
	static void DeleteInstance()
	{
		//�����C���X�^���X��null����Ȃ�������
		if (instance != nullptr)
		{
			//�C���X�^���X���J�����Anull�ŏ���������
			delete(instance);
			instance = nullptr;
		}
	}

	void Update();
private:
	/*���������֐�*/
	EffectManager();	 //�R���X�g���N�^

	/*�����o�ϐ�*/
	static EffectManager*	instance;	//�B��̃C���X�^���X
	Jet*					jet;		//�W�F�b�g�G�t�F�N�g
	Explosion*				explosion;	//�����G�t�F�N�g
};

