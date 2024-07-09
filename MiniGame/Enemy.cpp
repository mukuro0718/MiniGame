#include "Common.h"

/// <summary>
/// デストラクタ
/// </summary>
Enemy::Enemy(const int _modelHandle)
	: Character(_modelHandle)
	, moveTargetPos(0.0f)
	, isStop(false)
	, breakModelHandle(0)
{
	this->normalModelHandle = MV1DuplicateModel(_modelHandle);
}

/// <summary>
/// デストラクタ
/// </summary>
Enemy::~Enemy()
{

}

/// <summary>
/// 移動
/// </summary>
void Enemy::Move()
{
	if (!this->isStop)
	{
		this->transform.pos.EaseInOutQuint(this->transform.pos, this->moveTargetPos, WrapVECTOR(0.01f));
		WrapVECTOR size = this->transform.pos - this->moveTargetPos;
		if (size.Size() <= 5.0f)
		{
			this->isStop = true;
		}
	}
}

/// <summary>
/// 移動
/// </summary>
void Enemy::MoveOffScreen()
{
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::ENEMY);
	WrapVECTOR targetPos = 0.0f;
	WrapVECTOR percent = 0.0f;
	targetPos.Convert(json.GetJson(jsonIndex)["OFF_SCREEN_TARGET_POS"]);
	percent.Convert(json.GetJson(jsonIndex)["EASE_PERCENT"]);

	this->transform.pos.EaseInOutQuint(this->transform.pos, targetPos, percent);
}