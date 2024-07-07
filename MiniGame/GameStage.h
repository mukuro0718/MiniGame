//====================================
// @brief ����X�e�[�W�N���X
//====================================
#pragma once
#include "Object.h"

class GameStage : public Object
{
public:
	GameStage			(const int _modelHandle, const WrapVECTOR& _pos);	//�R���X�g���N�^
	~GameStage			();													//�f�X�g���N�^
	void		Update	()override;											//�X�V
	void		Init	()override;											//������
	const void	Draw	()const;											//�`��
private:
	/*���������֐�*/
	
	/*�����o�ϐ�*/
	WrapVECTOR	initPos;	//�������W
	int			modelHandle;//���f���n���h��
};

