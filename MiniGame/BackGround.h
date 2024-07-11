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
	//�摜�̎��
	enum class ImageType
	{
		TITLE_IMAGE,
		CLOUD,
	};

	/*�ÓI�萔*/
	static constexpr int MAX_ALPHA = 255;

	/*���������֐�*/
	BackGround();			//�R���X�g���N�^
	void Move();
	void ChangeCloudInfo(const int _index);//�w�i�̕ύX
	void UpdateAlpha();
	int GetRandom(const int _range, const bool _isSign,const int _offset);//�����_���l�̎擾

	/*�����o�ϐ�*/
	static BackGround*	instance;		//�B��̃C���X�^���X
	std::vector<Vec2d>	cloudPos;		//�`����W
	std::vector<Vec2d>	cloudSize;		//�摜�T�C�Y
	std::vector<int>	cloudVelocity;	//�ړ����x
	vector<int>			imageHandle;	//�摜�n���h��
	bool				isEraseImage;	//�摜��������
	int					alpha;			//�A���t�@
};

