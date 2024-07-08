#include "Common.h"

SceneManager* SceneManager::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
SceneManager::SceneManager()
	:scene(nullptr)
{
	this->scene		= new Title();
	this->fps		= new FPSController();
	this->load		= new LoadScene();
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
SceneManager::~SceneManager()
{

}
/// <summary>
/// �X�V
/// </summary>
void SceneManager::Update()
{
	if (GetASyncLoadNum() == 0)
	{
		/*�C���v�b�g�}�l�[�W���[�̃C���X�^���X���擾*/
		auto& input = InputManager::GetInstance();

		/*�C���v�b�g�}�l�[�W���[�̍X�V*/
		input.Update();

		/*�V�[���̍X�V*/
		this->scene->Update();

		/*�V�[���̕`��*/
		ClearDrawScreen();
		this->scene->Draw();

		/*�V�[���̏I������*/
		this->scene->EndProcess();

		/*�V�[���̕ύX*/
		SceneChange();

		/*�e�o�r�̕��ς��Z�o*/
		this->fps->Ave();

		/*fps�̕`��*/
		this->fps->Draw();

		/*�e�o�r�̏���*/
		this->fps->Wait();

		/*����ʂ̓��e��\�ɔ��f������*/
		ScreenFlip();
	}
	else
	{
		this->load->Update();
		this->load->Draw();
	}
}
/// <summary>
/// �V�[���̕ύX
/// </summary>
void SceneManager::SceneChange()
{
	/*�V�[���`�F���W���[�N���X�̃C���X�^���X���擾*/
	auto& changer = SceneChanger::GetInstance();

	/*�������݂̃V�[���^�C�v�ƑO�̃V�[���^�C�v���قȂ��Ă����珈�����s��*/
	if (changer.GetNowSceneType() != changer.GetNextSceneType())
	{
		//�V�[���^�C�v�ɂ���č쐬����C���X�^���X��ς���
		switch (changer.GetNextSceneType())
		{
		case SceneChanger::SceneType::TITLE:
			delete(this->scene);
			this->scene = new Title();
			break;
		case SceneChanger::SceneType::GAME:
			delete(this->scene);
			this->scene = new Game();
			break;
		case SceneChanger::SceneType::RESULT:
			delete(this->scene);
			this->scene = new Result();
			break;
		}
		//�V�[���𓯊�������
		changer.SynchroScene();
	}
}
