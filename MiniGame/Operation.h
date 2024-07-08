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
	void		Update	();		//�X�V
	const void	Draw	()const;//�`��

private:
	/*���������֐�*/

	/*�����o�ϐ�*/
	int fontHandle;
	vector<int> pos;
	vector<string> text;
	vector<int> endPosX;
	int moveX;
	bool isStart;
	bool isStop;
	bool isEnd;
	bool isFinish;
	int color;
	int textIndex;
	int stopFrameCount;
};

