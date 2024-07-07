//================================================================
// @brief player�Ǘ��N���X
//================================================================
#pragma once
#include <cassert>

class GamePlayer;
class Enemy;
class Transform;
class CharacterManager
{
public:
	virtual ~CharacterManager();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new CharacterManager();
	}

	/*�C���X�^���X�̎擾*/
	static CharacterManager& GetInstance()
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

	void				Init				();							//������
	void				Update				();							//�X�V
	const WrapVECTOR&	GetPlayerPos		()const;					//�v���C���[���W��getter
	const WrapVECTOR&	GetEnemyPos			(const int _index)const;	//�G�l�~�[���W��getter
	const int			GetEnemyNum			()const;					//�G�l�~�[�̐���getter
	const int			GetNowMoveEnemyNum	()const;					//���݈ړ����Ă���G�̐���getter
	const bool			GetIsShowBoss		()const;					//�{�X�����ꂽ���ǂ�����getter
	const bool			GetIsStop			(const int _index)const;	//��~�������ǂ�����getter
	const bool			GetPlayerIsHit		()const;					//�v���C���[�̓����蔻��t���O��getter
	const GamePlayer&	GetPlayerInstance	();							//�v���C���[�̃C���X�^���X��getter
	const Transform&	GetPlayerTransform	()const;					//�v���C���[�̃g�����X�t�H�[����getter
private:
	/*���������֐�*/
	CharacterManager();			//�R���X�g���N�^
	void ChangeNowMoveEnemy();	//�ғ����Ă���G�l�~�[�̕ύX

	/*�����o�ϐ�*/
	static CharacterManager*	instance;		//�B��̃C���X�^���X
	GamePlayer*					player;			//�Q�[���v���C���[
	vector<Enemy*>				enemy;			//�G�l�~�[
	int							nowMoveEnemy;	//���݉ғ����Ă���G�l�~�[�̐�
	bool isShowBoss;//�{�X�o��t���O
};

