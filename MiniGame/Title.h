//=============================================
// @brief�@�^�C�g���V�[��
//=============================================
#pragma once
#include "SceneBase.h"

class Transform;
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
		TITLE_IMAGE = 0,
	};
	//���f���̎��
	enum class ModelType
	{
		FISH_1 = 0,
		FISH_2 = 1,
		FISH_3 = 2,
		PLAYER = 3,
	};
	static constexpr int MAX_ALPHA = 255;

	/*���������֐�*/
	void		ChangeLogoSizeOffset	();//���S�T�C�Y�I�t�Z�b�g�̕ύX
	void		ChangeTransitionAlpha	();//�J�ڃA���t�@�l�̕ύX
	void		Create					();//�쐬
	void		SetTransform			();
	const void	DrawLogo				()const;
	const void	DrawTitleImage			()const;
	const void	DrawTransition			()const;

	/*�����o�ϐ�*/
	int					imageHandle;
	int					fontHandle;
	int					buttonFontHandle;
	int					alpha;
	int					logoAlpha;
	int					buttonAlpha;
	int					sizeOffset;
	bool				isEnd;
	bool				isAddButtonAlpha;
	vector<Transform>	transform;
	vector<int>			modelHandle;
};

