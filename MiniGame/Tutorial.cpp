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
	this->imageHandle = asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::TUTORIAL));
	this->movieHandle = LoadGraph("Data/Movie/TutorialMovie.mp4");
	PlayMovieToGraph(movieHandle);
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
	if (GetMovieStateToGraph(this->movieHandle) == 0)
	{
		//ムービーの再生位置を0秒目に変更します
		SeekMovieToGraph(this->movieHandle, 0);
		//ムービーを再生状態にします
		PlayMovieToGraph(this->movieHandle);
	}
}

/// <summary>
/// 描画
/// </summary>
void Tutorial::Draw()
{
	DrawExtendGraph(0, 0, 1920, 1080, this->imageHandle, TRUE);
	DrawExtendGraph(100, 50, 1240, 680, this->movieHandle, FALSE);
}

/// <summary>
/// 終了処理
/// </summary>
void Tutorial::EndProcess()
{
	/*インプットマネージャーのインスタンスを取得*/
	auto& input = InputManager::GetInstance();
	auto& sound = Sound::GetInstance();

	/*エンターキー（後でPAD対応させる）が押されたらシーンを切り替える*/
	if (input.GetReturnKeyState() || input.GetPadState() & PAD_INPUT_3)
	{
		auto& changer = SceneChanger::GetInstance();
		changer.ChangeScene(SceneChanger::SceneType::GAME);
	}
}
