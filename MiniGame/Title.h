//=============================================
// @brief�@�^�C�g���V�[��
//=============================================
#pragma once
#include "SceneBase.h"

class Title : public SceneBase
{
public:
	Title();	//�R���X�g���N�^
	~Title();	//�f�X�g���N�^

	void Update		()override;//�X�V
	void Draw		()override;//�`��
	void EndProcess	()override;//�I������

private:
	/*�񋓑�*/
	//�摜�̎��
	enum class ImageType
	{
		TITLE_LOGO,
		PUSH_BUTTON,
	};

	static constexpr int MAX_ALPHA = 255;

	/*���������֐�*/
	const void Draw()const;//�`��

	/*�����o�ϐ�*/
	int imageHandle;
	int fontHandle;
	int alpha;
	bool isEnd;
	int sizeOffset;
	bool isAdd;
};

