#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Amo::Amo(const int _modelHandle, const int _imageHandle)
	: Object			()
	, modelHandle		(0)
	, imageHandle		(_imageHandle)
	, moveVec			(0.0f)
	, posOffset			(0.0f)
	, hitPos			(0.0f)
	, moveTargetPos		(0.0f)
	, isHit				(false)
	, isOut				(false)
	, isSet				(false)
	, velocity			(0.0f)
	, isRebel			(false)
	, isSetMoveTargetPos(false)
	, isSwimAdd			(false)
	, swimAngle			(0.0f)
{
	this->modelHandle = MV1DuplicateModel(_modelHandle);
}

/// <summary>
/// デストラクタ
/// </summary>
Amo::~Amo()
{

}

/// <summary>
/// トランスフォームの設定
/// </summary>
void Amo::SetTransform(vector<float> _pos, vector<float> _rotate, vector<float> _scale)
{
	this->transform.pos		.Convert(_pos);
	this->transform.scale	.Convert(_scale);
	this->transform.rotate	.Convert(_rotate);
	this->transform.rotate	.DegToRad(this->transform.rotate);
}

/// <summary>
/// 座標のsetter
/// </summary>
void Amo::SetPos(const WrapVECTOR& _pos)
{
	this->transform.pos = _pos;
	this->transform.pos += this->posOffset;
	this->isSet = true;
}

/// <summary>
/// 描画
/// </summary>
const void Amo::Draw()const
{
	MV1DrawModel(this->modelHandle);
	if (!this->isOut)
	{
		DrawBillboard3D(this->transform.pos.value, 0.5f, 0.5f, 30.0f, 0.0f, this->imageHandle, TRUE);
	}
	//WrapVECTOR spherePos = this->transform.pos.value;
	//spherePos += this->hitPosOffset;
	//DrawSphere3D(this->moveTargetPos.value, this->radius, 16, GetColor(255, 0, 0), GetColor(255, 0, 0), FALSE);
}

/// <summary>
/// 画面外へ移動
/// </summary>
void Amo::MoveOffScreen()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::AMO);

	WrapVECTOR moveVec	= { 1.0f,0.0f,0.0f };
	WrapVECTOR rotate	= 0.0f;
	rotate.Convert(json.GetJson(jsonIndex)["MOVE_VEC_ROTATE"]);
	moveVec = moveVec.Rotate(rotate);
	this->moveVec = moveVec.Scale(json.GetJson(jsonIndex)["MOVE_OFF_SCREEN_VELOCITY"]);
	this->transform.pos += this->moveVec;
}

/// <summary>
/// 回転率の変更
/// </summary>
void Amo::ChangeRotate()
{
	if (this->isOut)
	{
		/*シングルトンクラスのインスタンスの取得*/
		auto&	json		= JsonManager::GetInstance();
		int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::AMO);

		this->transform.rotate.Convert(json.GetJson(jsonIndex)["CHANGE_ROTATE"]);
		this->transform.rotate.DegToRad(this->transform.rotate);
	}
}

/// <summary>
/// スケールの変更
/// </summary>
void Amo::ChangeScale()
{
	if (this->isOut)
	{
		/*シングルトンクラスのインスタンスの取得*/
		auto& json = JsonManager::GetInstance();
		int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::AMO);

		this->transform.scale.Convert(json.GetJson(jsonIndex)["CHANGE_SCALE"]);
	}
}

/// <summary>
/// 
/// </summary>
const float Amo::GetRandom(const int _range)const
{
	auto& character = CharacterManager::GetInstance();
	float out = character.GetPlayerPos().value.y;

	float add = static_cast<float>(GetRand(_range));
	if (GetRand(1) == 0)
	{
		add *= -1.0f;
	}
	out += add;
	if (out >= 55.0f)
	{
		out = 50.0f;
	}
	else if (out <= -50.0f)
	{
		out = -45.0f;
	}
	return add + out;
	
}

/// <summary>
/// 当たり判定
/// </summary>
void Amo::HitCheck()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& collision = Collision::GetInstance();
	auto& character = CharacterManager::GetInstance();

	if (!this->isHit)
	{
		this->isHit = collision.SphereAndSphereCollision(*this, character.GetPlayerInstance())->isHit;
	}
}

/// <summary>
/// 泳ぎ
/// </summary>
void Amo::Swim()
{
	if (this->isSwimAdd)
	{
		swimAngle += 1.0f;

		if (this->swimAngle >= 5.0f)
		{
			this->isSwimAdd = false;
		}
	}
	else
	{
		swimAngle -= 1.0f;
		if (this->swimAngle <= -5.0f)
		{
			this->isSwimAdd = true;
		}
	}
		this->swimFrameCount++;


	this->transform.rotate.value.y += this->swimAngle * (DX_PI_F / 180.0f);
}