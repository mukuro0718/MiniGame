#pragma once
#include "Object.h"

class Transform;
class Building : public Object
{
public:
	Building(const int _modelHandle);//�R���X�g���N�^
	~Building();//�f�X�g���N�^

	void		Init		()override;						//������
	void		Update		()override;						//�X�V
	const void	Draw		()const;						//�`��
	void		OnIsMove	()		{ this->isMove = true; }//�ړ��t���O�𗧂Ă�
	const bool	GetIsMove	()const { return this->isMove; }//�ړ��t���O��getter
	const void SetPos(const WrapVECTOR& _pos) { this->transform.pos = _pos; }
private:
	int modelHandle;//���f���n���h��
	bool isMove;//�ړ��t���O
};

