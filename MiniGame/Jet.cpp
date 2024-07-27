#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Jet::Jet()
    : useFlame(0)
    , addCount(0)
    , isInit(false)
{
    /*�V���O���g���N���X�̃C���X�^���X���擾*/
    auto&   asset       = LoadingAsset::GetInstance();
    auto&   json        = JsonManager::GetInstance();
    int     jsonIndex   = json.GetFileNameType(JsonManager::FileNameType::EFFECT);

    /*�摜�n���h���̎擾*/
    for (int i = 0; i < json.GetJson(jsonIndex)["JET_FLAME_NUM"]; i++)
    {
        this->flame[i] = new JetFlame(asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::STAR_YELLOW)));
    }
}

/// <summary>
/// �f�X�g���N�^
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
/// ������
/// </summary>
void Jet::Init()
{
    /*�V���O���g���N���X�̃C���X�^���X���擾*/
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
/// �`��
/// </summary>
void Jet::Update()
{
    /*�V���O���g���N���X�̃C���X�^���X���擾*/
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
/// �`��
/// </summary>
const void Jet::Draw()const
{
    for (int i = 0; i < this->useFlame; i++)
    {
        this->flame[i]->Draw();
    }
}
/// <summary>
/// float�^�̒l�������_���Ŏ擾
/// </summary>
float Jet::GetRandom(const int _range)
{
    /*�����_���l���擾*/
    float out = static_cast<float>(GetRand(_range));

    if (GetRand(1) == 0)
    {
        out *= -1.0f;
    }
    return out;
}

/// <summary>
/// �ړ����x�������_���Ŏ擾
/// </summary>
float Jet::GetRandomVelocity(const int _range)
{
    return static_cast<float>(GetRand(_range));
}

/// <summary>
/// �ړ��x�N�g���������_���Ŏ擾
/// </summary>
WrapVECTOR Jet::GetRandomMoveVec(const float _x,const int _yRange)
{
    float x = _x;
    float randomY = GetRandom(_yRange);
    WrapVECTOR out = { x,randomY,0.0f };
    out = out.Norm();
    return out;
}
