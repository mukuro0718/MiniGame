//================================================================
// @brief ����Ǘ��N���X
//================================================================
#pragma once
#include <cassert>

class Weapon;
class WeaponManager
{
public:
	virtual ~WeaponManager();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new WeaponManager();
	}

	/*�C���X�^���X�̎擾*/
	static WeaponManager& GetInstance()
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

	void				Init		();						//������
	void				Update		();						//�X�V
	const void			Draw		()const;				//�`��
	const int			GetWeaponNum()const;				//����̐���getter
	const WrapVECTOR&	GetWeaponPos(const int _index)const;//����̍��W��getter

private:
	/*���������֐�*/
	WeaponManager(); //�R���X�g���N�^

	/*�����o�ϐ�*/
	static WeaponManager*	instance;	//�B��̃C���X�^���X
	vector<Weapon*>			weapon;		//�G�l�~�[
};


