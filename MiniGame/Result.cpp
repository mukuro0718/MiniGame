#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Result::Result()
{

}

/// <summary>
/// デストラクタ
/// </summary>
Result::~Result()
{

}

/// <summary>
/// 更新
/// </summary>
void Result::Update()
{
	clsDx();
	printfDx("Result");

	/*終了処理*/
	EndProcess();
}

/// <summary>
/// 終了処理
/// </summary>
void Result::EndProcess()
{
	/*インプットマネージャーのインスタンスを取得*/
	auto& input = InputManager::GetInstance();

	/*エンターキー（後でPAD対応させる）が押されたらシーンを切り替える*/
	if (input.GetReturnKeyState())
	{
		auto& changer = SceneChanger::GetInstance();
		changer.ChangeScene(SceneChanger::SceneType::TITLE);
	}
}
