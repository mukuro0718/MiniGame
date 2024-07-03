#include "Common.h"

/// <summary>
/// コンストラクタ
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
/// デストラクタ
/// </summary>
Character::~Character()
{
	/*インスタンスの開放*/
	if (this->anim != nullptr)
	{
		delete(this->anim);
		this->anim = nullptr;
	}

	/*モデルハンドルの削除*/
	MV1DeleteModel(this->modelHandle);
}

/// <summary>
/// 描画
/// </summary>
const void Character::Draw()const
{
	MV1DrawModel(this->modelHandle);
}