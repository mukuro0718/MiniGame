#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Title::Title()
	: imageHandle		(-1)
	, fontHandle		(-1)
	, alpha				(MAX_ALPHA)
	, isEnd				(false)
	, sizeOffset		(0)
	, logoAlpha			(0)
	, buttonAlpha		(0)
	, buttonFontHandle	(-1)
	, isAddButtonAlpha	(true)
{
	Create();
	SetTransform();
	auto& backGround = BackGround::GetInstance();
	backGround.Init();

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
	auto& backGround = BackGround::GetInstance();
	auto& camera = CameraManager::GetInstance();


	backGround.Update();
	
	for (int i = 0; i < this->modelHandle.size(); i++)
	{
		MV1SetScale(this->modelHandle[i], this->transform[i].scale.value);
		MV1SetRotationXYZ(this->modelHandle[i], this->transform[i].rotate.value);
		MV1SetPosition(this->modelHandle[i], this->transform[i].pos.value);
	}
	
	ChangeLogoSizeOffset();
	ChangeTransitionAlpha();
}

/// <summary>
/// 描画
/// </summary>
void Title::Draw()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& backGround = BackGround::GetInstance();

	backGround.Draw();
	
	DrawTitleImage();
	DrawLogo();
	DrawTransition();
}

/// <summary>
/// 終了処理
/// </summary>
void Title::EndProcess()
{
	/*インプットマネージャーのインスタンスを取得*/
	auto& input = InputManager::GetInstance();
	
	if (input.GetReturnKeyState() || input.GetPadState() & PAD_INPUT_3)
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
/// <summary>
/// ロゴの描画
/// </summary>
const void Title::DrawLogo()const
{
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::SCENE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->logoAlpha);
	DrawStringToHandle(json.GetJson(jsonIndex)["TITLE_LOGO_X"], json.GetJson(jsonIndex)["TITLE_LOGO_Y"], "いつもとちがう\n　　　帰り道", GetColor(255, 255, 255), this->fontHandle);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, this->MAX_ALPHA);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->buttonAlpha);
	DrawStringToHandle(json.GetJson(jsonIndex)["TITLE_BUTTON_X"], json.GetJson(jsonIndex)["TITLE_BUTTON_Y"], "ボタンを押す", GetColor(255, 255, 255), this->buttonFontHandle);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, this->MAX_ALPHA);
}

/// <summary>
/// ボタンの描画
/// </summary>
const void Title::DrawTitleImage()const
{
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::SCENE);

	const int lx = json.GetJson(jsonIndex)["TITLE_IMAGE_LX"];
	const int ly = json.GetJson(jsonIndex)["TITLE_IMAGE_LY"];
	const int rx = json.GetJson(jsonIndex)["TITLE_IMAGE_RX"];
	const int ry = json.GetJson(jsonIndex)["TITLE_IMAGE_RY"];
	DrawExtendGraph(lx, ly, rx, ry, this->imageHandle, TRUE);
}

/// <summary>
/// 遷移画像の描画
/// </summary>
const void Title::DrawTransition()const
{
	auto& json = JsonManager::GetInstance();
	int jsonIndex = static_cast<int>(JsonManager::FileNameType::SET_UP_SCREEN);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->alpha);
	DrawBox(0, 0, json.GetJson(jsonIndex)["WINDOW_WIDTH"], json.GetJson(jsonIndex)["WINDOW_HEIGHT"], GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}


/// <summary>
/// ロゴサイズオフセットの変更
/// </summary>
void Title::ChangeLogoSizeOffset()
{
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::SCENE);

	if (this->alpha <= 0)
	{
		if (this->logoAlpha < this->MAX_ALPHA)
		{
			this->logoAlpha += json.GetJson(jsonIndex)["TITLE_LOGO_ADD_ALPHA"];
			if (this->logoAlpha >= this->MAX_ALPHA)
			{
				this->logoAlpha = this->MAX_ALPHA;
			}
		}
		else
		{
			if (this->isAddButtonAlpha)
			{
				this->buttonAlpha += json.GetJson(jsonIndex)["TITLE_LOGO_ADD_ALPHA"];
				if (this->buttonAlpha >= this->MAX_ALPHA)
				{
					this->isAddButtonAlpha = false;
				}
			}
			else
			{
				this->buttonAlpha -= json.GetJson(jsonIndex)["TITLE_LOGO_ADD_ALPHA"];
				if (this->buttonAlpha < 0)
				{
					this->isAddButtonAlpha = true;
				}
			}
		}
	}

}

/// <summary>
/// 遷移アルファ値の変更
/// </summary>
void Title::ChangeTransitionAlpha()
{
	if (!this->isEnd)
	{
		if (this->alpha > 0)
		{
			this->alpha -= 10;
		}
	}
	else
	{
		this->alpha += 10;
		if (this->alpha >= this->MAX_ALPHA)
		{
			this->alpha = this->MAX_ALPHA;
		}
	}
}
void Title::Create()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& asset = LoadingAsset::GetInstance();

	this->modelHandle.emplace_back(MV1DuplicateModel(asset.GetModel(asset.GetModelType(LoadingAsset::ModelType::FISH_1))));
	this->modelHandle.emplace_back(MV1DuplicateModel(asset.GetModel(asset.GetModelType(LoadingAsset::ModelType::FISH_2))));
	this->modelHandle.emplace_back(MV1DuplicateModel(asset.GetModel(asset.GetModelType(LoadingAsset::ModelType::FISH_3))));
	this->modelHandle.emplace_back(MV1DuplicateModel(asset.GetModel(asset.GetModelType(LoadingAsset::ModelType::CAR))));
	this->fontHandle = asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI_2));
	this->buttonFontHandle = asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI));
	this->imageHandle = asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::TITLE_IMAGE));
}

void Title::SetTransform()
{
	Transform addTransform;
	addTransform.rotate = 0.0f;
	addTransform.scale = 0.2f;
	addTransform.pos = 0.0f;

	for (int i = 0; i < this->modelHandle.size(); i++)
	{
		this->transform.emplace_back(addTransform);
	}

	this->transform[static_cast<int>(ModelType::FISH_1)].pos = { -40.0f,30.0f,0.0f };
	this->transform[static_cast<int>(ModelType::FISH_1)].rotate.DegToRad(WrapVECTOR(0.0f, 0.0f, 0.0f));
	this->transform[static_cast<int>(ModelType::FISH_1)].scale = 0.5f;

	this->transform[static_cast<int>(ModelType::FISH_2)].pos = { -20.0f,10.0f,-20.0f };
	this->transform[static_cast<int>(ModelType::FISH_2)].rotate.DegToRad(WrapVECTOR(0.0f, 0.0f, 0.0f));
	this->transform[static_cast<int>(ModelType::FISH_2)].scale = 0.5f;

	this->transform[static_cast<int>(ModelType::FISH_3)].pos = { -60.0f,-10.0f,20.0f };
	this->transform[static_cast<int>(ModelType::FISH_3)].rotate.DegToRad(WrapVECTOR(0.0f, 0.0f, 0.0f));
	this->transform[static_cast<int>(ModelType::FISH_3)].scale = 0.5f;

	this->transform[static_cast<int>(ModelType::PLAYER)].pos = { 70.0f,0.0f,0.0f };
	this->transform[static_cast<int>(ModelType::PLAYER)].rotate.DegToRad(WrapVECTOR(0.0f, -90.0f, 0.0f));
	this->transform[static_cast<int>(ModelType::PLAYER)].scale = 0.08f;
}
