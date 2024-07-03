#include "Common.h"

JsonManager* JsonManager::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
JsonManager::JsonManager()
{
	LoadJsonFile();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
JsonManager::~JsonManager()
{

}

/// <summary>
/// json�t�@�C���̓ǂݍ���
/// </summary>
void JsonManager::LoadJsonFile()
{
	/*json�ǂݍ��݃N���X�̃C���X�^���X���擾*/
	auto& loader = JsonLoader::GetInstance();

	/*�t�@�C���̖��O��ێ����Ă���Json�t�@�C����ǂݍ���*/
	this->baseJson = loader.GetJsonData("Data/Json/LoadJsonFile.json");

	/*�ǂݍ��񂾃t�@�C���̃f�[�^��ێ�*/
	std::vector<std::string> fileName = this->baseJson["FILE_NAME"];

	/*�ێ������f�[�^�̗v�f���������[�v����*/
	for (int i = 0; i < fileName.size(); i++)
	{
		//�Ή�����t�@�C������json��ǂݍ��݁A�ێ�����
		this->json.push_back(loader.GetJsonData(fileName[i]));
	}
}