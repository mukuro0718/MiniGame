//===============================================
// @brief �����蔻�茋�ʃN���X
// �����蔻��̌��ʂ�ێ�����
//===============================================
#pragma once

class WrapVECTOR;
class HitResult
{
public:
	HitResult();	//�R���X�g���N�^
	~HitResult();	//�f�X�g���N�^
	bool		isHit;	//�����蔻��
	WrapVECTOR	fixVec;	//
};

