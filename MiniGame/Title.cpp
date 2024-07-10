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
	camera.TitleCameraUpdate();
	
	for (int i = 0; i < this->modelHandle.size(); i++)
	{
		MV1SetScale(this->modelHandle[i], this->transform[i].scale.value);
		MV1SetRotationXYZ(this->modelHandle[i], this->transform[i].rotate.value);
		MV1SetPosition(this->modelHandle[i], this->transform[i].pos.value);
	}
	
	//ChangeLogoSizeOffset();
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
	
	for (int i = 0; i < this->modelHandle.size(); i++)
	{
		MV1DrawModel(this->modelHandle[i]);
	}

	//DrawLogo();
	//DrawButton();
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
	DrawStringToHandle(json.GetJson(jsonIndex)["TITLE_LOGO_X"], json.GetJson(jsonIndex)["TITLE_LOGO_Y"], "いつもとちがう\n　　　帰り道", GetColor(255, 255, 255), this->fontHandle);
}

/// <summary>
/// ボタンの描画
/// </summary>
const void Title::DrawButton()const
{
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::SCENE);

	const int x = json.GetJson(jsonIndex)["TITLE_A_BUTTON_X"];
	const int y = json.GetJson(jsonIndex)["TITLE_A_BUTTON_Y"];
	const int size = json.GetJson(jsonIndex)["TITLE_A_SIZE"];
	DrawExtendGraph(x - this->sizeOffset, y - this->sizeOffset, x + size + this->sizeOffset, y + size + this->sizeOffset, this->imageHandle, TRUE);
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
void Title::Create()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& asset = LoadingAsset::GetInstance();

	this->modelHandle.emplace_back(MV1DuplicateModel(asset.GetModel(asset.GetModelType(LoadingAsset::ModelType::FISH_1))));
	this->modelHandle.emplace_back(MV1DuplicateModel(asset.GetModel(asset.GetModelType(LoadingAsset::ModelType::FISH_2))));
	this->modelHandle.emplace_back(MV1DuplicateModel(asset.GetModel(asset.GetModelType(LoadingAsset::ModelType::FISH_3))));
	this->modelHandle.emplace_back(MV1DuplicateModel(asset.GetModel(asset.GetModelType(LoadingAsset::ModelType::CAR))));
	this->fontHandle = asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI_2));
	this->imageHandle = asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::A_BUTTON));
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
