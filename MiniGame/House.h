#pragma once
#include "Object.h"
class House : public Object
{
public:
	House(const int _modelHandle);	//�R���X�g���N�^
	~House();						//�f�X�g���N�^

	void		Init	()override;	//������
	void		Update	()override;	//�X�V
	const void	Draw	()const;	//�`��
private:
	/*���������֐�*/

	/*�����o�ϐ�*/
	int modelHandle;//���f���n���h��
};

