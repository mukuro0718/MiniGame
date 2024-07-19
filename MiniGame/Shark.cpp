#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Shark::Shark(const int _modelHandle, const int _imageHandle)
	: Amo(_modelHandle,_imageHandle)
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
	this->isSetMoveTargetPos = false;

	this->velocity	= json.GetJson(jsonIndex)["SHARK_VELOCITY"];
	this->radius = json.GetJson(jsonIndex)["SHARK_RADIUS"];
	this->hitPosOffset.Convert(json.GetJson(jsonIndex)["SHARK_HIT_POS_OFFSET"]);

	/*トランスフォームの設定*/
	SetTransform(json.GetJson(jsonIndex)["INIT_POS"], json.GetJson(jsonIndex)["CHANGE_ROTATE"], json.GetJson(jsonIndex)["INIT_SCALE"]);

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
	Swim();
	/*モデルの設定*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
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
		//移動目標座標を設定していなかったら設定する
		if (!this->isSetMoveTargetPos)
		{
			//x,z軸は決められた位置で、y軸のみランダムにする
			this->moveTargetPos = { json.GetJson(jsonIndex)["MOVE_TARGET_X_POS"],GetRandom(10),0.0 };
			//フラグを立てる
			this->isSetMoveTargetPos = true;
		}
		else
		{
			WrapVECTOR moveTargetToPosVec = this->moveTargetPos - this->transform.pos;
			this->moveVec = moveTargetToPosVec.Norm();
			float moveTargetToPosVecSize = moveTargetToPosVec.Size();
			if (moveTargetToPosVecSize <= 5.0f)
			{
				this->isOut = true;
				this->transform.pos = this->moveTargetPos;
			}
			else
			{
				this->transform.pos += this->moveVec;
			}
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