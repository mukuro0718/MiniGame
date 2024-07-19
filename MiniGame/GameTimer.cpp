#include "Common.h"

GameTimer* GameTimer::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
GameTimer::GameTimer()
	: elapsetTime(1)
	, elapsetFrame(1)
{
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
	this->elapsetTime = 1;
	this->elapsetFrame = 1;
}

/// <summary>
/// 更新
/// </summary>
void GameTimer::Update()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	auto& character = CharacterManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::TIMER);

	if (!character.GetPlayerInstance().GetIsStop())
	{
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
}

/// <summary>
/// 描画
/// </summary>
const void GameTimer::Draw()const
{
//#ifdef _DEBUG
//	clsDx();
//	printfDx("TIME:%d", this->elapsetTime);
//#endif // _DEBUG

}

