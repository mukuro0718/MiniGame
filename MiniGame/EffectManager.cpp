#include "Common.h"

EffectManager* EffectManager::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
EffectManager::EffectManager()
{
    this->jet = new Jet();
}

/// <summary>
/// デストラクタ
/// </summary>
EffectManager::~EffectManager()
{
	if (this->jet != nullptr)
	{
		delete(this->jet);
		this->jet = nullptr;
	}
}

/// <summary>
/// 更新
/// </summary>
void EffectManager::Update()
{
	jet->Update();
}