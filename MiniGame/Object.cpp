#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Object::Object()
	: radius(0.0f)
	, height(0.0f)
	, hitPosOffset(0.0f)
{
}

/// <summary>
/// �g�����X�t�H�[����getter
/// </summary>
const Transform& Object::GetTransform()const
{ 
	return this->transform;
}

/// <summary>
/// �����蔻����W��getter
/// </summary>
const WrapVECTOR& Object::GetHitPosition()const
{
	WrapVECTOR out = this-> transform.pos;
	out += hitPosOffset;
	return out;
}