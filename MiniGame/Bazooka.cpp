#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Bazooka::Bazooka(const int _modelHandle)
	: Weapon(_modelHandle)
	, posOffset(0.0f)
{
	Init();
}

/// <summary>
/// デストラクタ
/// </summary>
Bazooka::~Bazooka()
{

}

/// <summary>
/// 初期化
/// </summary>
void Bazooka::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::WEAPON);

	/*メンバ変数の初期化*/
	this->transform.scale	.Convert(json.GetJson(jsonIndex)["BAZOOKA_INIT_SCALE"]);
	this->transform.rotate	.Convert(json.GetJson(jsonIndex)["BAZOOKA_INIT_ROTATE"]);
	this->transform.rotate	.DegToRad(this->transform.rotate);
	this->posOffset			.Convert(json.GetJson(jsonIndex)["BAZOOKA_POS_OFFSET"]);
	/*モデルの設定*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);

}

/// <summary>
/// 更新
/// </summary>
void Bazooka::Update()
{
	WrapVECTOR pos = this->transform.pos + this->posOffset;

	/*モデルの設定*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, pos.value);
}