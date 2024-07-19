#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Tutorial::Tutorial()
	: fontHandle(-1)
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& asset = LoadingAsset::GetInstance();
	this->fontHandle = asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI_3));
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
	/*シングルトンクラスのインスタンスの取得*/
	auto& backGround = BackGround::GetInstance();

	/*更新*/
	backGround.Update();

}

/// <summary>
/// 描画
/// </summary>
void Tutorial::Draw()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& backGround = BackGround::GetInstance();

	/*描画*/
	backGround.Draw();
	DrawStringToHandle(0, 0, "あなたは家に帰る途中です！\n無事に家に帰ってください！\n", GetColor(255, 255, 255), this->fontHandle);
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
