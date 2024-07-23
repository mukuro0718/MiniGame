//===============================================
// @brief �V�[���`�F���W���[�N���X
// �V�[���^�C�v�̕ύX�֐�������
// �V�[���̃^�C�v��ێ�
// �V���O���g���Ŏ���
//===============================================
#pragma once
#include <cassert>

class SceneChanger final
{
public:
	virtual ~SceneChanger();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance() 
	{
		instance = new SceneChanger();
	}
	/*�C���X�^���X�̎擾*/
	static SceneChanger& GetInstance()
	{
		//�C���X�^���X��null���������A��O�𔭐�������)
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
	//�V�[���^�C�v
	enum class SceneType :int
	{
		TITLE    = 0,//�^�C�g��
		GAME	 = 1,//�Q�[��
		RESULT   = 2,//���U���g
		TUTORIAL = 3,
	};

	//�V�[���̓���
	const void SynchroScene();
	const void ChangeScene(const SceneType _nextScene);
	/*getter*/
	const SceneType GetNowSceneType()const { return this->nowScene; }		//���݂̃V�[���^�C�v��getter
	const SceneType GetNextSceneType()const { return this->nextSceneType; } //���̃V�[���^�C�v��getter
private:
	/*���������֐�*/
	SceneChanger();//�R���X�g���N�^

	/*�����o�ϐ�*/
	static SceneChanger* instance;//�B��̃C���X�^���X
	SceneType nowScene;
	SceneType nextSceneType;
};

