#include"Common.h"

/// <summary>
/// コンストラクタ
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
/// デストラクタ
/// </summary>
Game::~Game()
{

}
/// <summary>
/// 更新
/// </summary>
void Game::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
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

	/*初期化処理*/
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
/// 更新
/// </summary>
void Game::Update()
{
	/*シングルトンクラスのインスタンスの取得*/
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
	
	/*更新処理*/
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
/// 描画
/// </summary>
void Game::Draw()
{
	/*シングルトンクラスのインスタンスの取得*/
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

	/*描画*/
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
/// 終了処理
/// </summary>
void Game::EndProcess()
{
	/*インプットマネージャーのインスタンスを取得*/
	auto& input = InputManager::GetInstance();


	/*エンターキー（後でPAD対応させる）が押されたらシーンを切り替える*/
	if (input.GetReturnKeyState() || this->alpha >= this->MAX_ALPHA)
	{
		auto& changer = SceneChanger::GetInstance();
		changer.ChangeScene(SceneChanger::SceneType::RESULT);
	}
}
