#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Boss::Boss(const int _modelHandle, const int _breakModelHandle, const vector<float> _movePos)
	: Enemy(_modelHandle)
	, velocity(0.0f)
{
	/*シングルトンクラスのインスタンスの取得*/
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::ENEMY);

	/*トランスフォームの設定*/
	this->transform.pos		.Convert(json.GetJson(jsonIndex)["INIT_POS"]);
	this->transform.scale	.Convert(json.GetJson(jsonIndex)["BOSS_INIT_SCALE"]);
	this->transform.rotate	.Convert(json.GetJson(jsonIndex)["BOSS_INIT_ROTATE"]);
	this->transform.rotate	.DegToRad(this->transform.rotate);
	this->moveTargetPos		.Convert(_movePos);
	this->breakModelHandle = MV1DuplicateModel(_breakModelHandle);

	Init();
}

/// <summary>
/// デストラクタ
/// </summary>
Boss::~Boss()
{

}

/// <summary>
/// 初期化
/// </summary>
void Boss::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::ENEMY);

	/*メンバ変数の初期化*/
	this->initPos		.Convert(json.GetJson(jsonIndex)["INIT_POS"]);
	this->transform.pos = this->initPos;
	this->velocity		= 0.0f;
	this->state			= StateType::MOVE;
	this->modelHandle	= this->normalModelHandle;
	this->isHit			= false;
	this->isStop = false;
	/*モデルの設定*/
	MV1SetScale			(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ	(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition		(this->modelHandle, this->transform.pos.value);

}

/// <summary>
/// 更新
/// </summary>
void Boss::Update()
{
	auto& timer = GameTimer::GetInstance();
	auto& sound = Sound::GetInstance();

	/*速度の更新*/
	UpdateVelocity();

	/*状態の切り替え*/
	ChangeFlagsState();

	if(this->isHit)
	{
		this->transform.pos.value.x -= 2.0f;
	}
	else
	{
		/*移動*/
		Move();
		HitCheck();
	}

	sound.PlayPlayerExplosionSound();
	/*モデルの設定*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
}

void Boss::HitCheck()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& collision = Collision::GetInstance();
	auto& amo = AmoManager::GetInstance();
	/*弾との当たり判定*/
//使用している球の数を取得
	vector<int> useAmoNum = amo.GetNowUseNum();
	//弾の数だけループ
	for (int i = 0; i < useAmoNum.size(); i++)
	{
		for (int j = 0; j < useAmoNum[i]; j++)
		{
			//プレイヤーと弾の当たり判定をスフィアでとる（弾のほうはカプセルのほうが良いかも）
			this->hitResult = collision.SphereAndSphereCollision(*this, amo.GetAmoInstance(i, j));
			//当たっていたら
			if (this->hitResult->isHit)
			{
				if (!this->isHit)
				{
					auto& sound = Sound::GetInstance();
					sound.OnIsPlayPlayerExplosionSound();
				}
				this->isHit = true;
				this->modelHandle = this->breakModelHandle;
			}
		}
	}
}

/// <summary>
/// 速度の更新
/// </summary>
void Boss::UpdateVelocity()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::ENEMY);

}

/// <summary>
/// 速度の更新
/// </summary>
float Boss::RandomY()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::ENEMY);
	float	out			= static_cast<float>(GetRand(json.GetJson(jsonIndex)["RANDOM_Y_RANGE"]));

	if (GetRand(0) == 0)
	{
		return out * -1.0f;
	}
	return out;
}
/// <summary>
/// 状態の変化
/// </summary>
void Boss::ChangeFlagsState()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto&	timer		= GameTimer::GetInstance();
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::ENEMY);
	
	/*移動状態*/
	if (this->state == StateType::MOVE && this->transform.pos.value.x >= 0.0f)
	{
		this->state = StateType::ATTACK;
	}
	/*攻撃中*/
	else if (this->state == StateType::ATTACK)
	{
		this->state = StateType::MOVE;
		this->transform.pos = initPos;
		this->transform.pos.value.y = RandomY();
	}


}