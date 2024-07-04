#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Character::Character(const int _modelHandle)
	: hitResult			(nullptr)
	, moveVec			(0.0f)
	, fixVec			(0.0f)
	, initPos			(0.0f)
	, radius			(0.0f)
	, modelHandle		(0)
{
	this->hitResult = new HitResult();
	this->modelHandle = MV1DuplicateModel(_modelHandle);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Character::~Character()
{
	/*�C���X�^���X�̊J��*/
	if (this->hitResult != nullptr)
	{
		delete(this->hitResult);
		this->hitResult = nullptr;
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