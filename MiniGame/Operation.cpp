#include "Common.h"

const int Operation::TEXT_COLOR_GREEN = GetColor(50, 255, 50);

/// <summary>
/// コンストラクタ
/// </summary>
Operation::Operation(const int _fontHandle, const int _imageHandle,const int _modelHandle)
	: fontHandle(0)
	, color(0)
	, moveX(0)
	, isStop(false)
	, stopFrameCount(0)
{
	this->fontHandle = _fontHandle;
	this->imageHandle = _imageHandle;
	this->modelHandle = MV1DuplicateModel(_modelHandle);
	for (int i = 0; i < 2; i++)
	{
		this->pos.emplace_back(0);
	}
	Init();
}

/// <summary>
/// デストラクタ
/// </summary>
Operation::~Operation()
{

}

/// <summary>
/// 初期化
/// </summary>
void Operation::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::UI);
	vector<int> color = json.GetJson(jsonIndex)["OPERATION_COLOR"];
	vector<int> pos = json.GetJson(jsonIndex)["OPERATION_TEXT_POS"];
	vector<int> endPos = json.GetJson(jsonIndex)["OPERATION_END_POS"];

	this->pos = pos;
	this->moveX = 0;
	this->isStart = true;
	this->isStop = false;
	this->isEnd = false;
	this->isFinish = false;
	this->isShowTutorial = false;
	this->isShowTutorialButton = false;
	this->isShowRideButton = false;
	this->textIndex = 0;
	this->buttonSize = 5;
	this->isAddButtonSize = true;
	this->color = GetColor(color[0], color[1], color[2]);

	this->transform.pos.Convert(json.GetJson(jsonIndex)["MODEL_POS"]);
	this->transform.rotate.Convert(json.GetJson(jsonIndex)["MODEL_ROTATE"]);
	this->transform.rotate.DegToRad(this->transform.rotate);
	this->transform.scale.Convert(json.GetJson(jsonIndex)["MODEL_SCALE"]);

	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);

}

/// <summary>
/// 更新
/// </summary>
void Operation::Update()
{
	///*シングルトンクラスのインスタンスの取得*/
	//auto& json = JsonManager::GetInstance();
	//auto& timer = GameTimer::GetInstance();
	//auto& input = InputManager::GetInstance();
	//auto& character = CharacterManager::GetInstance();
	//int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::UI);
	//int time = timer.GetElapsetTime();
	//int frame = timer.GetElapsetFrame();

	//if (character.GetPlayerInstance().GetIsRide())
	//{
	//	this->transform.pos.value.x -= 2.0f;
	//}

	//if (this->isAddButtonSize)
	//{
	//	this->buttonSize += 0.1f;
	//	if (this->buttonSize >= 8.0f)
	//	{
	//		this->buttonSize = 8.0f;
	//		this->isAddButtonSize = false;
	//	}
	//}
	//else
	//{
	//	this->buttonSize -= 0.1f;
	//	if (this->buttonSize <= 5.0f)
	//	{
	//		this->buttonSize = 5.0f;
	//		this->isAddButtonSize = true;
	//	}
	//}

	//WrapVECTOR carPos = character.GetPlayerInstance().GetTransform().pos;
	//WrapVECTOR characterPos = character.GetPlayerInstance().GetCharacterPos();
	//float size = (carPos - characterPos).Size();
	////乗り込みようAボタンUIの表示処理
	//if ( size <= 12.0f)
	//{
	//	this->isShowRideButton = true;
	//}
	//else
	//{
	//	this->isShowRideButton = false;
	//}
	//size = (this->transform.pos - characterPos).Size();
	////チュートリアル用AボタンUIの表示処理
	//if ( size <= 12.0f)
	//{
	//	this->isShowTutorialButton = true;
	//}
	//else
	//{
	//	this->isShowTutorialButton = false;
	//}


	//if (this->isShowTutorialButton)
	//{
	//	if (input.GetPadState() & PAD_INPUT_3)
	//	{
	//		this->isShowTutorial = true;
	//	}
	//	else if (input.GetPadState() & PAD_INPUT_4)
	//	{
	//		this->isShowTutorial = false;
	//	}
	//}
	//else
	//{
	//	this->isShowTutorial = false;
	//}
	//MV1SetPosition(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// 描画
/// </summary>
const void Operation::Draw()const
{
	//auto& character = CharacterManager::GetInstance();
	//WrapVECTOR tutorialButtonPos = this->transform.pos;
	//tutorialButtonPos.value.y += this->BUTTON_POS_Y_OFFSET;
	//WrapVECTOR rideButtonPos = character.GetPlayerInstance().GetTransform().pos;
	//rideButtonPos.value.y += this->BUTTON_POS_Y_OFFSET;

	//if (!character.GetPlayerInstance().GetIsRide())
	//{
	//	MV1DrawModel(this->modelHandle);

	//	if (this->isShowTutorialButton)
	//	{
	//		DrawBillboard3D(tutorialButtonPos.value, 0.5f, 0.5f, buttonSize, 0.0f, this->imageHandle, TRUE);
	//	}
	//	if (this->isShowRideButton)
	//	{
	//		DrawBillboard3D(rideButtonPos.value, 0.5f, 0.5f, buttonSize, 0.0f, this->imageHandle, TRUE);
	//	}
	//	if (this->isShowTutorial)
	//	{
	//		DrawBox(50, 50, 1870, 1030, GetColor(0, 0, 0), TRUE);
	//		DrawBox(70, 70, 1850, 1010, GetColor(255, 255, 200), TRUE);
	//		DrawStringToHandle(this->pos[0], this->pos[1], "Aボタンで上昇\n\n敵の攻撃や、道路などに当たるとゲームオーバーです。\n\n下のバーの車が家のマークまでたどり着くと、ゲームクリアです\n\n\n\nBボタンで閉じる", GetColor(255, 255, 255), this->fontHandle);
	//	}
	//}
}