//===========================================
// @brief �Q�[���J�����N���X
//===========================================
#pragma once
#include "Object.h"

class WrapVECTOR;
class GameCamera : public Object
{
public:
	GameCamera();//�R���X�g���N�^
	~GameCamera();//�f�X�g���N�^

	void Init()		override;//������
	void Update()	override;//�X�V
private:
	/*�����o�ϐ�*/
	WrapVECTOR pos;			//�J�������W
	WrapVECTOR targetPos;	//�^�[�Q�b�g���W
};

