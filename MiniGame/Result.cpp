#include "Common.h"

const int Result::COLOR_BLACK = GetColor(0, 0, 0);
const int Result::COLOR_WHITE = GetColor(255, 255, 255);

/// <summary>
/// コンストラクタ
/// </summary>
Result::Result()
	: transitionAlpha(MAX_ALPHA)
	, color(0)
	, isGameClear(false)
	, isGameOver(false)
	, buttonAlpha(0)
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& asset = LoadingAsset::GetInstance();
	auto& character = CharacterManager::GetInstance();
	auto& timer = GameTimer::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonIndex = static_cast<int>(JsonManager::FileNameType::SCENE);


	this->fontHandle.emplace_back(asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI_2)));
	this->fontHandle.emplace_back(asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI_2)));
	this->fontHandle.emplace_back(asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI)));
	if (timer.GetElapsetTime() >= 120)
	{
		this->color = GetColor(255, 255, 255);
		//this->textColor = GetColor(0, 0, 0);
		this->textColor = GetColor(255, 255, 255);
		this->isGameClear = true;
	}
	else if (character.GetPlayerIsHit())
	{
		this->color = GetColor(0, 0, 0);
		this->textColor = GetColor(255, 255, 255);
		this->isGameOver = true;
	}
	vector<int> overPos = json.GetJson(jsonIndex)["RESULT_GAMEOVER_TEXT_POS"];
	Vec2d addPos = { overPos[0] ,overPos[1] };
	this->textPos.emplace_back(addPos);

	vector<int> clearPos = json.GetJson(jsonIndex)["RESULT_GAMECLEAR_TEXT_POS"];
	addPos = { clearPos[0] ,clearPos[1] };
	this->textPos.emplace_back(addPos);

	vector<int> buttonPos = json.GetJson(jsonIndex)["RESULT_BUTTON_TEXT_POS"];
	addPos = { buttonPos[0] ,buttonPos[1] };
	this->textPos.emplace_back(addPos);
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
	auto& input = InputManager::GetInstance();
	auto& json = JsonManager::GetInstance();
	auto& backGround = BackGround::GetInstance();
	auto& camera = CameraManager::GetInstance();
	auto& stage = StageManager::GetInstance();
	auto& character = CharacterManager::GetInstance();
	auto& effect = EffectManager::GetInstance();
	int   jsonIndex = static_cast<int>(JsonManager::FileNameType::SCENE);

	/*更新処理*/
	if (this->isGameOver)
	{
		backGround.Update();
		camera.OverCameraUpdate();
		character.Update();
	}

	/*α値の増減*/
	if (this->isEnd)
	{
		this->transitionAlpha += json.GetJson(jsonIndex)["RESULT_ADD_TRRANSITION_ALPHA"];
	}
	else
	{
		if (this->transitionAlpha > 0)
		{
			this->transitionAlpha -= json.GetJson(jsonIndex)["RESULT_ADD_TRRANSITION_ALPHA"];
		}
	}
	UpdateButtonAlpha();
}

void Result::UpdateButtonAlpha()
{
	auto& json = JsonManager::GetInstance();
	int   jsonIndex = static_cast<int>(JsonManager::FileNameType::SCENE);
	/*α値の増減*/
	if (this->isAddAlpha)
	{
		this->buttonAlpha += json.GetJson(jsonIndex)["RESULT_ADD_BUTTON_ALPHA"];
		if (this->buttonAlpha >= this->MAX_ALPHA)
		{
			this->isAddAlpha = false;
		}
	}
	else
	{
		this->buttonAlpha -= json.GetJson(jsonIndex)["RESULT_ADD_BUTTON_ALPHA"];
		if (this->buttonAlpha < 0)
		{
			this->isAddAlpha = true;
		}
	}
}
/// <summary>
/// 描画
/// </summary>
void Result::Draw()
{
	auto& json		 = JsonManager		::GetInstance();
	auto& stage		 = StageManager		::GetInstance();
	auto& character	 = CharacterManager ::GetInstance();
	auto& backGround = BackGround		::GetInstance();
	int   jsonIndex	 = static_cast<int>(JsonManager::FileNameType::SET_UP_SCREEN);
	int fontIndex = 0;
	if (this->isGameOver)
	{
		DrawGameOver();
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->transitionAlpha);
	DrawBox(0, 0, json.GetJson(jsonIndex)["WINDOW_WIDTH"], json.GetJson(jsonIndex)["WINDOW_HEIGHT"], this->color, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, this->MAX_ALPHA);
}

void Result::DrawGameOver()
{
	auto& stage		 = StageManager::GetInstance();
	auto& character  = CharacterManager::GetInstance();
	auto& backGround = BackGround::GetInstance();
	int   fontIndex  = 0;

	backGround.Draw();
	stage.Draw();
	character.Draw();
	fontIndex = static_cast<int>(FontType::OVER);
	DrawStringToHandle(this->textPos[fontIndex].x, this->textPos[fontIndex].y, "GAMEOVER", this->textColor, this->fontHandle[fontIndex]);
	fontIndex = static_cast<int>(FontType::BUTTON);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->buttonAlpha);
	DrawStringToHandle(this->textPos[fontIndex].x, this->textPos[fontIndex].y, "ボタンを押す", this->textColor, this->fontHandle[fontIndex]);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, this->MAX_ALPHA);
}

/// <summary>
/// 終了処理
/// </summary>
void Result::EndProcess()
{
	/*インプットマネージャーのインスタンスを取得*/
	auto& input = InputManager::GetInstance();

	if (input.GetReturnKeyState())
	{
		this->isEnd = true;
	}

	/*エンターキー（後でPAD対応させる）が押されたらシーンを切り替える*/
	if (this->isEnd && this->transitionAlpha >= this->MAX_ALPHA)
	{
		auto& changer = SceneChanger::GetInstance();
		changer.ChangeScene(SceneChanger::SceneType::TITLE);
	}
}
