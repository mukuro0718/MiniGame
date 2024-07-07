#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Shark::Shark(const int _modelHandle)
	: Amo(_modelHandle)
{
	Init();
}

/// <summary>
/// デストラクタ
/// </summary>
Shark::~Shark()
{

}

/// <summary>
/// 初期化
/// </summary>
void Shark::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::AMO);

	/*メンバ変数の初期化*/
	this->posOffset.Convert(json.GetJson(jsonIndex)["SHARK_POS_OFFSET"]);
	this->isHit		= false;
	this->isOut		= false;
	this->isSet		= false;
	this->isRebel	= false;
	this->velocity	= json.GetJson(jsonIndex)["SHARK_VELOCITY"];
	this->radius = json.GetJson(jsonIndex)["SHARK_RADIUS"];
	this->hitPosOffset.Convert(json.GetJson(jsonIndex)["SHARK_HIT_POS_OFFSET"]);
	this->price = json.GetJson(jsonIndex)["SHARK_PRICE"];

	/*トランスフォームの設定*/
	SetTransform(json.GetJson(jsonIndex)["INIT_POS"], json.GetJson(jsonIndex)["INIT_ROTATE"], json.GetJson(jsonIndex)["INIT_SCALE"]);

	/*モデルの設定*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// 更新
/// </summary>
void Shark::Update()
{
	HitCheck();

	Move();

	/*モデルの設定*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);

	/*描画*/
	Draw();
}

/// <summary>
/// 移動
/// </summary>
void Shark::Move()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::AMO);

	if (!this->isOut)
	{
		MoveOffScreen();
		if (this->transform.pos.value.x >= 100.0f || this->transform.pos.value.y >= 100.0f)
		{
			this->transform.pos = { 120.0,-20.0f,0.0 };
			this->isOut = true;
		}
	}
	else
	{
		if (this->isRebel)
		{
			this->moveVec = { 2.0f,0.0f,0.0f };
			this->transform.rotate = { 0.0f,0.0f,0.0f };
			this->transform.pos += this->moveVec.Scale(this->velocity);
		}
		else
		{
			ChangeScale();
			ChangeRotate();

			this->moveVec = { -2.0f,0.0f,0.0f };
			this->transform.rotate = { 0.0f,180.0f,0.0f };
			this->transform.rotate.DegToRad(this->transform.rotate);
			this->transform.pos += this->moveVec.Scale(this->velocity);
			if (this->transform.pos.value.x < -250.0f)
			{
				this->hitPosOffset.Convert(json.GetJson(jsonIndex)["SHARK_HIT_POS_OFFSET_REBEL"]);
				this->transform.pos = { -250.0,-50.0f,50.0 };
				this->isRebel = true;
			}
		}
	}
}