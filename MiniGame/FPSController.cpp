#include"Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
FPSController::FPSController()
	: fps(0.0f)
	, startTime(0)
	, count(0)
{
}
/// <summary>
/// デストラクタ
/// </summary>
FPSController::~FPSController()
{

}
/// <summary>
/// 初期化
/// </summary>
const void FPSController::Init()
{
	this->fps = 0.0f;
	this->startTime = 0;
	this->count = 0;
}
/// <summary>
/// FPSの平均
/// </summary>
const void FPSController::Ave()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::FPS_CONTROLLER);

	//カウントが０だったらスタートタイムを初期化
	if (this->count == 0)
	{
		this->startTime = GetNowCount();
	}
	//カウントが目標FPSになったら
	if (this->count == json.GetJson(jsonIndex)["TARGET_FPS"])
	{
		//現在の時刻を取得
		int nowTime = GetNowCount();
		//FPS計算
		this->fps = 1000.0 / (static_cast<double>((nowTime - this->startTime)) / json.GetJson(jsonIndex)["TARGET_FPS"]);
		//初期化
		this->startTime = 0;
		this->count = 0;
	}
	else
	{
		this->count++;
	}
}
/// <summary>
/// FPSの描画
/// </summary>
const void FPSController::Draw()
{
#if _DEBUG
	//FPSの描画
	DrawFormatString(1650, 0, GetColor(255,255,255), "FPS:%lg", fps);
#endif // _DEBUG
}
/// <summary>
/// 目標FPSになるよう待機
/// </summary>
const void FPSController::Wait()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::FPS_CONTROLLER);

	//現在の経過時間
	int elapsedTime = GetNowCount() - this->startTime;
	//待機時間
	int waitTime = this->count * 1000 / json.GetJson(jsonIndex)["TARGET_FPS"] - elapsedTime;
	if (waitTime > 0)
	{
		Sleep(waitTime);
	}
}
