//====================================================
// @brief �l�iUI�N���X
//====================================================
#pragma once

class Operation final
{
public:
	Operation(const int _fontHandle);//�R���X�g���N�^
	~Operation();//�f�X�g���N�^

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

