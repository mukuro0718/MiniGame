#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Jet::Jet()
    : useFlame(0)
    , addCount(0)
    , isInit(false)
{
    /*シングルトンクラスのインスタンスを取得*/
    auto&   asset       = LoadingAsset::GetInstance();
    auto&   json        = JsonManager::GetInstance();
    int     jsonIndex   = json.GetFileNameType(JsonManager::FileNameType::EFFECT);

    /*画像ハンドルの取得*/
    for (int i = 0; i < json.GetJson(jsonIndex)["JET_FLAME_NUM"]; i++)
    {
        this->flame[i] = new JetFlame(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::STAR_YELLOW)));
    }
}

/// <summary>
/// デストラクタ
/// </summary>
Jet::~Jet()
{
    for (int i = 0; i < this->FLAME_NUM; i++)
    {
        if (this->flame[i] != nullptr)
        {
            delete(this->flame[i]);
            this->flame[i] = nullptr;
        }
    }
}

/// <summary>
/// 初期化
/// </summary>
void Jet::Init()
{
    /*シングルトンクラスのインスタンスを取得*/
    auto& json = JsonManager::GetInstance();
    int     jsonIndex = json.GetFileNameType(JsonManager::FileNameType::EFFECT);
    auto& character = CharacterManager::GetInstance();
    for (int i = 0; i < this->FLAME_NUM; i++)
    {
        this->flame[i]->Init
        (
            json.GetJson(jsonIndex)["JET_FLAME_SIZE"],
            character.GetPlayerTransform().pos,
            GetRandomMoveVec(json.GetJson(jsonIndex)["JET_FLAME_MOVE_X"], json.GetJson(jsonIndex)["JET_FLAME_MOVE_Y"]),
            GetRandomVelocity(json.GetJson(jsonIndex)["JET_FLAME_VELOCITY"])
        );
    }
    this->useFlame = 0;
    this->isInit = true;
}

/// <summary>
/// 描画
/// </summary>
void Jet::Update()
{
    /*シングルトンクラスのインスタンスを取得*/
    auto& json = JsonManager::GetInstance();
    int     jsonIndex = json.GetFileNameType(JsonManager::FileNameType::EFFECT);
    auto& character = CharacterManager::GetInstance();

    if (character.GetPlayerInstance().GetIsStop()) return;
    
    if (!this->isInit)
    {
        for (int i = 0; i < this->FLAME_NUM; i++)
        {
            this->flame[i]->Init
            (
                json.GetJson(jsonIndex)["JET_FLAME_SIZE"],
                character.GetPlayerTransform().pos,
                GetRandomMoveVec(json.GetJson(jsonIndex)["JET_FLAME_MOVE_X"], json.GetJson(jsonIndex)["JET_FLAME_MOVE_Y"]),
                GetRandomVelocity(json.GetJson(jsonIndex)["JET_FLAME_VELOCITY"])
            );
        }
    }

    for (int i = 0; i < this->useFlame; i++)
    {
        if (flame[i]->GetPos().value.x <= json.GetJson(jsonIndex)["JET_FLAME_X"])
        {
            flame[i]->Init
            (
                json.GetJson(jsonIndex)["JET_FLAME_SIZE"],
                character.GetPlayerTransform().pos,
                GetRandomMoveVec(json.GetJson(jsonIndex)["JET_FLAME_MOVE_X"], json.GetJson(jsonIndex)["JET_FLAME_MOVE_Y"]),
                GetRandomVelocity(json.GetJson(jsonIndex)["JET_FLAME_VELOCITY"])
            );
        }
        this->flame[i]->Update();
    }

    if (this->useFlame != json.GetJson(jsonIndex)["JET_FLAME_NUM"])
    {
        this->addCount++;
        if (this->addCount % 2 == 0)
        {
            this->useFlame++;
        }
    }
}

/// <summary>
/// 描画
/// </summary>
const void Jet::Draw()const
{
    for (int i = 0; i < this->useFlame; i++)
    {
        this->flame[i]->Draw();
    }
}
/// <summary>
/// float型の値をランダムで取得
/// </summary>
float Jet::GetRandom(const int _range)
{
    /*ランダム値を取得*/
    float out = static_cast<float>(GetRand(_range));

    if (GetRand(1) == 0)
    {
        out *= -1.0f;
    }
    return out;
}

/// <summary>
/// 移動速度をランダムで取得
/// </summary>
float Jet::GetRandomVelocity(const int _range)
{
    return static_cast<float>(GetRand(_range));
}

/// <summary>
/// 移動ベクトルをランダムで取得
/// </summary>
WrapVECTOR Jet::GetRandomMoveVec(const float _x,const int _yRange)
{
    float x = _x;
    float randomY = GetRandom(_yRange);
    WrapVECTOR out = { x,randomY,0.0f };
    out = out.Norm();
    return out;
}
