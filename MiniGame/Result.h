//=============================================
// @brief ���U���g�V�[��
//=============================================
#pragma once
#include "SceneBase.h"

class Transform;
class WrapVECTOR;
class Result : public SceneBase
{
public:
	Result();	//�R���X�g���N�^
	~Result();	//�f�X�g���N�^

	void Update		()override;//�X�V
	void Draw		()override;//�`��
	void EndProcess	()override;//�I������
private:
	/*�񋓑́E�\����*/
	//�t�H���g�̎��
	enum class FontType
	{
		OVER   = 0,
		CLEAR  = 1,
		BUTTON = 2,
	};
	//���f���̎��
	enum class ModelType
	{
		CAR = 0,
		HOUSE = 1,
	};
	struct Vec2d
	{
		int x = 0;
		int y = 0;
	};
	/*�ÓI�萔*/
	static constexpr int MAX_ALPHA = 255;
	static constexpr int EXPLOSIONT_SIZE = 400;
	static const int COLOR_BLACK;
	static const int COLOR_WHITE;

	/*���������֐�*/
	void UpdateGameOver	();
	void DrawScore();
	void DrawGameOver	();
	void DrawGameClear	();
	void UpdateButtonAlpha();
	void Create();
	void SetTransform();
	void SetText();
	void InitSmoke();
	Vec2d Convert(const vector<int> _in);
	void SetSmoke(const int _index);
	int GetRandom(const int _range, const bool _isSign,const int _offset);
	void UpdateSmoke();

	/*�����o�ϐ�*/
	vector<Transform>	transform;			//�g�����X�t�H�[��
	vector<Vec2d>		textPos;			//�e�L�X�g���W
	vector<int>			fontHandle;			//�t�H���g�n���h��
	vector<int>			explosionHandle;	//�����摜�n���h��
	vector<int>			modelHandle;		//���f���n���h��
	WrapVECTOR			explosionPos;		//�����`����W
	bool				isGameOver;			//�Q�[���I�[�o�[�t���O
	bool				isGameClear;		//�Q�[���N���A�t���O
	bool				isEnd;				//�V�[���I���t���O
	bool				isAddAlpha;			//���ǉ��t���O
	bool				isExplosion;		//�����t���O
	bool				isDrawClearText;	//�N���A�����̕`��
	bool				isShowScore;		//�X�R�A�̕\��
	int					textColor;			//�e�L�X�g�J���[
	int					transitionAlpha;	//�J�ڃ�
	int					color;				//�F
	int					explosionIndex;		//�����C���f�b�N�X
	int					explosionFrameCount;//�����t���[����
	int					smokeHandle;		//���摜�n���h��
	int					buttonAlpha;		//�{�^���p��
	vector<WrapVECTOR>	smokeMoveVec;
	vector<WrapVECTOR>  smokePos;
	vector<float>		smokeVelocity;
	vector<int>			smokeSize;
	int					showScoreFrameCount;
};

