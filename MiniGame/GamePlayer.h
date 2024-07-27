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
	GamePlayer(const int _modelHandle,const int _breakModelHandle, const int _characterModelHandle);	//�R���X�g���N�^
	~GamePlayer();						//�f�X�g���N�^

	/*�p�����Ƃ̏������z�֐��Ɏ��Ԃ���������*/
	void Init()				override;//������
	void Update()			override;//�X�V
	void HitCheck()			;//�����蔻��
	void Move()				;//�ړ�
	void ChangeFlagsState()	;//�t���O�̏�Ԃ�ύX

	void CountTime();//���Ԃ̌v��
	void DrawShadow();
	/*getter*/
	const bool	GetIsInput	()const { return this->isInput;	 }//A�{�^�����͂�getter
	const float	GetHeight	()const { return this->height;	 }//������getter
	const int	GetAliveTime()const { return this->aliveTime;}//�������Ԃ�getter
	const bool	GetIsHit	()const { return this->isHit;	 }//�����蔻��t���O��getter
	const bool	GetIsStop	()const { return this->isStop;	 }
	/*�t���O�𗧂Ă�*/
	const int GetPrice()const { return this->price; }

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
	float jumpPower;		//�W�����v��
	float height;			//�g��
	float floatPower;		//����
	float zAngle;			//Z�������Ƃɂ����A���O��
	
	bool isInput;			//A�{�^������
	bool isOnGround;		//�n�ʂɂ��邩
	bool isHit;				//�e��n�ʂɓ���������
	bool isStop;			//��~�t���O�i�{�^�����͂���������false�ɂ���j
	//bool isRide;//�Ԃɏ������

	int countStartTime;		//�v���J�n����
	int stunFrameCount;		//�C�����������܂ł̃t���[����
	int normalModelHandle;	
	int breakModelHandle;	//��ꂽ���f���n���h��
	int aliveTime;			//��������
	int price;				//��΂̍��v���z
	//int characterModelHandle;
	//Transform characterTransform;
};

