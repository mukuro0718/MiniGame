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
	int alpha;
	bool isEnd;
};

