//================================================================
// @brief ��ΊǗ��N���X
//================================================================
#pragma once
#include <cassert>

class Gem;
class GemManager
{
public:
	virtual ~GemManager();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new GemManager();
	}

	/*�C���X�^���X�̎擾*/
	static GemManager& GetInstance()
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

	void		Update			();											//�X�V
	const void	Draw			()const;									//�`��
	const int	GetUseNum		()const { return this->useCurrentlyNum; }	//�g�p���Ă��鐔��getter
	const Gem&	GetGemInstance	(const int _index)const;					//�W�F���̃C���X�^���X��getter

	const bool GetGemIsHit(const int _index)const;
	const bool GetGemIsSet(const int _index)const;
private:
	/*�񋓑�*/
	enum class PatternType
	{
		CENTER	= 0,
		BOTTOM	= 1,
		TOP		= 2,
		UP		= 3,
		DOWN	= 4,
	};

	/*���������֐�*/
	GemManager();		//�R���X�g���N�^
	void InitUseGem();	//�g�p���Ă���W�F���̏�����
	void SetUseGem();	//�g�p����W�F���̃Z�b�g

	/*�����o�ϐ�*/
	static GemManager*	instance;	//�B��̃C���X�^���X
	vector<Gem*>		gem;		//���
	Gem*				specialGem;
	int					useCurrentlyNum;
};


