//========================================
// �e�N���X
// �v���C���[�ƃG�l�~�[�ɑ΂��Ċۉe�̕`����s��
//========================================

#pragma once
class Shadow
{
public:
	Shadow();	//�R���X�g���N�^
	~Shadow();	//�f�X�g���N�^
	void Final();//�ŏI����
	void Draw(const int _stageModelHandle, const VECTOR _targetPos, const float _shadowHeight, const float _shadowSize);//�e��`��
private:
	int imageHandle;//�e�摜�n���h��
};

