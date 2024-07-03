#include "Common.h"

StageManager* StageManager::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
StageManager::StageManager()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto&	asset		= LoadingAsset::GetInstance();
	auto&	json		= JsonManager::GetInstance();
	int		jsonIndex	= json.GetFileNameType(JsonManager::FileNameType::STAGE);

	/*�C���X�^���X�̍쐬*/
	WrapVECTOR firstRoadPos = 0.0f;
	WrapVECTOR offset		= 0.0f;
	offset.Convert(json.GetJson(jsonIndex)["ROAD_POS_OFFSET"]);
	firstRoadPos.Convert(json.GetJson(jsonIndex)["FIRST_FRONT_ROAD_POS"]);
	for (int i = 0; i < json.GetJson(jsonIndex)["FRONT_ROAD_NUM"]; i++)
	{
		WrapVECTOR roadPos = firstRoadPos;
		for (int j = 0; j < i; j++)
		{
			roadPos += offset;
		}
		frontRoad.emplace_back(new GameStage(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::ROAD)), roadPos));
	}
	firstRoadPos.Convert(json.GetJson(jsonIndex)["FIRST_BACK_ROAD_POS"]);
	for (int i = 0; i < json.GetJson(jsonIndex)["BACK_ROAD_NUM"]; i++)
	{
		WrapVECTOR roadPos = firstRoadPos;
		for (int j = 0; j < i; j++)
		{
			roadPos += offset;
		}
		backRoad.emplace_back(new GameStage(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::ROAD)), roadPos));
	}
	skydome = new Skydome(asset.GetModel(asset.GetModelType(LoadingAsset::ModelType::SKYDOME)));
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
StageManager::~StageManager()
{

}

/// <summary>
/// �X�V
/// </summary>
void StageManager::Update()
{
	for (int i = 0; i < frontRoad.size(); i++)
	{
		frontRoad[i]->Update();
	}
	for (int i = 0; i < backRoad.size(); i++)
	{
		backRoad[i]->Update();
	}
	//skydome->Update();
}

