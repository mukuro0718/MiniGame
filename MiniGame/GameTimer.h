//======================================================
// @brief �^�C�}�[�N���X
// �����̎��Ԃł͂Ȃ��A�U�O�t���[�������������_�łP�b�Ƃ���
//======================================================
#pragma once
#include <cassert>
class GameTimer
{
public:
	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new GameTimer();
	}
	
	/*�C���X�^���X�̎擾*/
	static GameTimer& GetInstance()
	{
		assert(instance != nullptr);
		return *instance;
	}

	/*�C���X�^���X�̉��*/
	static void DeleteInstance()
	{
		if (instance != nullptr)
		{
			delete(instance);
			instance = nullptr;
		}
	}

	/*���̑��֐�*/
	virtual ~GameTimer();	//�f�X�g���N�^
	void	Update();		//�X�V
	void	Init();			//������
	const void Draw()const;	//�`��

	/*getter*/
	const int GetElapsetTime	()const { return this->elapsetTime; }
	const int GetElapsetFrame	()const { return this->elapsetFrame; }
private:
	/*���������֐�*/
	GameTimer();	//�R���X�g���N�^

	/*�����o�ϐ�*/
	static GameTimer* instance;//�B��̃C���X�^���X
	int elapsetTime;//�o�ߎ���
	int elapsetFrame;//�o�߃t���[��
};

