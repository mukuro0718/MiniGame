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
	Init();
	this->transform.pos = _pos;
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
	this->transform.pos.value.x = 240.0f;
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
	this->transform.pos.value.x -= 2.0f;
	if (this->transform.pos.value.x <= -240.0f)
	{
		Init();
	}
	/*モデルの設定*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
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
