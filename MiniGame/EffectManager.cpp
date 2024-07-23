#include "Common.h"

EffectManager* EffectManager::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
EffectManager::EffectManager()
	: jet(nullptr)
	, explosion(nullptr)
{
	this->jet = new Jet();
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
/// ������
/// </summary>
void EffectManager::Init()
{
	jet->Init();
	explosion->Init();
}

/// <summary>
/// �X�V
/// </summary>
void EffectManager::Update()
{
	jet->Update();
	explosion->Update();
}

/// <summary>
/// �`��
/// </summary>
const void EffectManager::Draw()const
{
	auto& character = CharacterManager::GetInstance();

		jet->Draw();
		explosion->Draw();
}