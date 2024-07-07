//================================================================
// @brief �X�e�[�W�Ǘ��N���X
//================================================================
#pragma once
#include <cassert>

class GameStage;
class Skydome;
class StageManager
{
public:
	virtual ~StageManager();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new StageManager();
	}

	/*�C���X�^���X�̎擾*/
	static StageManager& GetInstance()
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
	const void Draw()const;//�`��
private:
	/*���������֐�*/
	StageManager(); //�R���X�g���N�^

	/*�����o�ϐ�*/
	static StageManager*	instance;	//�B��̃C���X�^���X
	vector<GameStage*>		frontRoad;	//�O�̓�
	vector<GameStage*>		backRoad;	//���̓�
	Skydome*				skydome;	//�X�J�C�h�[��
};

