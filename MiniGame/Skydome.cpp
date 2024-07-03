#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Skydome::Skydome(const int _modelHandle)
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::SKYDOME);

	/*トランスフォームの設定*/
	this->transform.pos.Convert(json.GetJson(jsonIndex)["ORIGIN"]);
	this->transform.scale.Convert(json.GetJson(jsonIndex)["SCALE"]);
	this->transform.rotate.Convert(json.GetJson(jsonIndex)["ROTATE"]);

	/*モデルの複製*/
	this->modelHandle = MV1DuplicateModel(_modelHandle);

	/*モデルの設定*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// デストラクタ
/// </summary>
Skydome::~Skydome()
{

}

/// <summary>
/// 初期化
/// </summary>
void Skydome::Init()
{

}

/// <summary>
/// 更新
/// </summary>
void Skydome::Update()
{

	/*描画*/
	Draw();
}

/// <summary>
/// 描画
/// </summary>
const void Skydome::Draw()const
{
	MV1DrawModel(this->modelHandle);
}