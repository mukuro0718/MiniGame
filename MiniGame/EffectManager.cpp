#include "Common.h"

EffectManager* EffectManager::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
EffectManager::EffectManager()
{
    this->jet = new Jet();
}

/// <summary>
/// �f�X�g���N�^
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
/// �X�V
/// </summary>
void EffectManager::Update()
{
	jet->Update();
}