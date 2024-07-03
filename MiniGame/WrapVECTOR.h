//======================================================
// @brief WrapVECTOR�N���X
// Dxlib�Œ�`����Ă���VECTOR�N���X�����b�s���O
// �p�����Ďg�p
//======================================================
#pragma once

class WrapVECTOR
{
public:
	/*�R���X�g���N�^*/
	WrapVECTOR(const float _x, const float _y, const float _z);
	WrapVECTOR(const float _in);
	WrapVECTOR(const VECTOR _in);
	WrapVECTOR(const std::vector<float> _in);

	virtual ~WrapVECTOR(){}//�f�X�g���N�^

	/*�����o�ϐ��̑���*/
	WrapVECTOR Add(const std::vector<float> _in);					//vector<float>��ǉ����ĕԂ�
	void Convert(const std::vector<float> _in);						//vector<float>��VECTOR�ɕϊ�
	void Set(const float _x, const float _y, const float _z);		//�l��setter
	void Set(const WrapVECTOR& _in);
	float Size();													//�x�N�g���̃T�C�Y��Ԃ�
	WrapVECTOR Norm();												//���K�������x�N�g����Ԃ�
	WrapVECTOR Scale(const float _in);								//�����ŃX�P�[�����O�����l��Ԃ�
	WrapVECTOR Cross(const WrapVECTOR& _in);						//�����Ƃ̊O�ς̌��ʂ�Ԃ�
	WrapVECTOR Rotate(const WrapVECTOR& _in);						//�x�N�g���̉�]
	
	/*�p�x�����W�A���ɕϊ�*/
	float DegToRad(const float _deg);
	void DegToRad(const WrapVECTOR& _deg);

	/*���W�A�����p�x�ɕϊ�*/
	float RadToDeg(const float _rad);
	void RadToDeg(const WrapVECTOR& _rad);


	/*���`�⊮*/
	float EaseInOutQuint(const float _start, const float _end, const float _percent);
	void  EaseInOutQuint(const WrapVECTOR& _start, const WrapVECTOR& _end, const WrapVECTOR& _percent);
	
	/*operator*/
	bool operator!=(const WrapVECTOR& _in);
	WrapVECTOR operator+(const WrapVECTOR& _in);
	WrapVECTOR operator-(const WrapVECTOR& _in);
	WrapVECTOR operator+=(const WrapVECTOR& _in);
	WrapVECTOR operator-=(const WrapVECTOR& _in);
	WrapVECTOR operator*=(const WrapVECTOR& _in);

	/*�����o�ϐ�*/
	VECTOR value;//�l
};

