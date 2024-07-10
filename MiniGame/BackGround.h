//======================================================
// @brief �w�i�N���X
// �S�̔w�i�����Ԍo�߂Ő؂�ւ��Ȃ���\��
// �t�F�[�h�Ő؂�ւ���
//======================================================
#pragma once
#include <cassert>

class BackGround
{
public:
	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new BackGround();
	}

	/*�C���X�^���X�̎擾*/
	static BackGround& GetInstance()
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
	virtual		~BackGround	();		//�f�X�g���N�^
	const void	Draw		()const;//�`��
	void		Init		();		//������
	void		Update		();		//�X�V
private:
	/*�\���́E�񋓑�*/
	struct Vec2d
	{
		int x = 0;
		int y = 0;
	};
	
	/*���������֐�*/
	BackGround();			//�R���X�g���N�^
	void Move();
	void ChangeBackGround();//�w�i�̕ύX
	void UpdateAlpha();
	/*�����o�ϐ�*/
	static BackGround*	instance;		//�B��̃C���X�^���X
	std::vector<int>	moveX;			//�ړ��T�C�Y
	std::vector<int>	velocity;		//�ړ����x
	std::vector<int>	imageHandle;	//�摜�n���h��
	bool				isEraseImage;	//�摜��������
	int					imageWidth;		//�摜�̉��̑傫��
	int					imageHeight;	//�摜�̏c�̑傫��
	int					alpha;			//�A���t�@
	int					maxAlpha;		//�ő�A���t�@

};

