//=======================================
// @brief �V�[���}�l�[�W���[�N���X
// �V�[���̊Ǘ����s��
//=======================================
#pragma once
#include <cassert>

class SceneBase;
class FPSController;
class LoadScene;
class SceneManager final
{
public:
	virtual ~SceneManager();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new SceneManager();
	}

	/*�C���X�^���X�̎擾*/
	static SceneManager& GetInstance()
	{
		//�C���X�^���X��null���������O�𔭐�������
		assert(instance != nullptr);
		return *instance;
	}

	/*�C���X�^���X�̍폜*/
	static void DeleteInstance()
	{
		//�����C���X�^���X��null����Ȃ�������
		if (instance != nullptr)
		{
			//�C���X�^���X���J�����Anull��������
			delete(instance);
			instance = nullptr;
		}
	}

	void Update();//�X�V
private:
	/*���������֐�*/
	SceneManager();//�R���X�g���N�^
	void SceneChange();//�V�[���̕ύX

	/*�����o�ϐ�*/
	static SceneManager* instance;//�B��̃C���X�^���X
	SceneBase*		scene;//�V�[���C���X�^���X
	FPSController*  fps;//fps�R���g���[���[
	LoadScene*		load;
};

