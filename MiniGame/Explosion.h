//========================================================
// @brief �����G�t�F�N�g�N���X
// �Q�W���̉摜��؂�ւ��ĕ`��
//========================================================
#pragma once
class Explosion
{
public:
	Explosion();//�R���X�g���N�^
	~Explosion();//�f�X�g���N�^

	void		Init	();		//������
	void		Update	();		//�X�V
	const void	Draw	()const;//�`��
private:

	WrapVECTOR pos;
	float imageSize;
	vector<int> imageHandle;//�摜�n���h��
	int drawFrameCount;//�`��p�t���[���J�E���g�i�`�悪�J�n���ꂽ�Ƃ��Ɍv�����J�n���A�萔�Ŋ������]�肪�O�̎��ɕ`��摜��؂�ւ���j
	int nowDrawImage;//���ݕ`�撆�̉摜
};

