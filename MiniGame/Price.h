//====================================================
// @brief �l�iUI�N���X
//====================================================
#pragma once

class Price final
{
public:
	Price(const int _fontHandle);//�R���X�g���N�^
	~Price();//�f�X�g���N�^

	void Init();	//������
	void Update();	//�X�V

private:
	/*���������֐�*/
	const void Draw()const;

	/*�����o�ϐ�*/
	int fontHandle;
	vector<int> pos;
	int color;
};

