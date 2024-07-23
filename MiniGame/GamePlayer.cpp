#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
GamePlayer::GamePlayer(int _modelHandle, const int _breakModelHandle, const int _characterModelHandle)
	: Character(_modelHandle)
	, jumpPower(0.0f)
	, height(0.0f)
	, floatPower(0.0f)
	, isStun(false)
	, isOnGround(false)
	, isStop(true)
	//, isRide(false)
	, countStartTime(0)
	, aliveTime		(0)
	, stunFrameCount(0)
	, normalModelHandle(-1)
	//, characterModelHandle(-1)
{	
	this->hitResult = new HitResult();
	this->normalModelHandle = MV1DuplicateModel(_modelHandle);
	this->breakModelHandle = MV1DuplicateModel(_breakModelHandle);
	//this->characterModelHandle = MV1DuplicateModel(_characterModelHandle);
	/*初期化*/
	Init();
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
	/*this->characterTransform.pos.Convert(json.GetJson(jsonIndex)["INIT_CHARACTER_POS"]);
	this->characterTransform.rotate.Convert(json.GetJson(jsonIndex)["INIT_CHARACTER_ROTATE"]);
	this->characterTransform.rotate.DegToRad(this->transform.rotate);
	this->characterTransform.scale.Convert(json.GetJson(jsonIndex)["INIT_CHARACTER_SCALE"]);*/
	this->moveVec.			Convert(json.GetJson(jsonIndex)["ORIGIN"]);
	this->fixVec.			Convert(json.GetJson(jsonIndex)["ORIGIN"]);
	this->aliveTime			= 0;
	this->price				= 0;
	this->stunFrameCount	= 0;
	this->radius			= json.GetJson(jsonIndex)["RADISU"];
	this->modelHandle		= this->normalModelHandle;
	this->countStartTime	= GetNowCount();
	
	this->isStun			= false;
	this->isOnGround		= false;
	this->isHit				= false;
	this->isStop			= true;
	//this->isRide = false;
	
	this->zAngle			= 0.0f;
	this->floatPower		= 0.0f;
	this->height			= json.GetJson(jsonIndex)["STAND_HEIGHT"];
	this->jumpPower			= 0.0f;
	/*モデルの設定*/
	MV1SetScale			(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ	(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition		(this->modelHandle, this->transform.pos.value);
	MV1SetScale			(this->breakModelHandle, this->transform.scale.value);
	MV1SetRotationXYZ	(this->breakModelHandle, this->transform.rotate.value);
	MV1SetPosition		(this->breakModelHandle, this->transform.pos.value);
	//MV1SetScale			(this->characterModelHandle, this->characterTransform.scale.value);
	//MV1SetRotationXYZ	(this->characterModelHandle, this->characterTransform.rotate.value);
	//MV1SetPosition		(this->characterModelHandle, this->characterTransform.pos.value);
}
/// <summary>
/// 更新
/// </summary>
void GamePlayer::Update()
{
	auto& time = GameTimer::GetInstance();
	this->aliveTime = time.GetElapsetTime();
	auto& sound = Sound::GetInstance();

	/*移動*/
	Move();
	/*音*/
	sound.PlayPlayerExplosionSound();
	sound.PlayButtonSound();
	sound.PlayMoneySound();
	/*当たり判定*/
	HitCheck();
	/*モデルの設定*/
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->breakModelHandle, this->transform.pos.value);
	MV1SetRotationXYZ(this->breakModelHandle, this->transform.rotate.value);
	//MV1SetPosition(this->characterModelHandle, this->characterTransform.pos.value);
	//MV1SetRotationXYZ(this->characterModelHandle, this->characterTransform.rotate.value);

	/*描画*/
	if (this->isHit)
	{
		this->modelHandle = this->breakModelHandle;
	}
}

/// <summary>
/// 当たり判定
/// </summary>
void GamePlayer::HitCheck()
{
	if (!this->isStop)
	{
		/*シングルトンクラスのインスタンスの取得*/
		auto& collision = Collision::GetInstance();
		auto& amo = AmoManager::GetInstance();
		auto& gem = GemManager::GetInstance();
		auto& sound = Sound::GetInstance();

		/*弾との当たり判定*/
		//使用している球の数を取得
		vector<int> useAmoNum = amo.GetNowUseNum();
		//弾の数だけループ
		for (int i = 0; i < useAmoNum.size(); i++)
		{
			for (int j = 0; j < useAmoNum[i]; j++)
			{
				//弾が誰とも当たっていないかつプレイヤーに向けて移動してきていたら
				if (!amo.GetAmoInstance(i, j).GetIsHit() && amo.GetAmoInstance(i, j).GetIsOut())
				{
					//プレイヤーと弾の当たり判定をスフィアでとる（弾のほうはカプセルのほうが良いかも）
					this->hitResult = collision.SphereAndSphereCollision(*this, amo.GetAmoInstance(i, j));
					//当たっていたら
					if (this->hitResult->isHit)
					{
						sound.OnIsPlayPlayerExplosionSound();
						//this->isHit = true;
					}
				}
			}
		}

		/*宝石との当たり判定*/
		//使用している宝石の数を取得
		for (int i = 0; i < gem.GetUseNum(); i++)
		{
			if (!gem.GetGemInstance(i).GetIsHit() && gem.GetGemInstance(i).GetIsSet())
			{
				//プレイヤーと宝石の当たり判定をスフィアでとる
	 			this->hitResult = collision.SphereAndSphereCollision(*this, gem.GetGemInstance(i));
				//もし当たっていたら
				if (this->hitResult->isHit)
				{
					sound.OnIsPlayMoneySound();
					this->price += gem.GetGemInstance(i).GetPrice();
				}
			}
		}
	}
}

/// <summary>
/// 移動
/// </summary>
void GamePlayer::Move()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& input = InputManager::GetInstance();
	auto& json = JsonManager::GetInstance();
	auto& timer = GameTimer::GetInstance();
	auto& ui = UIManager::GetInstance();
	auto& sound = Sound::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::PLAYER);
	int pad = input.GetPadState();


		if (timer.GetElapsetTime() >= 120)
		{
			this->transform.pos.value.x++;
			if (this->transform.pos.value.x >= 200.0f)
			{
				this->transform.pos.value.x = 200.0f;
			}
		}
		else
		{
			bool isInput = false;
			if (pad & PAD_INPUT_3 || CheckHitKey(KEY_INPUT_SPACE))
			{
				this->isStop = false;
				isInput = true;
			}

			if (!this->isStop)
			{
				/*上昇（もしAボタンが押されていたら）*/
				if (isInput && !this->isHit)
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
					/*if (!this->isHit)
					{
						sound.OnIsPlayPlayerExplosionSound();
					}*/
					//this->isHit = true;
					this->transform.pos.value.y = json.GetJson(jsonIndex)["MIN_Y"];
				}
			}
		}
	//}
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


void GamePlayer::DrawShadow()
{
	auto& stage = StageManager::GetInstance();
	//if (!this->isRide)
	//{
	//	MV1DrawModel(characterModelHandle);
	//}
	for (int i = 0; i < stage.GetFrontRoadNum(); i++)
	{
		this->shadow->Draw(stage.GetFrontRoadModelHandle(i),this->transform.pos.value, 100.0f, 10.0f);
	}
}