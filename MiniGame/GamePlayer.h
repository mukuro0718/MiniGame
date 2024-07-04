//==============================================
// @brief �v���C���[�N���X
// �L�����N�^�[�x�[�X�N���X���p�����A
// �������z�֐��Ɏ��Ԃ���������B
// �܂��A�v���C���[�Ǝ��̃��\�b�h��ϐ���ێ����A
// �̂��ɍ��CharacterManager�N���X�ŊǗ������B
//==============================================
#pragma once
#include "Character.h"

class GamePlayer : public Character
{
public:
	GamePlayer(const int _modelHandle);	//�R���X�g���N�^
	~GamePlayer();						//�f�X�g���N�^

	/*�p�����Ƃ̏������z�֐��Ɏ��Ԃ���������*/
	void Init()				override;//������
	void Update()			override;//�X�V
	void HitCheck()			;//�����蔻��
	void Move()				;//�ړ�
	void ChangeFlagsState()	;//�t���O�̏�Ԃ�ύX

	void CountTime();//���Ԃ̌v��
	
	/*getter*/
	const bool	GetIsStan()		const { return this->isStun; }		//�C��t���O��getter
	const float	GetHeight()		const { return this->height; }		//������getter
	const int	GetAliveTime()	const { return this->aliveTime; }	//�������Ԃ�getter
	const int	GetPrice()		const { return this->price; }		//���i��getter
	/*�t���O�𗧂Ă�*/
	const void OnIsStun() { isStun = true; }//�C��t���O�𗧂Ă�
private:
	/*�\���́E�񋓑�*/
	//�A�j���[�V�����̎��
	enum class AnimType
	{
		SIT,
		IDLE,
		JUMP,
	};

	/*�����o�ϐ�*/
	float jumpPower;	//�W�����v��
	float height;		//�g��
	float floatPower;	//����
	float zAngle;		//Z�������Ƃɂ����A���O��
	
	bool isSit;
	bool isStun;		//�C�₵����
	bool isOnGround;	//�n�ʂɂ��邩
	bool isJump;		//�W�����v���Ă��邩�i�G���v���C���[�𔭌������Ƃ��ɁA�W�����v���邽�߂̂��́j

	int countStartTime;	//�v���J�n����
	int aliveTime;		//��������
	int stunFrameCount;	//�C�����������܂ł̃t���[����
	int price;
};

