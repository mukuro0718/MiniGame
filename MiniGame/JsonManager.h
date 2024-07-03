//================================================================
// @brief json�Ǘ��N���X
// JsonLoader�N���X���g�p����Json�t�@�C����ǂݍ��ݕێ�����
//================================================================
#pragma once
#include<cassert>

class JsonManager
{
public:
	virtual ~JsonManager();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new JsonManager();
	}

	/*�C���X�^���X�̎擾*/
	static JsonManager& GetInstance()
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

	/*json�t�@�C���̓ǂݍ���*/
	void LoadJsonFile();

	/*�t�@�C���̎��*/
	enum class FileNameType
	{
		STAGE			= 0,	//�X�e�[�W
		FONT_PATH		= 1,	//�t�H���g
		FPS_CONTROLLER	= 2,	//FPS
		LOAD_SCENE		= 3,	//���[�h�V�[��
		MODEL_PATH		= 4,	//���f��
		PLAYER			= 5,	//�v���C���[
		SCENE_CHANGER	= 6,	//�V�[���`�F���W���[
		SET_UP_SCREEN	= 7,	//�X�N���[���ݒ�
		CAMERA			= 8,	//�J����
		IRON_BAR		= 9,	//�S�_
		IMAGE_PATH		= 10,	//�摜
		SKYDOME			= 11,	//�X�J�C�h�[��
		TIMER			= 12,	//�^�C�}�[
		BACKGROUND		= 13,	//�w�i
		ENEMY			= 14,	//�G�l�~�[
		WEAPON			= 15,	//����
		AMO				= 16,	//�e
		UI				= 17,	//UI
		GEM				= 18,	//���
	};

	/*json�f�[�^��getter*/
	const int GetFileNameType(const FileNameType _index)const { return static_cast<int>(_index); }
	const json GetJson(const int _index) { return json[_index]; }
private:
	/*���������֐�*/
	JsonManager(); //�R���X�g���N�^

	/*�����o�ϐ�*/
	static JsonManager* instance;//�B��̃C���X�^���X
	std::vector<json> json;
	nlohmann::json baseJson;
};

