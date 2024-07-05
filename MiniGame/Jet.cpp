#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Jet::Jet()
    : useFlame(0)
    , addCount(0)
{
    /*シングルトンクラスのインスタンスを取得*/
    auto&   asset       = LoadingAsset::GetInstance();
    auto&   json        = JsonManager::GetInstance();
    int     jsonIndex   = json.GetFileNameType(JsonManager::FileNameType::EFFECT);

    /*画像ハンドルの取得*/
    for (int i = 0; i < json.GetJson(jsonIndex)["JET_FLAME_NUM"]; i++)
    {
        this->flame.emplace_back(new JetFlame(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::JET_FLAME))));
    }

    Init();
}

/// <summary>
/// デストラクタ
/// </summary>
Jet::~Jet()
{
    for (int i = 0; i < this->flame.size(); i++)
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
    for (int i = 0; i < this->flame.size(); i++)
    {
        this->flame[i]->Init(json.GetJson(jsonIndex)["JET_FLAME_SIZE"], character.GetPlayerTransform());
    }
    this->useFlame = 0;
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

    for (int i = 0; i < this->useFlame; i++)
    {
        if (flame[i]->GetPos().value.x <= json.GetJson(jsonIndex)["JET_FLAME_X"])
        {
            flame[i]->Init(10.0f, character.GetPlayerTransform());
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