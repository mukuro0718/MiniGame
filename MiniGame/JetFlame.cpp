#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
JetFlame::JetFlame(const int _imageHandle)
    : pos           (0.0f)
    , moveVec       (0.0f)
    , centerX       (0.0f)
    , centerY       (0.0f)
    , size          (0.0f)
    , angle         (0.0f)
    , imageHandle   (0)
{
    /*画像ハンドルの取得*/
    this->imageHandle = _imageHandle;
}

/// <summary>
/// デストラクタ
/// </summary>
JetFlame::~JetFlame()
{

}


void JetFlame::Init(const float _size,const Transform& _in)
{
    /*シングルトンクラスのインスタンスを取得*/
    auto& json = JsonManager::GetInstance();
    int     jsonIndex = json.GetFileNameType(JsonManager::FileNameType::PARTICLE);

    this->centerX = json.GetJson(jsonIndex)["JET_FLAME_CENTER_X"];
    this->centerY = json.GetJson(jsonIndex)["JET_FLAME_CENTER_Y"];
    this->size      = _size;
    this->angle     = 0.0f;
    this->pos = _in.pos;
    this->moveVec.Convert(json.GetJson(jsonIndex)["JET_FLAME_MOVE_VEC"]);
}

/// <summary>
/// 描画
/// </summary>
void JetFlame::Update()
{
    /*移動*/
    Move();

    /*描画*/
    Draw();
}

/// <summary>
/// 移動
/// </summary>
void JetFlame::Move()
{
    this->pos += this->moveVec;
}

/// <summary>
/// 描画
/// </summary>
const void JetFlame::Draw()const
{
    DrawBillboard3D(this->pos.value, this->centerX, this->centerY, this->size, this->angle, this->imageHandle, TRUE);
}