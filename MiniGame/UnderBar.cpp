#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
UnderBar::UnderBar()
{
    /*�V���O���g���N���X�̃C���X�^���X�̎擾*/
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
/// �f�X�g���N�^
/// </summary>
UnderBar::~UnderBar()
{

}

/// <summary>
/// ������
/// </summary>
void UnderBar::Init()
{

}

/// <summary>
/// �X�V
/// </summary>
void UnderBar::Update()
{
}

/// <summary>
/// �`��
/// </summary>
const void UnderBar::Draw()const
{
    /*�o�[�̕`��*/
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
