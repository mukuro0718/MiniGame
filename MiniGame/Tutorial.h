//=============================================
// @brief �`���[�g���A���V�[��
//=============================================
#pragma once
#include "SceneBase.h"

class Tutorial : public SceneBase
{
public:
	Tutorial();	//�R���X�g���N�^
	~Tutorial();	//�f�X�g���N�^

	void Update		()override;//�X�V
	void Draw		()override;//�`��
	void EndProcess	()override;//�I������
private:
	int fontHandle;
	int imageHandle;
	int movieHandle;
};

