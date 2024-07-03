#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Character::Character(const int _modelHandle)
	: anim				(nullptr)
	, moveVec			(0.0f)
	, fixVec			(0.0f)
	, initPos			(0.0f)
	, radius			(0.0f)
	, modelHandle		(0)
{
	this->anim = new Animation();
	this->modelHandle = MV1DuplicateModel(_modelHandle);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Character::~Character()
{
	/*�C���X�^���X�̊J��*/
	if (this->anim != nullptr)
	{
		delete(this->anim);
		this->anim = nullptr;
	}

	/*���f���n���h���̍폜*/
	MV1DeleteModel(this->modelHandle);
}

/// <summary>
/// �`��
/// </summary>
const void Character::Draw()const
{
	MV1DrawModel(this->modelHandle);
}