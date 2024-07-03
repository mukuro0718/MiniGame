#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Weapon::Weapon(const int _modelHandle)
	:Object()
{
	this->modelHandle = MV1DuplicateModel(_modelHandle);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Weapon::~Weapon()
{

}

/// <summary>
/// ���W��setter
/// </summary>
void Weapon::SetPos(const WrapVECTOR& _pos)
{
	this->transform.pos = _pos;
}

/// <summary>
/// �`��
/// </summary>
const void Weapon::Draw()const
{
	MV1DrawModel(this->modelHandle);
}