#pragma once
#include "Enemy.h"

class Boss : public Enemy
{
public:
	Boss(const int _modelHandle, const vector<float> _movePos);	//�R���X�g���N�^
	~Boss();													//�f�X�g���N�^

	void Init()				override;//������
	void Update()			override;//�X�V
	void ChangeFlagsState()	;//�t���O�̏�Ԃ�ύX

private:
	/*�񋓑�*/
	//��Ԃ̎��
	enum class StateType
	{
		MOVE = 0,//�ړ�
		ATTACK = 1,//�U��
		DEATH = 2,//���S
	};
	/*�ÓI�萔*/

	/*���������֐�*/
	void UpdateVelocity();	//���x�̍X�V
	float RandomY();	//�W�����v�͂̍X�V

	/*�����o�ϐ�*/
	float velocity;	//�ړ����x
	StateType state;//���
};

