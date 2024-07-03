//================================================================
// @brief �e�Ǘ��N���X
//================================================================
#pragma once
#include <cassert>

class Amo;
class AmoManager
{
public:
	virtual ~AmoManager();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new AmoManager();
	}

	/*�C���X�^���X�̎擾*/
	static AmoManager& GetInstance()
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
	/*�񋓑�*/
	enum class AmoType
	{
		NONE	= -1,
		FISH1	= 0,
		FISH2	= 1,
		FISH3	= 2,
		FISH4	= 3,
		SHARK	= 4,
	};

	/*���������֐�*/
	AmoManager(); //�R���X�g���N�^
	const int GetRandomAmoType()const;//�e�̎�ނ������_���Ŏ擾
	void InitUseCurrentlyNum();//�Ή�����ϐ��̏�����

	/*�����o�ϐ�*/
	static AmoManager*	instance;	//�B��̃C���X�^���X
	vector<vector<Amo*>>amo;		//�e
	vector<int>			useCurrentlyNum;//��vector���̉��Ԗڂ܂ł��g�p����Ă��邩
	int					prevTime;//�ȑO�̎���
	vector<int>			currentlyAmoPrice;
};


