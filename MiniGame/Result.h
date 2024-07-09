//=============================================
// @brief ���U���g�V�[��
//=============================================
#pragma once
#include "SceneBase.h"

class Result : public SceneBase
{
public:
	Result();	//�R���X�g���N�^
	~Result();	//�f�X�g���N�^

	void Update		()override;//�X�V
	void Draw		()override;//�`��
	void EndProcess	()override;//�I������
private:
	/*�񋓑�*/
	enum class TextType
	{
		MAIN,
		OVER,
		CLEAR,
	};

	/*�ÓI�萔*/
	static constexpr int MAX_ALPHA = 255;

	/*���������֐�*/
	void GameOver();
	void GameClear();

	/*�����o�ϐ�*/
	vector<vector<int>> textPos;
	int textColor;
	int alpha;
	int color;
	bool isGameOver;
	bool isGameClear;
	bool isEnd;
	bool isNext;
	int fontHandle;
	int waitFrameCount;
	int imageHandle;
	bool isAdd;
	int sizeOffset;
	int buttonAlpha;
};

