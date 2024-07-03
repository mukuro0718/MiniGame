#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
GamePlayer::GamePlayer(int _modelHandle)
	: Character		(_modelHandle)
	, jumpPower		(0.0f)
	, height		(0.0f)
	, floatPower	(0.0f)
	, isSit			(false)
	, isStun		(false)
	, isOnGround	(false)
	, isJump		(false)
	, countStartTime(0)
	, aliveTime		(0)
	, stunFrameCount(0)
{	
	/*初期化*/
	Init();

	/*アニメーションの追加*/
	AddAnim();
}
/// <summary>
/// デストラクタ
/// </summary>
GamePlayer::~GamePlayer()
{
}
/// <summary>
/// 初期化
/// </summary>
void GamePlayer::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::PLAYER);

	/*メンバ変数の初期化*/
	this->transform.pos.	Convert(json.GetJson(jsonIndex)["INIT_POS"]);
	this->transform.rotate.	Convert(json.GetJson(jsonIndex)["INIT_ROTATE"]);
	this->transform.rotate.	DegToRad(this->transform.rotate);
	this->transform.scale.	Convert(json.GetJson(jsonIndex)["INIT_SCALE"]);
	this->moveVec.			Convert(json.GetJson(jsonIndex)["ORIGIN"]);
	this->fixVec.			Convert(json.GetJson(jsonIndex)["ORIGIN"]);
	this->isOnGround		= false;
	this->isStun			= false;
	this->countStartTime	= GetNowCount();
	this->aliveTime			= 0;
	this->stunFrameCount	= 0;
	this->jumpPower			= 0.0f;
	this->height			= json.GetJson(jsonIndex)["STAND_HEIGHT"];
	this->radius			= json.GetJson(jsonIndex)["RADISU"];
	this->floatPower		= 0.0f;

	/*モデルの設定*/
	MV1SetScale			(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ	(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition		(this->modelHandle, this->transform.pos.value);

}
/// <summary>
/// アニメーションの追加
/// </summary>
void GamePlayer::AddAnim()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::PLAYER);

	vector<int> animIndex = json.GetJson(jsonIndex)["ANIM_INDEX"];
	for (int i = 0; i < animIndex.size(); i++)
	{
		this->anim->Add(-1, animIndex[i]);
	}
}
/// <summary>
/// アニメーションの変更
/// </summary>
void GamePlayer::ChangeAnim()
{
	if (this->isJump)
	{
		this->anim->Play(&this->modelHandle, static_cast<int>(AnimType::JUMP), 0.2f);
	}
	else if (this->isSit)
	{
		this->anim->Play(&this->modelHandle, static_cast<int>(AnimType::SIT), 1.0f);
	}
	else
	{
		this->anim->Play(&this->modelHandle, static_cast<int>(AnimType::IDLE), 0.5f);
	}
}
/// <summary>
/// 更新
/// </summary>
void GamePlayer::Update()
{
	/*移動*/
	Move();

	/*モデルの設定*/
	MV1SetPosition		(this->modelHandle, this->transform.pos.value);
	MV1SetRotationXYZ	(this->modelHandle, this->transform.rotate.value);

	/*描画*/
	Draw();
}
/// <summary>
/// 移動ベクトルの補正(床や壁,ギミック)
/// </summary>
void GamePlayer::FixMoveVec()
{
	//this->fixVec = _info.fixVec;
	//if (!this->isStun)
	//{
	//	this->isStun = _info.isHitAttack;
	//	if (this->isStun)
	//	{
	//		this->hitCount++;
	//	}
	//}
	//this->moveVec = VAdd(this->moveVec, this->fixVec);
}
/// <summary>
/// 移動
/// </summary>
void GamePlayer::Move()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& input = InputManager::GetInstance();
	auto& json = JsonManager::GetInstance();

	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::PLAYER);
	int pad = input.GetPadState();

	/*上昇（もしAボタンが押されていたら）*/
	if (pad & PAD_INPUT_2 || CheckHitKey(KEY_INPUT_SPACE))
	{
		zAngle += static_cast<float>(json.GetJson(jsonIndex)["ADD_ANGLE"]);
		floatPower += static_cast<float>(json.GetJson(jsonIndex)["ADD_JUMP_POWER"]);
	}
	
	/*下降（Aボタンが押されていなかったら）*/
	else
	{
		zAngle -= static_cast<float>(json.GetJson(jsonIndex)["DECREASE_ANGLE"]);
		floatPower -= static_cast<float>(json.GetJson(jsonIndex)["DECREASE_JUMP_POWER"]);
	}

	/*仮の座標の上限/下限値*/
	if (floatPower >= json.GetJson(jsonIndex)["MAX_JUMP_POWER"])
	{
		floatPower = json.GetJson(jsonIndex)["MAX_JUMP_POWER"];
	}
	else if (floatPower < json.GetJson(jsonIndex)["MIN_JUMP_POWER"])
	{
		floatPower = json.GetJson(jsonIndex)["MIN_JUMP_POWER"];
	}
	if (zAngle >= json.GetJson(jsonIndex)["MAX_ANGLE"])
	{
 		zAngle = json.GetJson(jsonIndex)["MAX_ANGLE"];
	}
	else if (zAngle < json.GetJson(jsonIndex)["MIN_ANGLE"])
	{
		zAngle = json.GetJson(jsonIndex)["MIN_ANGLE"];
	}

	/*移動ベクトルの更新*/
	this->moveVec.value.y = floatPower;

	/*回転率の更新*/
	this->transform.rotate.value.z = zAngle * (DX_PI_F / 180.0f);

	/*座標の更新*/
	this->transform.pos += this->moveVec;

	/*仮の座標の上限/下限値*/
	if (this->transform.pos.value.y >= json.GetJson(jsonIndex)["MAX_Y"])
	{
		this->transform.pos.value.y = json.GetJson(jsonIndex)["MAX_Y"];
	}
	else if (this->transform.pos.value.y <= json.GetJson(jsonIndex)["MIN_Y"])
	{
		this->transform.pos.value.y = json.GetJson(jsonIndex)["MIN_Y"];
	}
}
/// <summary>
/// フラグの状態を変更
/// </summary>
void GamePlayer::ChangeFlagsState()
{
	
}

/// <summary>
/// 時間の計測
/// </summary>
void GamePlayer::CountTime()
{
	this->aliveTime = GetNowCount() - this->countStartTime;
}