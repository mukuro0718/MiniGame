#include "Common.h"

GameTimer* GameTimer::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
GameTimer::GameTimer()
	: elapsetTime(0)
	, elapsetFrame(0)
{
	/*初期化*/
	Init();
}

/// <summary>
/// デストラクタ
/// </summary>
GameTimer::~GameTimer()
{

}

/// <summary>
/// 初期化
/// </summary>
void GameTimer::Init()
{
	this->elapsetTime = 0;
	this->elapsetFrame = 0;
}

/// <summary>
/// 更新
/// </summary>
void GameTimer::Update()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::TIMER);

	/*フレーム数の増加*/
	this->elapsetFrame++;

	/*もしフレーム数が最大フレーム数を超えていたら*/
	if (this->elapsetFrame >= json.GetJson(jsonIndex)["MAX_FRAME"])
	{
		//経過時間を増やす
		this->elapsetTime++;
		//フレーム数を初期化する
		this->elapsetFrame = 0;
	}
}

/// <summary>
/// 描画
/// </summary>
const void GameTimer::Draw()const
{
#ifdef _DEBUG
	printfDx("TIME:%d", this->elapsetTime);
#endif // _DEBUG

}

