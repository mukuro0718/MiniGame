#include"Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Game::Game()
{
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
Game::~Game()
{
}

/// <summary>
/// �X�V
/// </summary>
void Game::Update()
{
	clsDx();
	printfDx("GAME");

	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& stage = StageManager::GetInstance();
	auto& camera = CameraManager::GetInstance();
	auto& weapon = WeaponManager::GetInstance();
	auto& amo = AmoManager::GetInstance();
	auto& character = CharacterManager::GetInstance();
	auto& input = InputManager::GetInstance();
	auto& timer = GameTimer::GetInstance();
	auto& backGround = BackGround::GetInstance();
	auto& ui = UIManager::GetInstance();

	timer.Update();
	backGround.Update();
	camera.Update();
	stage.Update();
	character.Update();
	weapon.Update();
	amo.Update();
	ui.Update();
	/*�I������*/
	EndProcess();
}

/// <summary>
/// �I������
/// </summary>
void Game::EndProcess()
{
	/*�C���v�b�g�}�l�[�W���[�̃C���X�^���X���擾*/
	auto& input = InputManager::GetInstance();


	/*�G���^�[�L�[�i���PAD�Ή�������j�������ꂽ��V�[����؂�ւ���*/
	if (input.GetReturnKeyState())
	{
		auto& changer = SceneChanger::GetInstance();
		changer.ChangeScene(SceneChanger::SceneType::RESULT);
	}
}
