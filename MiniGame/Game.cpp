#include"Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Game::Game()
{
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
void Game::Update()
{
	/*シングルトンクラスのインスタンスの取得*/
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
	
	/*更新処理*/
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
/// 描画
/// </summary>
void Game::Draw()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& stage = StageManager::GetInstance();
	auto& weapon = WeaponManager::GetInstance();
	auto& amo = AmoManager::GetInstance();
	//auto& gem			= GemManager		::GetInstance();
	auto& character = CharacterManager::GetInstance();
	auto& backGround = BackGround::GetInstance();
	auto& ui = UIManager::GetInstance();
	auto& effect = EffectManager::GetInstance();
	auto& timer = GameTimer::GetInstance();

	/*描画*/
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
/// 終了処理
/// </summary>
void Game::EndProcess()
{
	/*インプットマネージャーのインスタンスを取得*/
	auto& input = InputManager::GetInstance();


	/*エンターキー（後でPAD対応させる）が押されたらシーンを切り替える*/
	if (input.GetReturnKeyState())
	{
		auto& changer = SceneChanger::GetInstance();
		changer.ChangeScene(SceneChanger::SceneType::RESULT);
	}
}
