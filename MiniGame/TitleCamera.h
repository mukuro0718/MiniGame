#pragma once
//===========================================
// @brief �^�C�g���J�����N���X
//===========================================
#pragma once
#include "Object.h"

class WrapVECTOR;
class TitleCamera : public Object
{
public:
	TitleCamera();//�R���X�g���N�^
	~TitleCamera();//�f�X�g���N�^

	void Init()		override;//������
	void Update()	override;//�X�V
private:
	/*�����o�ϐ�*/
	WrapVECTOR pos;			//�J�������W
	WrapVECTOR targetPos;	//�^�[�Q�b�g���W
};

