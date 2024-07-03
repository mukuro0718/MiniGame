#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Collision::Collision()
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
Collision::~Collision()
{

}

/// <summary>
/// ���Ƌ��̓����蔻��
/// </summary>
HitResult Collision::SphereAndSphereCollision(const Object& _in1, const Object& _in2)
{
	/*�Ԃ��l*/
	HitResult out;

	/*���S�x�N�g�����o��*/
	WrapVECTOR center1 = _in1.GetHitPosition();
	WrapVECTOR center2 = _in2.GetHitPosition();

	/*���a���o��*/
	float radius1 = _in1.GetRadius();
	float radius2 = _in2.GetRadius();

	/*���S�Ԃ̃x�N�g�����o��*/
	WrapVECTOR betweenCenterVec = center2 - center1;

	/*���S�Ԃ̃x�N�g���̃T�C�Y���o��*/
	float betweenCenterVecSize = betweenCenterVec.Size();

	/*����radius�̍��v���o��*/
	float sumRadius = radius1 + radius2;

	/*centerPos�Ԃ̃x�N�g���̃T�C�Y��radius�̍��v������������Γ������Ă���*/
	if (betweenCenterVecSize < sumRadius)
	{
		//�߂荞�ݗʂ��o��
		float pushBackValue = sumRadius - betweenCenterVecSize;
		//�����߂��������o��
		WrapVECTOR pushBackVec = center1 - center2;
		//���K��
		WrapVECTOR pushBackVecNorm = pushBackVec.Norm();
		//�߂荞�ݗʂŃX�P�[�����O
		out.fixVec = pushBackVec.Scale(pushBackValue);
		out.isHit = true;
	}


	return out;
}
