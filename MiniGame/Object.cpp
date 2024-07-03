#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Object::Object()
	: radius(0.0f)
	, height(0.0f)
	, hitPosOffset(0.0f)
{
}

/// <summary>
/// トランスフォームのgetter
/// </summary>
const Transform& Object::GetTransform()const
{ 
	return this->transform;
}

/// <summary>
/// 当たり判定座標のgetter
/// </summary>
const WrapVECTOR& Object::GetHitPosition()const
{
	WrapVECTOR out = this-> transform.pos;
	out += hitPosOffset;
	return out;
}