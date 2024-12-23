#include "Common.h"
/// <summary>
/// コンストラクタ
/// </summary>
GameCamera::GameCamera()
	: Object()
	, pos		(0.0f)
	, targetPos	(0.0f)
{
	/*初期化*/
	Init();
}
/// <summary>
/// デストラクタ
/// </summary>
GameCamera::~GameCamera()
{
	//処理なし
}
/// <summary>
/// 初期化
/// </summary>
void GameCamera::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::CAMERA);

	SetCameraNearFar(json.GetJson(jsonIndex)["CAMERA_NEAR"], json.GetJson(jsonIndex)["CAMERA_FAR"]);
}
/// <summary>
/// 更新
/// </summary>
void GameCamera::Update()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	auto& chara = CharacterManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::CAMERA);
	WrapVECTOR origin = 0;
	origin.Convert(json.GetJson(jsonIndex)["ORIGIN"]);
	/*座標の更新*/
	this->targetPos = /*chara.GetPlayerPos()*/origin;
	/*this->targetPos.Add(json.GetJson(jsonIndex)["TARGET_POS_OFFSET"]);*/
	this->transform.pos = origin.Add(json.GetJson(jsonIndex)["CAMERA_OFF_SET"]);
	
	/*カメラの設定*/
	SetCameraPositionAndTargetAndUpVec(this->transform.pos.value, this->targetPos.value, VGet(0.0f, 1.0f, 0.0f));
}