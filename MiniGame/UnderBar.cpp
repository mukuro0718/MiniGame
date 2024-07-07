#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
UnderBar::UnderBar()
{
    /*シングルトンクラスのインスタンスの取得*/
    auto& json = JsonManager::GetInstance();
    auto& asset = LoadingAsset::GetInstance();
    int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::UI);

    this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::PREV_BAR)));
    this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::NOW_BAR)));
    this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::CAR)));
    this->imageHandle.emplace_back(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::HOUSE)));

    DrawRect origin;

    for (int i = 0; i < imageHandle.size(); i++)
    {
        this->pos.emplace_back(DrawRect());
    }
    Convert(this->pos[static_cast<int>(ImageType::PREV)], json.GetJson(jsonIndex)["UNDER_BAR_POS"]);
    Convert(this->pos[static_cast<int>(ImageType::NOW)], json.GetJson(jsonIndex)["UNDER_BAR_POS"]);
    Convert(this->pos[static_cast<int>(ImageType::CAR)], json.GetJson(jsonIndex)["CAR_POS"]);
    Convert(this->pos[static_cast<int>(ImageType::HOUSE)], json.GetJson(jsonIndex)["HOUCE_POS"]);

    Init();
}

/// <summary>
/// デストラクタ
/// </summary>
UnderBar::~UnderBar()
{

}

/// <summary>
/// 初期化
/// </summary>
void UnderBar::Init()
{

}

/// <summary>
/// 更新
/// </summary>
void UnderBar::Update()
{
}

/// <summary>
/// 描画
/// </summary>
const void UnderBar::Draw()const
{
    /*バーの描画*/
    for (int i = 0; i < imageHandle.size(); i++)
    {
        DrawExtendGraph(pos[i].lx, pos[i].ly, pos[i].rx, pos[i].ry, imageHandle[i], TRUE);
    }
}


void UnderBar::Convert(DrawRect& _pos, const vector<int> _in)
{
    _pos.lx = _in[0];
    _pos.ly = _in[1];
    _pos.rx = _in[2];
    _pos.ry = _in[3];
}
