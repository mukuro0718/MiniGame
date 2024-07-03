//================================================================
// @brief camera�Ǘ��N���X
//================================================================
#pragma once
#include <cassert>

class GameCamera;
class CameraManager
{
public:
	virtual ~CameraManager();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new CameraManager();
	}

	/*�C���X�^���X�̎擾*/
	static CameraManager& GetInstance()
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
	CameraManager(); //�R���X�g���N�^

	/*�����o�ϐ�*/
	static CameraManager*	instance;	//�B��̃C���X�^���X
	GameCamera*				camera;		//�Q�[���J����
};

