#pragma once
#include "Object.h"
class Skydome : public Object
{
public:
	Skydome(const int _modelHandle);	//�R���X�g���N�^
	~Skydome();	//�f�X�g���N�^
	void Init()override;	//������
	void Update()override;	//�X�V
private:
	/*���������֐�*/
	const void Draw()const;

	/*�����o�ϐ�*/
	int modelHandle;//���f���̃n���h��
};


