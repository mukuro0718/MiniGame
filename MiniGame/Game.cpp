#include"Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Game::Game()
	: alpha(MAX_ALPHA)
	, isGameCrear(false)
	, isGameOver(false)
	, color(0)
{
	Init();
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
void Game::Init()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& weapon = WeaponManager::GetInstance();
	auto& amo = AmoManager::GetInstance();
	auto& gem			= GemManager		::GetInstance();
	auto& character = CharacterManager::GetInstance();
	auto& input = InputManager::GetInstance();
	auto& timer = GameTimer::GetInstance();
	auto& backGround = BackGround::GetInstance();
	auto& ui = UIManager::GetInstance();
	auto& effect = EffectManager::GetInstance();
	auto& stage = StageManager::GetInstance();
	auto& sound = Sound::GetInstance();

	/*����������*/
	sound.Init();
	sound.OnIsPlayBGM();
	timer.Init();
	backGround.Init();
	effect.Init();
	character.Init();
	weapon.Init();
	amo.Init();
	stage.Init();
	gem		.InitUseGem();
	ui.Init();
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
	auto& gem			= GemManager		::GetInstance();
	auto& character	= CharacterManager	::GetInstance();
	auto& input			= InputManager		::GetInstance();
	auto& timer			= GameTimer			::GetInstance();
	auto& backGround		= BackGround		::GetInstance();
	auto& ui				= UIManager			::GetInstance();
	auto& effect		= EffectManager		::GetInstance();
	auto& sound = Sound::GetInstance();
	
	/*�X�V����*/
	timer		.Update();
	backGround	.Update();
	camera		.Update();
	stage		.Update();
	effect		.Update();
	character	.Update();
	weapon		.Update();
	amo			.Update();
	gem			.Update();
	ui			.Update();
	sound		.PlayBGM();
	

	if (timer.GetElapsetTime() >= 120)
	{
		this->isGameCrear = true;
		this->color = GetColor(255, 255, 255);
	}
	else if (character.GetPlayerIsHit())
	{
		this->isGameOver = true;
		this->color = GetColor(0, 0, 0);
	}

	if ((this->isGameOver && character.GetPlayerPos().value.y <= -50.0f) || this->isGameCrear)
	{
		this->alpha += 2;
	}
	else
	{
		if (this->alpha > 0)
		{
			this->alpha -= 2;
		}
	}

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
	auto& gem			= GemManager		::GetInstance();
	auto& character = CharacterManager::GetInstance();
	auto& backGround = BackGround::GetInstance();
	auto& ui = UIManager::GetInstance();
	auto& effect = EffectManager::GetInstance();
	auto& timer = GameTimer::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonFileNum = static_cast<int>(JsonManager::FileNameType::SET_UP_SCREEN);

	/*�`��*/
	timer		.Draw();
	backGround	.Draw();
	stage		.Draw();
	weapon		.Draw();
	gem			.Draw();
	amo			.Draw();
	effect		.Draw();
	character	.Draw();
	ui			.Draw();

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->alpha);
	DrawBox(0, 0, json.GetJson(jsonFileNum)["WINDOW_WIDTH"], json.GetJson(jsonFileNum)["WINDOW_HEIGHT"], this->color, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}
/// <summary>
/// �I������
/// </summary>
void Game::EndProcess()
{
	/*�C���v�b�g�}�l�[�W���[�̃C���X�^���X���擾*/
	auto& input = InputManager::GetInstance();


	/*�G���^�[�L�[�i���PAD�Ή�������j�������ꂽ��V�[����؂�ւ���*/
	if (input.GetReturnKeyState() || this->alpha >= this->MAX_ALPHA)
	{
		auto& changer = SceneChanger::GetInstance();
		changer.ChangeScene(SceneChanger::SceneType::RESULT);
	}
}
