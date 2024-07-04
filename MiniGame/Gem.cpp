#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Gem::Gem(const int _modelHandle,const int _price)
    : isSet(false)
    , modelHandle(0)
    , price(0)
{
    this->modelHandle = MV1DuplicateModel(_modelHandle);
    this->price = _price;
    Init();
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
    auto&   json        = JsonManager::GetInstance();
    int     jsonIndex   = json.GetFileNameType(JsonManager::FileNameType::GEM);
    this->transform.pos     .Convert(json.GetJson(jsonIndex)["INIT_POS"]);
    this->transform.scale   .Convert(json.GetJson(jsonIndex)["INIT_SCALE"]);
    this->transform.rotate  .Convert(json.GetJson(jsonIndex)["INIT_ROTATE"]);
    this->transform.rotate  .DegToRad(this->transform.rotate);
    this->isSet = false;
    
    /*モデルの設定*/
    MV1SetScale(this->modelHandle, this->transform.scale.value);
    MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
    MV1SetPosition(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// 更新
/// </summary>
void Gem::Update()
{
    Move();

    /*モデルの設定*/
    MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
    MV1SetPosition(this->modelHandle, this->transform.pos.value);

    /*描画*/
    Draw();
}

/// <summary>
/// 移動
/// </summary>
void Gem::Move()
{
    /*シングルトンクラスのインスタンスの取得*/
    auto& json = JsonManager::GetInstance();
    int     jsonIndex = json.GetFileNameType(JsonManager::FileNameType::GEM);

    this->transform.pos.value.x += json.GetJson(jsonIndex)["MOVE_VELOCITY"];

    if (this->transform.pos.value.x <= json.GetJson(jsonIndex)["STOP_MOVE_X_POS"])
    {
        this->transform.pos.value.x = json.GetJson(jsonIndex)["STOP_MOVE_X_POS"];
    }
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
    this->isSet = true;
}
