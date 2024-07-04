#include "Common.h"

/// <summary>
/// コンストラクタ
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
/// デストラクタ
/// </summary>
Character::~Character()
{
	/*インスタンスの開放*/
	if (this->hitResult != nullptr)
	{
		delete(this->hitResult);
		this->hitResult = nullptr;
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