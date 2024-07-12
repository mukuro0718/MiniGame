#include "Common.h"

const int Result::COLOR_BLACK = GetColor(0, 0, 0);
const int Result::COLOR_WHITE = GetColor(255, 255, 255);

/// <summary>
/// コンストラクタ
/// </summary>
Result::Result()
	: explosionPos		 (0.0f)
	, isGameClear		 (false)
	, isGameOver		 (false)
	, isExplosion		 (false)
	, isEnd				 (false)
	, isAddAlpha		 (false)
	, isDrawClearText	 (false)
	, textColor			 (0)
	, transitionAlpha	 (MAX_ALPHA)
	, color				 (0)
	, buttonAlpha		 (0)
	, explosionIndex	 (0)
	, explosionFrameCount(0)
	, smokeHandle		 (-1)
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& character = CharacterManager::GetInstance();
	auto& timer = GameTimer::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonIndex = static_cast<int>(JsonManager::FileNameType::SCENE);

	Create();
	SetTransform();
	SetText();
	InitSmoke();
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
	auto& input		 = InputManager::GetInstance();
	auto& json		 = JsonManager::GetInstance();
	auto& backGround = BackGround::GetInstance();
	auto& camera	 = CameraManager::GetInstance();
	auto& stage		 = StageManager::GetInstance();
	auto& character  = CharacterManager::GetInstance();
	auto& timer		 = GameTimer::GetInstance();
	int   jsonIndex  = static_cast<int>(JsonManager::FileNameType::SCENE);

	backGround.Update();

	/*更新処理*/
	if (this->isGameClear)
	{
		timer.Update();
		camera.ClearCameraUpdate();
		if (this->transform[static_cast<int>(ModelType::HOUSE)].pos.value.x > 0.0f)
		{
			stage.Update();
			this->transform[static_cast<int>(ModelType::HOUSE)].pos.value.x--;
			if (this->transform[static_cast<int>(ModelType::HOUSE)].pos.value.x <= 0.0f)
			{
				this->isExplosion = true;
			}
		}
		for (int i = 0; i < this->modelHandle.size(); i++)
		{
			MV1SetPosition(this->modelHandle[i], this->transform[i].pos.value);
			MV1SetRotationXYZ(this->modelHandle[i], this->transform[i].rotate.value);
			MV1SetScale(this->modelHandle[i], this->transform[i].scale.value);
		}
		if (this->isExplosion)
		{
			this->explosionFrameCount++;

			if (this->explosionFrameCount % 5 == 0)
			{
				this->explosionIndex++;
				if (this->explosionIndex >= this->explosionHandle.size())
				{
					this->isExplosion = false;
					this->explosionIndex = 0;
				}
				if (this->explosionIndex >= 5)
				{
					this->isDrawClearText = true;
				}
			}
		}
	}
	else
	{
		camera.OverCameraUpdate();
		character.Update();
		UpdateSmoke();
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
		else
		{
			this->color = this->COLOR_BLACK;
		}
	}
	UpdateButtonAlpha();
}

/// <summary>
/// ボタンαの更新
/// </summary>
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
	int   jsonIndex	 = static_cast<int>(JsonManager::FileNameType::SET_UP_SCREEN);
	if (this->isGameClear)
	{
		DrawGameClear();
	}
	else
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
	for (int i = 0; i < this->smokePos.size(); i++)
	{
		DrawBillboard3D(this->smokePos[i].value, 0.5f, 0.5f, this->smokeSize[i], 0.0f, this->smokeHandle, TRUE);
	}
	character.Draw();


	fontIndex = static_cast<int>(FontType::OVER);
	DrawStringToHandle(this->textPos[fontIndex].x, this->textPos[fontIndex].y, "GAMEOVER", this->COLOR_WHITE, this->fontHandle[fontIndex]);
	fontIndex = static_cast<int>(FontType::BUTTON);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->buttonAlpha);
	DrawStringToHandle(this->textPos[fontIndex].x, this->textPos[fontIndex].y, "ボタンを押す", this->COLOR_WHITE, this->fontHandle[fontIndex]);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, this->MAX_ALPHA);
}
void Result::DrawGameClear()
{
	auto& stage = StageManager::GetInstance();
	auto& backGround = BackGround::GetInstance();
	int   fontIndex = 0;

	/*背景*/
	backGround.Draw();

	/*ステージ*/
	stage.Draw();
	
	/*モデル*/
	for (int i = 0; i < this->modelHandle.size(); i++)
	{
		MV1DrawModel(this->modelHandle[i]);
	}
	
	/*テキスト*/
	if (this->isDrawClearText)
	{
		fontIndex = static_cast<int>(FontType::CLEAR);
		DrawStringToHandle(this->textPos[fontIndex].x, this->textPos[fontIndex].y, "GAMECLEAR", this->COLOR_WHITE, this->fontHandle[fontIndex]);
		fontIndex = static_cast<int>(FontType::BUTTON);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->buttonAlpha);
		DrawStringToHandle(this->textPos[fontIndex].x, this->textPos[fontIndex].y, "ボタンを押す", this->COLOR_WHITE, this->fontHandle[fontIndex]);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, this->MAX_ALPHA);
	}
	
	/*爆発*/
	if (this->isExplosion)
	{
		DrawBillboard3D(this->explosionPos.value, 0.5f, 0.5f, this->EXPLOSIONT_SIZE, 0.0f, this->explosionHandle[this->explosionIndex], TRUE);
	}
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

/// <summary>
/// アセットの設定
/// </summary>
void Result::Create()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& asset = LoadingAsset::GetInstance();

	this->fontHandle.emplace_back(asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI_2)));
	this->fontHandle.emplace_back(asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI_2)));
	this->fontHandle.emplace_back(asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI)));
	this->modelHandle.emplace_back(asset.GetModel(asset.GetModelType(LoadingAsset::ModelType::CAR)));
	this->modelHandle.emplace_back(asset.GetModel(asset.GetModelType(LoadingAsset::ModelType::HOUSE)));

	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_01)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_02)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_03)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_04)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_05)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_06)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_07)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_08)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_09)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_10)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_11)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_12)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_13)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_14)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_15)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_16)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_17)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_18)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_19)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_20)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_21)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_22)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_23)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_24)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_25)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_26)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_27)));
	this->explosionHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::EXPLOSION_28)));

	this->smokeHandle = asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::SMOKE_BLACK));
}

void Result::SetTransform()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = static_cast<int>(JsonManager::FileNameType::SCENE);

	Transform init;
	for (int i = 0; i < this->modelHandle.size(); i++)
	{
		this->transform.emplace_back(init);
	}
	this->transform[static_cast<int>(ModelType::CAR)].pos.Convert(json.GetJson(jsonIndex)["RESULT_PLAYER_POS"]);
	this->transform[static_cast<int>(ModelType::CAR)].rotate.Convert(json.GetJson(jsonIndex)["RESULT_PLAYER_ROTATE"]);
	this->transform[static_cast<int>(ModelType::CAR)].rotate.DegToRad(this->transform[static_cast<int>(ModelType::CAR)].rotate);
	this->transform[static_cast<int>(ModelType::CAR)].scale.Convert(json.GetJson(jsonIndex)["RESULT_PLAYER_SCALE"]);
	this->transform[static_cast<int>(ModelType::HOUSE)].pos.Convert(json.GetJson(jsonIndex)["RESULT_HOUSE_POS"]);
	this->transform[static_cast<int>(ModelType::HOUSE)].rotate.Convert(json.GetJson(jsonIndex)["RESULT_HOUSE_ROTATE"]);
	this->transform[static_cast<int>(ModelType::HOUSE)].rotate.DegToRad(this->transform[static_cast<int>(ModelType::HOUSE)].rotate);
	this->transform[static_cast<int>(ModelType::HOUSE)].scale.Convert(json.GetJson(jsonIndex)["RESULT_HOUSE_SCALE"]);

	explosionPos = { 0.0f,0.0f,0.0f };
}


void Result::SetText()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& character = CharacterManager::GetInstance();
	auto& timer = GameTimer::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonIndex = static_cast<int>(JsonManager::FileNameType::SCENE);

	if (timer.GetElapsetTime() >= 120)
	{
		this->color = this->COLOR_WHITE;
		this->textColor = this->COLOR_WHITE;
		this->isGameClear = true;
	}
	else if (character.GetPlayerIsHit())
	{
		this->color = this->COLOR_BLACK;
		this->textColor = this->COLOR_WHITE;
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
int Result::GetRandom(const int _range, const bool _isSign, const int _offset)
{
	int out = GetRand(_range);
	if (_isSign && GetRand(1) == 1)
	{
		out *= -1;
	}

	return out + _offset;
}


/// <summary>
/// 煙の設定
/// </summary>
void Result::InitSmoke()
{
	auto& json = JsonManager::GetInstance();
	int jsonIndex = static_cast<int>(JsonManager::FileNameType::SCENE);
	auto& character = CharacterManager::GetInstance();

	WrapVECTOR origin = 0.0f;
	WrapVECTOR playerPos = character.GetPlayerPos();
	playerPos = playerPos.Add(json.GetJson(jsonIndex)["RESULT_SMOKE_POS_OFFSET"]);
	for (int i = 0; i < json.GetJson(jsonIndex)["RESULT_SMOKE_NUM"]; i++)
	{
		this->smokeMoveVec.emplace_back(origin);
		this->smokePos.emplace_back(playerPos);
		this->smokeVelocity.emplace_back(0.0f);
		this->smokeSize.emplace_back(0);
	}

	for (int i = 0; i < json.GetJson(jsonIndex)["RESULT_SMOKE_NUM"]; i++)
	{
		this->smokeMoveVec[i].value.x = static_cast<float>(GetRandom
		(
			json.GetJson(jsonIndex)["RESULT_SMOKE_X_RANGE"],
			true, 0
		));
		this->smokeMoveVec[i].value.y = static_cast<float>(GetRandom
		(
			json.GetJson(jsonIndex)["RESULT_SMOKE_Y_RANGE"],
			false,
			json.GetJson(jsonIndex)["RESULT_SMOKE_Y_OFFSET"]
		));
		this->smokeMoveVec[i] = this->smokeMoveVec[i].Norm();

		this->smokeVelocity[i] = static_cast<float>(GetRandom
		(
			json.GetJson(jsonIndex)["RESULT_SMOKE_VELOCITY_RANGE"],
			false,
			json.GetJson(jsonIndex)["RESULT_SMOKE_VELOCITY_OFFSET"]
		));
		this->smokeSize[i] = GetRandom
		(
			json.GetJson(jsonIndex)["RESULT_SMOKE_SIZE_RANGE"],
			false,
			json.GetJson(jsonIndex)["RESULT_SMOKE_SIZE_OFFSET"]
		);
	}
}
/// <summary>
/// 煙の設定
/// </summary>
void Result::SetSmoke(const int _index)
{
	auto& json = JsonManager::GetInstance();
	auto& character = CharacterManager::GetInstance();
	int jsonIndex = static_cast<int>(JsonManager::FileNameType::SCENE);
	this->smokePos[_index] = character.GetPlayerPos();
	smokePos[_index] = smokePos[_index].Add(json.GetJson(jsonIndex)["RESULT_SMOKE_POS_OFFSET"]);

	this->smokeMoveVec[_index].value.x = static_cast<float>(GetRandom
	(
		json.GetJson(jsonIndex)["RESULT_SMOKE_X_RANGE"],
		true, 0
	));
	this->smokeMoveVec[_index].value.y = static_cast<float>(GetRandom
	(
		json.GetJson(jsonIndex)["RESULT_SMOKE_Y_RANGE"],
		false,
		json.GetJson(jsonIndex)["RESULT_SMOKE_Y_OFFSET"]
	));
	this->smokeMoveVec[_index] = this->smokeMoveVec[_index].Norm();
	this->smokeVelocity[_index] = static_cast<float>(GetRandom
	(
		json.GetJson(jsonIndex)["RESULT_SMOKE_VELOCITY_RANGE"],
		false,
		json.GetJson(jsonIndex)["RESULT_SMOKE_VELOCITY_OFFSET"]
	));
	this->smokeSize[_index] = GetRandom
	(
		json.GetJson(jsonIndex)["RESULT_SMOKE_SIZE_RANGE"],
		false,
		json.GetJson(jsonIndex)["RESULT_SMOKE_SIZE_OFFSET"]
	);
}

/// <summary>
/// 煙の更新
/// </summary>
void Result::UpdateSmoke()
{
	for (int i = 0; i < this->smokePos.size(); i++)
	{
		float velocity = this->smokeVelocity[i] / 10.0f;
		this->smokePos[i] += this->smokeMoveVec[i].Scale(velocity);
		if (this->smokePos[i].value.y >= 10.0f)
		{
			SetSmoke(i);
		}
	}
}