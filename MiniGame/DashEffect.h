//====================================
// @brief �_�b�V���G�t�F�N�g�N���X
// �萔�������x�[�X�N���X���쐬����
//====================================
#pragma once
#include<DxLib.h>
#include<vector>
using namespace std;

class DashEffectConst;
class DashEffectBase;
class DashEffect
{
public:
	DashEffect();
	~DashEffect();

	const void Update(const bool _isRun, const VECTOR _targetPos);//�X�V
	const void Draw();	//�`��

private:
	/*�����o�ϐ�*/
	DashEffectConst* m_const;
	vector<DashEffectBase*> m_base;
	int m_nowEffectNum;
	int m_waitInitNum;
};

