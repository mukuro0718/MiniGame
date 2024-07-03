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
	clsDx();
	printfDx("GAME");

	/*シングルトンクラスのインスタンスの取得*/
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
	/*終了処理*/
	EndProcess();
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
