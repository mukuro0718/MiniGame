#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Normal::Normal(const int _modelHandle, const vector<float> _movePos)
	: Enemy(_modelHandle)
	, velocity(0.0f)
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::ENEMY);
		
	/*トランスフォームの設定*/
	this->transform.pos		.Convert(json.GetJson(jsonIndex)["INIT_POS"]);
	this->transform.scale	.Convert(json.GetJson(jsonIndex)["NORMAL_INIT_SCALE"]);
	this->transform.rotate	.Convert(json.GetJson(jsonIndex)["NORMAL_INIT_ROTATE"]);
	this->transform.rotate	.DegToRad(this->transform.rotate);
	this->moveTargetPos		.Convert(_movePos);

	Init();
}

/// <summary>
/// デストラクタ
/// </summary>
Normal::~Normal()
{

}

/// <summary>
/// 初期化
/// </summary>
void Normal::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::ENEMY);

	/*メンバ変数の初期化*/
	this->initPos		.Convert(json.GetJson(jsonIndex)["INIT_POS"]);
	this->transform.pos = this->initPos;
	this->state			= StateType::MOVE;
	this->velocity		= 0.0f;
	this->isStop		= false;

	/*モデルの設定*/
	MV1SetScale			(this->modelHandle,this->transform.scale.value);
	MV1SetRotationXYZ	(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition		(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// 更新
/// </summary>
void Normal::Update()
{
	auto& character = CharacterManager::GetInstance();

	if (character.GetIsShowBoss())
	{
		MoveOffScreen();
	}
	else
	{
		/*移動*/
		Move();
	}
	/*モデルの設定*/
	MV1SetScale			(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ	(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition		(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// 状態の変化
/// </summary>
void Normal::ChangeFlagsState()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto&	timer		= GameTimer::GetInstance();
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::ENEMY);


	
}