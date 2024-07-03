//================================================================
// @brief json�ǂݍ��݃N���X
// �w�肳�ꂽjson�t�@�C����ǂݍ���
//================================================================
#pragma once
#include<cassert>

// for convenience
using json = nlohmann::json;
class JsonLoader
{
public:
	virtual ~JsonLoader();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new JsonLoader();
	}

	/*�C���X�^���X�̎擾*/
	static JsonLoader& GetInstance()
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

	/*�w�肳�ꂽJson�t�@�C����ǂݍ��݃f�[�^��Ԃ�*/
	const json GetJsonData(std::string _jsonName)const;
private:
	/*���������֐�*/
	JsonLoader(); //�R���X�g���N�^

	/*�����o�ϐ�*/
	static JsonLoader* instance;//�B��̃C���X�^���X
};

