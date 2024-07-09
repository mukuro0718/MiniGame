#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
House::House(const int _modelHandle)
{

}

/// <summary>
/// デストラクタ
/// </summary>
House::~House()
{

}

/// <summary>
/// 初期化
/// </summary>
void House::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::STAGE);

	this->transform.pos.Convert(json.GetJson(jsonIndex)["HOUSE_POS"]);
	this->transform.rotate.Convert(json.GetJson(jsonIndex)["HOUSE_ROTATE"]);
	this->transform.scale.Convert(json.GetJson(jsonIndex)["HOUSE_SCALE"]);

}

/// <summary>
/// 更新
/// </summary>
void House::Update()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& timer = GameTimer::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::STAGE);

	if (timer.GetElapsetTime() >= json.GetJson(jsonIndex)["TARGET_TIME"])
	{
		this->transform.pos.value.x--;
		if (this->transform.pos.value.x <= json.GetJson(jsonIndex)["TARGET_TIME"])
		{
			this->transform.pos.value.x = json.GetJson(jsonIndex)["TARGET_TIME"];
		}
	}


	/*モデルの設定*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// 描画
/// </summary>
const void House::Draw()const
{
	MV1DrawModel(this->modelHandle);
}