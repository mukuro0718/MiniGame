//=============================================
// @brief ���U���g�V�[��
//=============================================
#pragma once
#include "SceneBase.h"

class Transform;
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
	static constexpr int EXPLOSIONT_SIZE = 1920;
	static const int COLOR_BLACK;
	static const int COLOR_WHITE;

	/*���������֐�*/
	void UpdateGameOver	();
	void UpdateGameClear();
	void DrawGameOver	();
	void DrawGameClear	();
	void UpdateButtonAlpha();
	void Create();
	void SetTransform();
	void SetText();
	/*�����o�ϐ�*/
	vector<Vec2d> textPos;
	bool isGameOver;
	bool isGameClear;
	bool isEnd;
	bool isAddAlpha;
	int  textColor;
	int  transitionAlpha;
	int  color;
	vector<int>	 fontHandle;
	vector<int>	 explosionHandle;
	int explosionIndex;
	int explosionFrameCount;
	int smokeHandle;
	bool isExplosion;
	int  buttonAlpha;
	vector<int> modelHandle;
	vector<Transform> transform;
};

