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
	, alpha(this->MAX_ALPHA)
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
	auto& character = CharacterManager::GetInstance();
	if (!character.GetPlayerInstance().GetIsStop()) return;
	if (this->isAddAlpha)
	{
		this->alpha += 5;
		if (this->alpha < this->MAX_ALPHA)return;
		this->alpha = this->MAX_ALPHA;
		this->isAddAlpha = false;
	}
	else
	{
		this->alpha -= 5;
		if (this->alpha > this->MIN_ALPHA)return;
		this->alpha = this->MIN_ALPHA;
		this->isAddAlpha = true;
	}
}

/// <summary>
/// 描画
/// </summary>
const void Operation::Draw()const
{
	auto& character = CharacterManager::GetInstance();
	if (!character.GetPlayerInstance().GetIsStop()) return;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->alpha);
	DrawStringToHandle(this->pos[0], this->pos[1], "PUSH A / SPACE", GetColor(255, 255, 255), this->fontHandle);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, this->MAX_ALPHA);
}