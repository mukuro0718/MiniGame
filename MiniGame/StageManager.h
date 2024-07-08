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
	void		Init	();		//������
	void		Update	();		//�X�V
	const void	Draw	()const;//�`��
private:
	/*�񋓑�*/
	enum class BuildingType
	{
		A = 0,
		B = 1,
		C = 2,
		D = 3,
		E = 4,
		F = 5,
		G = 6,
		H = 7,
	};

	/*���������֐�*/
	StageManager();				//�R���X�g���N�^
	void CreateRoad();			//���̍쐬
	void CreateBuilding();		//�����̍쐬
	void CreateBase();			//�����̃x�[�X�̍쐬
	void SetMoveBuildingType();	//�ړ����錚���̐ݒ�

	/*�����o�ϐ�*/
	static StageManager*	instance;	//�B��̃C���X�^���X
	vector<GameStage*>		frontRoad;	//�O�̓�
	vector<GameStage*>		backRoad;	//���̓�
	vector<GameStage*>		frontBase;	//�O�̓�
	vector<GameStage*>		backBase;	//���̓�
	Skydome*				skydome;	//�X�J�C�h�[��
	vector<Building*>		building;	//����
};

