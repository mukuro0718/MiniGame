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
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto&stage			= StageManager		::GetInstance();
	auto&camera			= CameraManager		::GetInstance();
	auto&weapon			= WeaponManager		::GetInstance();
	auto&amo				= AmoManager		::GetInstance();
	//auto& gem			= GemManager		::GetInstance();
	auto& character	= CharacterManager	::GetInstance();
	auto& input			= InputManager		::GetInstance();
	auto& timer			= GameTimer			::GetInstance();
	auto& backGround		= BackGround		::GetInstance();
	auto& ui				= UIManager			::GetInstance();
	auto& effect		= EffectManager		::GetInstance();
	
	/*�X�V����*/
	timer		.Update();
	backGround	.Update();
	camera		.Update();
	stage		.Update();
	effect		.Update();
	character	.Update();
	weapon		.Update();
	amo			.Update();
	//gem		.Update();
	ui			.Update();
	
	

}
/// <summary>
/// �`��
/// </summary>
void Game::Draw()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& stage = StageManager::GetInstance();
	auto& weapon = WeaponManager::GetInstance();
	auto& amo = AmoManager::GetInstance();
	//auto& gem			= GemManager		::GetInstance();
	auto& character = CharacterManager::GetInstance();
	auto& backGround = BackGround::GetInstance();
	auto& ui = UIManager::GetInstance();
	auto& effect = EffectManager::GetInstance();
	auto& timer = GameTimer::GetInstance();

	/*�`��*/
	clsDx();
	printfDx("GAME");
	timer		.Draw();
	backGround	.Draw();
	stage		.Draw();
	weapon		.Draw();
	amo			.Draw();
	character	.Draw();
	ui			.Draw();
	effect		.Draw();
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
