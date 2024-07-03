#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Transform::Transform()
	: pos(0.0f)
	, scale(0.0f)
	, rotate(0.0f)
{
}

/// <summary>
/// メンバ変数に保持されている値の表示
/// </summary>
void Transform::showInfo(const std::string _name)
{
	printfDx(_name.c_str());
	printfDx("POS X:%f,Y:%f,Z:%f\n", pos.value.x, pos.value.y, pos.value.z);
	printfDx("SCALE X:%f,Y:%f,Z:%f\n", scale.value.x, scale.value.y, scale.value.z);
	printfDx("ROTATE X:%f,Y:%f,Z:%f\n", rotate.value.x, rotate.value.y, rotate.value.z);
}
