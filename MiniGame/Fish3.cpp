#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Fish3::Fish3(const int _modelHandle)
	: Amo(_modelHandle)
{
	Init();
}

/// <summary>
/// デストラクタ
/// </summary>
Fish3::~Fish3()
{

}

/// <summary>
/// 初期化
/// </summary>
void Fish3::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::AMO);

	/*メンバ変数の初期化*/
	this->posOffset.Convert(json.GetJson(jsonIndex)["FISH_POS_OFFSET"]);
	this->isHit		= false;
	this->isOut		= false;
	this->isSet = false;
	this->velocity = json.GetJson(jsonIndex)["FISH3_VELOCITY"];
	this->radius = json.GetJson(jsonIndex)["FISH3_RADIUS"];
	this->hitPosOffset.Convert(json.GetJson(jsonIndex)["FISH3_HIT_POS_OFFSET"]);
	this->price = json.GetJson(jsonIndex)["FISH3_PRICE"];

	SetTransform(json.GetJson(jsonIndex)["INIT_POS"], json.GetJson(jsonIndex)["INIT_ROTATE"], json.GetJson(jsonIndex)["INIT_SCALE"]);

	/*モデルの設定*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// 更新
/// </summary>
void Fish3::Update()
{
	if (!this->isHit)
	{
		HitCheck();

		Move();

		ChangeRotate();
		ChangeScale();

		/*モデルの設定*/
		MV1SetScale(this->modelHandle, this->transform.scale.value);
		MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
		MV1SetPosition(this->modelHandle, this->transform.pos.value);

		/*描画*/
		Draw();
	}
}

/// <summary>
/// 移動
/// </summary>
void Fish3::Move()
{
	if (!this->isOut)
	{
		MoveOffScreen();
		if (this->transform.pos.value.x >= 100.0f || this->transform.pos.value.y >= 100.0f)
		{
			this->transform.pos = { 120.0,GetRandom(40),0.0 };
			this->isOut = true;
		}
	}
	else
	{
		this->moveVec = { -2.0f,0.0f,0.0f };
		this->transform.rotate = { 0.0f,180.0f,0.0f };
		this->transform.rotate.DegToRad(this->transform.rotate);
		this->transform.pos += this->moveVec.Scale(this->velocity);
	}

}