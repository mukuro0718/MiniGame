#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Building::Building(const int _modelHandle)
	: modelHandle(0)
	, isMove(false)
{
	this->modelHandle = MV1DuplicateModel(_modelHandle);
	Init();
}

/// <summary>
/// デストラクタ
/// </summary>
Building::~Building()
{

}

/// <summary>
/// 初期化
/// </summary>
void Building::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::STAGE);
	this->transform.pos.Convert(json.GetJson(jsonIndex)["BUILDING_POS"]);
	this->transform.rotate.Convert(json.GetJson(jsonIndex)["BUILDING_ROTATE"]);
	this->transform.scale.Convert(json.GetJson(jsonIndex)["BUILDING_SCALE"]);

	this->isMove = false;
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);

}

/// <summary>
/// 更新
/// </summary>
void Building::Update()
{
	if (this->isMove)
	{
 		this->transform.pos.value.x -= 2.0f;
		if (this->transform.pos.value.x <= -240.0f)
		{
			Init();
		}
	}
	MV1SetScale			(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ	(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition		(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// 描画
/// </summary>
const void Building::Draw()const
{
	MV1DrawModel(this->modelHandle);
}