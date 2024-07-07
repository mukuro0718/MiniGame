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
}

/// <summary>
/// 描画
/// </summary>
void Title::Draw()
{
	ClearDrawScreen();
	clsDx();
	printfDx("TITLE");
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
