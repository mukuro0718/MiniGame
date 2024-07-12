#include "Common.h"
/// <summary>
/// コンストラクタ
/// </summary>
ResultCamera::ResultCamera()
	: pos(0.0f)
	, targetPos(0.0f)
{
	/*初期化*/
	Init();
}
/// <summary>
/// デストラクタ
/// </summary>
ResultCamera::~ResultCamera()
{
	//処理なし
}
/// <summary>
/// 初期化
/// </summary>
void ResultCamera::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::CAMERA);

	SetCameraNearFar(json.GetJson(jsonIndex)["CAMERA_NEAR"], json.GetJson(jsonIndex)["CAMERA_FAR"]);
}
/// <summary>
/// ゲームクリア時更新
/// </summary>
void ResultCamera::ClearUpdate()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	auto& chara = CharacterManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::CAMERA);
	WrapVECTOR target = 0;
	target.Convert(json.GetJson(jsonIndex)["ORIGIN"]);
	/*座標の更新*/
	this->targetPos = target;

	this->pos = target.Add(json.GetJson(jsonIndex)["CLEAR_CAMERA_OFFSET"]);

	/*カメラの設定*/
	SetCameraPositionAndTargetAndUpVec(this->pos.value, this->targetPos.value, VGet(0.0f, 1.0f, 0.0f));
}
/// <summary>
/// ゲームオーバー時更新
/// </summary>
void ResultCamera::OverUpdate()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	auto& chara = CharacterManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::CAMERA);
	WrapVECTOR target = 0;
	target = chara.GetPlayerPos();
	/*座標の更新*/
	this->targetPos = target.Add(json.GetJson(jsonIndex)["OVER_TARGET_OFFSET"]);

	this->pos = target.Add(json.GetJson(jsonIndex)["OVER_CAMERA_OFFSET"]);

	/*カメラの設定*/
	SetCameraPositionAndTargetAndUpVec(this->pos.value, this->targetPos.value, VGet(0.0f, 1.0f, 0.0f));
}