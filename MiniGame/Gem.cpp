#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Gem::Gem(const int _modelHandle,const int _price)
{
    this->modelHandle = MV1DuplicateModel(_modelHandle);
    this->price = _price;
}

/// <summary>
/// デストラクタ
/// </summary>
Gem::~Gem()
{

}

/// <summary>
/// 初期化
/// </summary>
void Gem::Init()
{
    /*シングルトンクラスのインスタンスの取得*/
    auto& json = JsonManager::GetInstance();
    int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::GEM);
    this->transform.pos.Convert(json.GetJson(jsonIndex)["INIT_POS"]);
    this->transform.scale.Convert(json.GetJson(jsonIndex)["INIT_SCALE"]);
    this->transform.rotate.Convert(json.GetJson(jsonIndex)["INIT_ROTATE"]);
    this->transform.rotate.DegToRad(this->transform.rotate);
}

/// <summary>
/// 更新
/// </summary>
void Gem::Update()
{

}

/// <summary>
/// 描画
/// </summary>
const void Gem::Draw()const
{
    MV1DrawModel(this->modelHandle);
}

const void Gem::SetPrice(const int _in)
{
    this->price = _in;
}

const void Gem::SetPos(const WrapVECTOR& _in)
{
    this->transform.pos = _in;
}
