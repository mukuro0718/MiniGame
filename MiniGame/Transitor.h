//=========================================
// @brief �V�[���J�ڎ����o�N���X
// �Q�l�Fhttps://qiita.com/tsuchinokoman/items/b6d7f500ab0d05478a2c#transitor%E5%9F%BA%E5%BA%95%E3%82%AF%E3%83%A9%E3%82%B9
//=========================================
#pragma once
/// <summary>
/// �V�[���J�ڎ����o���N���X
/// </summary>
class Transitor
{
protected:
	const int interval_;//�؂�ւ��ɂ����鎞��
	int frame_ = 0;//�J�n���猻�݂܂ł̃t���[����
	int oldRT_ = 0;//�؂�ւ��O�̉��
	int newRT_ = 0;//�؂�ւ���̉��
public:
	Transitor(int interval = 60) : interval_(interval) {}
	virtual ~Transitor();
	void Start();//���o�J�n
	virtual void Update() = 0;//Scene::Update�̍Ō�ɌĂ�ł�
	virtual void Draw() = 0;//Scene::Draw�̍Ō�ɌĂ�ł�
	virtual bool IsEnd()const;//���o���I������
};

