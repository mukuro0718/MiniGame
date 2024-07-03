#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Weapon::Weapon(const int _modelHandle)
	:Object()
{
	this->modelHandle = MV1DuplicateModel(_modelHandle);
}

/// <summary>
/// デストラクタ
/// </summary>
Weapon::~Weapon()
{

}

/// <summary>
/// 座標のsetter
/// </summary>
void Weapon::SetPos(const WrapVECTOR& _pos)
{
	this->transform.pos = _pos;
}

/// <summary>
/// 描画
/// </summary>
const void Weapon::Draw()const
{
	MV1DrawModel(this->modelHandle);
}