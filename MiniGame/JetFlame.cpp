#include "Common.h"

/// <summary>
/// �R���X�g���N�^
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
    /*�摜�n���h���̎擾*/
    this->imageHandle = _imageHandle;
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
JetFlame::~JetFlame()
{

}


void JetFlame::Init(const float _size,const Transform& _in)
{
    /*�V���O���g���N���X�̃C���X�^���X���擾*/
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
/// �`��
/// </summary>
void JetFlame::Update()
{
    /*�ړ�*/
    Move();

    /*�`��*/
    Draw();
}

/// <summary>
/// �ړ�
/// </summary>
void JetFlame::Move()
{
    this->pos += this->moveVec;
}

/// <summary>
/// �`��
/// </summary>
const void JetFlame::Draw()const
{
    DrawBillboard3D(this->pos.value, this->centerX, this->centerY, this->size, this->angle, this->imageHandle, TRUE);
}