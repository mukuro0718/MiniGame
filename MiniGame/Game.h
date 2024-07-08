//=======================================
// @brief �Q�[���N���X
//=======================================
#pragma once
#include "SceneBase.h"

class Game : public SceneBase
{
public:
	Game();		//�R���X�g���N�^
	~Game();	//�f�X�g���N�^

	void Init		();			//������
	void Update		()override;	//�X�V
	void Draw		()override;	//�`��
	void EndProcess	()override;	//�I������
private:
	/*�ÓI�萔*/
	static constexpr int MAX_ALPHA = 255;

	/*�����o�ϐ�*/
	int alpha;
	bool isEnd;
};

