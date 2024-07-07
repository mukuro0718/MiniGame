#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
GameStage::GameStage(const int _modelHandle,const WrapVECTOR& _pos)
	: modelHandle	(0)
	, initPos		(0.0f)
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::STAGE);

	/*モデルの複製*/
	this->modelHandle = MV1DuplicateModel(_modelHandle);

	this->initPos = _pos;
	Init();
}
void GameStage::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::STAGE);

	/*トランスフォームの設定*/
	this->transform.scale	.Convert(json.GetJson(jsonIndex)["ROAD_SCALE"]);
	this->transform.rotate	.Convert(json.GetJson(jsonIndex)["ROAD_ROTATE"]);
	this->transform.rotate	.DegToRad(this->transform.rotate);
	this->transform.pos		= this->initPos;

	/*モデルに対する設定*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
}
/// <summary>
/// デストラクタ
/// </summary>
GameStage::~GameStage()
{
}
/// <summary>
/// 更新
/// </summary>
void GameStage::Update()
{
	/*モデルの設定*/
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
}
/// <summary>
/// 描画
/// </summary>
const void GameStage::Draw()const
{
	/*地面の描画*/
	MV1DrawModel(this->modelHandle);
}
