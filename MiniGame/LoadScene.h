//=============================================
//���[�h��ʃN���X
//=============================================
#pragma once

class LoadScene
{
public:
	LoadScene();//�R���X�g���N�^
	~LoadScene();//�f�X�g���N�^

	void Init();//������
	void Final();//�ŏI����
	void Update();//�X�V
	void Draw();//�`��
private:
	/*�����o�ϐ�*/
	int		alpha;					//�A���t�@
	int		isIncWaitFrameCount;	//�t���[���J�E���g
	int		updateWaitFrameCount;	//�t���[���J�E���g
	bool	isIncTheValue;			//�l���������Ă��邩(TRUE:���� FALSE:���� )
};

