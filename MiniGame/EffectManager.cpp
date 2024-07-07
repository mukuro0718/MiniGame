#include "Common.h"

EffectManager* EffectManager::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
EffectManager::EffectManager()
{
    this->jet		= new Jet();
	this->explosion = new Explosion();
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
	if (this->explosion != nullptr)
	{
		delete(this->explosion);
		this->explosion = nullptr;
	}
}

/// <summary>
/// �X�V
/// </summary>
void EffectManager::Update()
{
	jet->Update();
	explosion->Update();
}