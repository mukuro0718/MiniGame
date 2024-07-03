#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Title::Title()
{

}

/// <summary>
/// デストラクタ
/// </summary>
Title::~Title()
{

}

/// <summary>
/// 更新
/// </summary>
void Title::Update()
{
	clsDx();
	printfDx("TITLE");

	/*終了処理*/
	EndProcess();

}

/// <summary>
/// 終了処理
/// </summary>
void Title::EndProcess()
{
	/*インプットマネージャーのインスタンスを取得*/
	auto& input = InputManager::GetInstance();

	/*エンターキー（後でPAD対応させる）が押されたらシーンを切り替える*/
	if (input.GetReturnKeyState())
	{
		auto& changer = SceneChanger::GetInstance();
		changer.ChangeScene(SceneChanger::SceneType::TUTORIAL);
	}
}
