//========================================================
// @brief �J�j�N���X
// ���P�[�V�������C�̎��̓G
//========================================================
#pragma once
#include "Enemy.h"

class WrapVECTOR;
class Normal : public Enemy
{
public:
	Normal(const int _modelHandle, const int _breakModelHandle, const vector<float> _movePos);	//�R���X�g���N�^
	~Normal();														//�f�X�g���N�^

	void Init()				override;//������
	void Update()			override;//�X�V
	void ChangeFlagsState()	;//�t���O�̏�Ԃ�ύX

private:
	/*�񋓑�*/
	//��Ԃ̎��
	enum class StateType
	{
		MOVE	= 0,//�ړ�
		ATTACK1	= 1,//�U��
		DEATH	= 2,//���S
	};

	/*�����o�ϐ�*/
	float velocity;	//�ړ����x
	StateType state;//���
};

