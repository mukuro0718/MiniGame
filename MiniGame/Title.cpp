#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Title::Title()
	: imageHandle(-1)
	, fontHandle(-1)
	, alpha(MAX_ALPHA)
	, isEnd(false)
	, sizeOffset(0)
	, isAdd(true)
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& asset = LoadingAsset::GetInstance();
	auto& backGround = BackGround::GetInstance();
	backGround.Init();

	this->fontHandle = asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI_2));
	this->imageHandle = asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::A_BUTTON));
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
	/*シングルトンクラスのインスタンスの取得*/
	auto& backGround = BackGround::GetInstance();	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::SCENE);

	backGround.Update();
	if (this->isAdd)
	{
		sizeOffset++;
		if (sizeOffset >= json.GetJson(jsonIndex)["TITLE_A_SIZE_OFFSET"])
		{
			this->isAdd = false;
		}
	}
	else
	{
		sizeOffset--;
		if (sizeOffset <= 0)
		{
			this->isAdd = true;
		}
	}

	if (!this->isEnd)
	{
		if (this->alpha > 0)
		{
			this->alpha -= 2;
		}
	}
	else
	{
		this->alpha += 2;
		if (this->alpha >= this->MAX_ALPHA)
		{
			this->alpha = this->MAX_ALPHA;
		}
	}
}

/// <summary>
/// 描画
/// </summary>
void Title::Draw()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& backGround = BackGround::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::SCENE);
	int jsonIndex2 = static_cast<int>(JsonManager::FileNameType::SET_UP_SCREEN);

	ClearDrawScreen();
	backGround.Draw();
	DrawStringToHandle(json.GetJson(jsonIndex)["TITLE_LOGO_X"], json.GetJson(jsonIndex)["TITLE_LOGO_Y"], "いつもとちがう\n　　　帰り道", GetColor(255, 255, 255), this->fontHandle);
	const int x = json.GetJson(jsonIndex)["TITLE_A_BUTTON_X"];
	const int y = json.GetJson(jsonIndex)["TITLE_A_BUTTON_Y"];
	const int size = json.GetJson(jsonIndex)["TITLE_A_SIZE"];
	DrawExtendGraph(x - this->sizeOffset, y - this->sizeOffset, x + size + this->sizeOffset, y + size + this->sizeOffset, this->imageHandle, TRUE);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->alpha);
	DrawBox(0, 0, json.GetJson(jsonIndex2)["WINDOW_WIDTH"], json.GetJson(jsonIndex2)["WINDOW_HEIGHT"], GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

}

/// <summary>
/// 終了処理
/// </summary>
void Title::EndProcess()
{
	/*インプットマネージャーのインスタンスを取得*/
	auto& input = InputManager::GetInstance();
	
	if (input.GetReturnKeyState() || input.GetPadState() & PAD_INPUT_2)
	{
		this->isEnd = true;
	}

	/*エンターキー（後でPAD対応させる）が押されたらシーンを切り替える*/
	if (this->isEnd && this->alpha >= this->MAX_ALPHA)
	{
		auto& changer = SceneChanger::GetInstance();
		changer.ChangeScene(SceneChanger::SceneType::GAME);
	}
}
