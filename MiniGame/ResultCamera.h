#pragma once
//===========================================
// @brief �^�C�g���J�����N���X
//===========================================
#pragma once
#include "Object.h"

class WrapVECTOR;
class ResultCamera
{
public:
	ResultCamera();//�R���X�g���N�^
	~ResultCamera();//�f�X�g���N�^

	void Init		();//������
	void ClearUpdate();//�Q�[���N���A���X�V
	void OverUpdate	();//�Q�[���I�[�o�[���X�V
private:
	/*�����o�ϐ�*/
	WrapVECTOR pos;			//�J�������W
	WrapVECTOR targetPos;	//�^�[�Q�b�g���W
};

