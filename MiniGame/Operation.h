//====================================================
// @brief �l�iUI�N���X
//====================================================
#pragma once

class Operation final
{
public:
	Operation(const int _fontHandle);//�R���X�g���N�^
	~Operation();//�f�X�g���N�^

	void		Init	();		//������
	const void	Draw	()const;//�`��

private:
	/*���������֐�*/

	/*�����o�ϐ�*/
	int fontHandle;
	vector<int> pos;
	int color;
};

