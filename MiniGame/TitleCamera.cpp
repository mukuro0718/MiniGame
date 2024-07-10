#include "Common.h"
/// <summary>
/// コンストラクタ
/// </summary>
TitleCamera::TitleCamera()
	: Object()
	, pos(0.0f)
	, targetPos(0.0f)
{
	/*初期化*/
	Init();
}
/// <summary>
/// デストラクタ
/// </summary>
TitleCamera::~TitleCamera()
{
	//処理なし
}
/// <summary>
/// 初期化
/// </summary>
void TitleCamera::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::CAMERA);

	SetCameraNearFar(json.GetJson(jsonIndex)["CAMERA_NEAR"], json.GetJson(jsonIndex)["CAMERA_FAR"]);
}
/// <summary>
/// 更新
/// </summary>
void TitleCamera::Update()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	auto& chara = CharacterManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::CAMERA);
	WrapVECTOR origin = 0;
	origin.Convert(json.GetJson(jsonIndex)["TITLE_CAMERA_TARGET"]);
	/*座標の更新*/
	this->targetPos = origin;

	this->transform.pos = origin.Add(json.GetJson(jsonIndex)["TITLE_CAMERA_OFF_SET"]);

	/*カメラの設定*/
	SetCameraPositionAndTargetAndUpVec(this->transform.pos.value, this->targetPos.value, VGet(0.0f, 1.0f, 0.0f));
}