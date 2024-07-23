#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Character::Character(const int _modelHandle)
	: moveVec			(0.0f)
	, fixVec			(0.0f)
	, initPos			(0.0f)
	, radius			(0.0f)
	, modelHandle		(0)
	, shadow			(nullptr)
{
	this->modelHandle = MV1DuplicateModel(_modelHandle);
	shadow = new Shadow();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Character::~Character()
{
	/*���f���n���h���̍폜*/
	MV1DeleteModel(this->modelHandle);
}

/// <summary>
/// �`��
/// </summary>
const void Character::Draw()const
{
	MV1DrawModel(this->modelHandle);
//#ifdef _DEBUG
//	WrapVECTOR centerPos = this->transform.pos;
//	centerPos += this->hitPosOffset;
//
//	DrawSphere3D(centerPos.value, this->radius, 16, GetColor(0, 255, 255), GetColor(0, 255, 255), FALSE);
//#endif // _DEBUG

}