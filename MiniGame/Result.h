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

};

