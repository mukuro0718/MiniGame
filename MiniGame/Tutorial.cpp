#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Tutorial::Tutorial()
{

}

/// <summary>
/// デストラクタ
/// </summary>
Tutorial::~Tutorial()
{

}

/// <summary>
/// 更新
/// </summary>
void Tutorial::Update()
{
	clsDx();
	printfDx("Tutorial");

	/*終了処理*/
	EndProcess();
}

/// <summary>
/// 終了処理
/// </summary>
void Tutorial::EndProcess()
{
	/*インプットマネージャーのインスタンスを取得*/
	auto& input = InputManager::GetInstance();

	/*エンターキー（後でPAD対応させる）が押されたらシーンを切り替える*/
	if (input.GetReturnKeyState())
	{
		auto& changer = SceneChanger::GetInstance();
		changer.ChangeScene(SceneChanger::SceneType::GAME);
	}
}
