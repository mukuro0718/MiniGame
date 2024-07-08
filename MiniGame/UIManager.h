//================================================================
// @brief UI�Ǘ��N���X
//================================================================
#pragma once
#include<cassert>

class Operation;
class UnderBar;
class UIManager
{
public:
	virtual ~UIManager();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new UIManager();
	}

	/*�C���X�^���X�̎擾*/
	static UIManager& GetInstance()
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
	void		Init	();		//������
	void		Update	();		//�X�V
	const void	Draw	()const;//�`��
private:
	/*���������֐�*/
	UIManager(); //�R���X�g���N�^

	/*�����o�ϐ�*/
	static UIManager* instance;//�B��̃C���X�^���X
	Operation* operation;//�l�iUI
	UnderBar* bar;//�o�[UI
};

