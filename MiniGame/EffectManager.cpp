#include "Common.h"

EffectManager* EffectManager::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
EffectManager::EffectManager()
	: jet(nullptr)
	, explosion(nullptr)
{
	this->jet = new Jet();
	this->explosion = new Explosion();
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
	if (this->explosion != nullptr)
	{
		delete(this->explosion);
		this->explosion = nullptr;
	}
}

/// <summary>
/// 初期化
/// </summary>
void EffectManager::Init()
{
	jet->Init();
	explosion->Init();
}

/// <summary>
/// 更新
/// </summary>
void EffectManager::Update()
{
	jet->Update();
	explosion->Update();
}

/// <summary>
/// 描画
/// </summary>
const void EffectManager::Draw()const
{
	auto& character = CharacterManager::GetInstance();

		jet->Draw();
		explosion->Draw();
}