//====================================================
// @brief �I�u�W�F�N�g�x�[�X�N���X
//====================================================
#pragma once

class WrapVECTOR;
class Transform
{
public:
	Transform();			//�R���X�g���N�^
	virtual ~Transform(){}	//�f�X�g���N�^

	void showInfo(const std::string _name);//�����o�ϐ��ɕێ�����Ă���l�̕\��

	/*�����o�ϐ�*/
	WrapVECTOR pos;		//���W
	WrapVECTOR scale;	//�g�嗦
	WrapVECTOR rotate;	//��]��
};

