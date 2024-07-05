#include "Common.h"

GemManager* GemManager::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
GemManager::GemManager()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& asset = LoadingAsset::GetInstance();
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::GEM);

	/*インスタンスの作成*/
	for (int i = 0; i < json.GetJson(jsonIndex)["MAX_GEM_NUM"]; i++)
	{
		this->gem.emplace_back(new Gem(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::GEM_1)),100));
	}
	this->specialGem = new Gem(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::GEM_2)),1000);

	vector<vector<float>> patternPos = json.GetJson(jsonIndex)["BOTTOM_PATTERN"];
	WrapVECTOR addPos = 0.0f;
	for (int i = 0; i < patternPos.size(); i++)
	{
		addPos = patternPos[i];
		this->gem[i]->SetPos(addPos);
		this->useCurrentlyNum++;
	}
	patternPos.clear();
}

/// <summary>
/// デストラクタ
/// </summary>
GemManager::~GemManager()
{
	for (int i = 0; i < this->gem.size(); i++)
	{
		if (this->gem[i] != nullptr)
		{
			delete(this->gem[i]);
			this->gem[i] = nullptr;
		}
	}
	this->gem.clear();
}

/// <summary>
/// 更新
/// </summary>
void GemManager::Update()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& timer = GameTimer::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::GEM);

	/*経過フレームが０かつ目標の時間だったら*/
	if (timer.GetElapsetFrame() == 0 && timer.GetElapsetTime() % json.GetJson(jsonIndex)["TARGET_TIME"] == 0)
	{
		InitUseGem();
		SetUseGem();
	}

	for (int i = 0; i < this->useCurrentlyNum; i++)
	{
		this->gem[i]->Update();
	}
}

/// <summary>
/// 使用しているジェムの初期化
/// </summary>
void GemManager::InitUseGem()
{
	for (int i = 0; i < this->useCurrentlyNum; i++)
	{
		this->gem[i]->Init();
	}
	this->useCurrentlyNum = 0;
}

/// <summary>
/// 使用しているジェムの初期化
/// </summary>
void GemManager::SetUseGem()
{
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::GEM);

	vector<vector<float>> patternPos;
	switch (GetRand(json.GetJson(jsonIndex)["PATTERN_NUM"]))
	{
	case static_cast<int>(PatternType::CENTER):
		patternPos = json.GetJson(jsonIndex)["CENTER_PATTERN"];
		break;
	case static_cast<int>(PatternType::BOTTOM):
		patternPos = json.GetJson(jsonIndex)["BOTTOM_PATTERN"];
		break;
	case static_cast<int>(PatternType::TOP):
		patternPos = json.GetJson(jsonIndex)["TOP_PATTERN"];
		break;
	case static_cast<int>(PatternType::UP):
		patternPos = json.GetJson(jsonIndex)["UP_PATTERN"];
		break;
	case static_cast<int>(PatternType::DOWN):
		patternPos = json.GetJson(jsonIndex)["DOWN_PATTERN"];
		break;
	}

	WrapVECTOR addPos = 0.0f;
	for (int i = 0; i < patternPos.size(); i++)
	{
		addPos = patternPos[i];
		this->gem[i]->SetPos(addPos);
		this->useCurrentlyNum++;
	}
	patternPos.clear();
}

const Gem& GemManager::GetGemInstance(const int _index)const
{
	return *this->gem[_index];
}

const bool GemManager::GetGemIsHit(const int _index)const
{
	return this->gem[_index]->GetIsHit();
}
const bool GemManager::GetGemIsSet(const int _index)const
{
	return this->gem[_index]->GetIsSet();
}
