#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Result::Result()
	: alpha(MAX_ALPHA)
	, color(0)
	, isGameClear(false)
	, isGameOver(false)
	, waitFrameCount(0)
	, buttonAlpha(0)
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& asset = LoadingAsset::GetInstance();
	auto& character = CharacterManager::GetInstance();
	auto& timer = GameTimer::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonIndex = static_cast<int>(JsonManager::FileNameType::SCENE);


	this->imageHandle = asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::A_BUTTON));
	this->fontHandle = asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI_3));
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
	vector<int> mainPos = json.GetJson(jsonIndex)["RESULT_MAIN_TEXT_POS"];
	this->textPos.emplace_back(mainPos);
	vector<int> overPos = json.GetJson(jsonIndex)["RESULT_GAME_OVER_TEXT_POS"];
	this->textPos.emplace_back(overPos);
	vector<int> clearPos = json.GetJson(jsonIndex)["RESULT_GAME_CLEAR_TEXT_POS"];
	this->textPos.emplace_back(clearPos);
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
	int jsonIndex = static_cast<int>(JsonManager::FileNameType::SCENE);

	if (this->isEnd)
	{
		this->alpha += 2;
	}
	else
	{
		if (this->alpha > 0)
		{
			this->alpha -= 2;
		}
		else if (this->textPos[static_cast<int>(TextType::MAIN)][1] >= json.GetJson(jsonIndex)["RESULT_MAIN_TARGET_Y"])
		{
			if (waitFrameCount >= json.GetJson(jsonIndex)["RESULT_WAIT_FRAME_COUNT"])
			{
				if (input.GetPadState() & PAD_INPUT_3)
				{
					this->textPos[static_cast<int>(TextType::MAIN)][1] -= 10;
				}
				else
				{
					this->textPos[static_cast<int>(TextType::MAIN)][1] -= 3;
				}
				if (this->textPos[static_cast<int>(TextType::MAIN)][1] < json.GetJson(jsonIndex)["RESULT_MAIN_TARGET_Y"])
				{
					waitFrameCount = 0;
				}
			}
		}
		else
		{
			if (waitFrameCount >= json.GetJson(jsonIndex)["RESULT_WAIT_FRAME_COUNT"])
			{
				if (this->isGameClear)
				{
					if (this->textPos[static_cast<int>(TextType::CLEAR)][1] >= json.GetJson(jsonIndex)["RESULT_CLEAR_TARGET_Y"])
					{
						if (input.GetPadState() & PAD_INPUT_3)
						{
							this->textPos[static_cast<int>(TextType::CLEAR)][1] -= 10;
						}
						else
						{
							this->textPos[static_cast<int>(TextType::CLEAR)][1] -= 3;
						}
						if (this->textPos[static_cast<int>(TextType::CLEAR)][1] < json.GetJson(jsonIndex)["RESULT_CLEAR_TARGET_Y"])
						{
							waitFrameCount = 0;
							this->isNext = true;
						}
					}
				}
				else if (this->isGameOver)
				{
					if (this->textPos[static_cast<int>(TextType::OVER)][1] >= json.GetJson(jsonIndex)["RESULT_OVER_TARGET_Y"])
					{
						if (input.GetPadState() & PAD_INPUT_3)
						{
							this->textPos[static_cast<int>(TextType::OVER)][1] -= 10;
						}
						else
						{
							this->textPos[static_cast<int>(TextType::OVER)][1] -= 3;
						}
						if (this->textPos[static_cast<int>(TextType::OVER)][1] < json.GetJson(jsonIndex)["RESULT_OVER_TARGET_Y"])
						{
							waitFrameCount = 0;
							this->isNext = true;
						}
					}
				}
			}
		}
	}

	if (this->isNext)
	{

		if (this->buttonAlpha < MAX_ALPHA)
		{
			this->buttonAlpha++;
		}
		if (this->isAdd)
		{
			sizeOffset++;
			if (sizeOffset >= json.GetJson(jsonIndex)["RESULT_A_SIZE_OFFSET"])
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
		if (input.GetPadState() & PAD_INPUT_3)
		{
			this->isEnd = true;
		}
	}
	waitFrameCount++;
}
/// <summary>
/// 描画
/// </summary>
void Result::Draw()
{
	auto& json = JsonManager::GetInstance();
	int jsonFileNum = static_cast<int>(JsonManager::FileNameType::SET_UP_SCREEN);
	int jsonIndex = static_cast<int>(JsonManager::FileNameType::SCENE);

	DrawStringToHandle(this->textPos[static_cast<int>(TextType::MAIN)][0], this->textPos[static_cast<int>(TextType::MAIN)][1],"THANK YOU FOR PLAYING", this->textColor, this->fontHandle);
	if (this->isGameClear)
	{
		DrawStringToHandle(this->textPos[static_cast<int>(TextType::CLEAR)][0], this->textPos[static_cast<int>(TextType::CLEAR)][1], "CONGRATULATIONS", this->textColor, this->fontHandle);
	}
	else if (this->isGameOver)
	{
		DrawStringToHandle(this->textPos[static_cast<int>(TextType::OVER)][0], this->textPos[static_cast<int>(TextType::OVER)][1], "PLEASE TRY AGAIN", this->textColor, this->fontHandle);
	}

	const int x = json.GetJson(jsonIndex)["RESULT_A_BUTTON_Y"];
	const int y = json.GetJson(jsonIndex)["RESULT_A_BUTTON_X"];
	const int size = json.GetJson(jsonIndex)["RESULT_A_SIZE"];
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->buttonAlpha);
	DrawExtendGraph(x - this->sizeOffset, y - this->sizeOffset, x + size + this->sizeOffset, y + size + this->sizeOffset, this->imageHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->alpha);
	DrawBox(0, 0, json.GetJson(jsonFileNum)["WINDOW_WIDTH"], json.GetJson(jsonFileNum)["WINDOW_HEIGHT"], this->color, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
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
	if (this->isEnd && this->alpha >= this->MAX_ALPHA)
	{
		auto& changer = SceneChanger::GetInstance();
		changer.ChangeScene(SceneChanger::SceneType::TITLE);
	}
}
