#include "Common.h"

StageManager* StageManager::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
StageManager::StageManager()
{
	CreateRoad();
	CreateBase();
	CreateBuilding();
	//skydome = new Skydome(asset.GetModel(asset.GetModelType(LoadingAsset::ModelType::SKYDOME)));
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
StageManager::~StageManager()
{
	for (int i = 0; i < frontRoad.size(); i++)
	{
		if (frontRoad[i] != nullptr)
		{
			delete(frontRoad[i]);
			frontRoad[i] = nullptr;
		}
	}
	for (int i = 0; i < backRoad.size(); i++)
	{
		if (backRoad[i] != nullptr)
		{
			delete(backRoad[i]);
			backRoad[i] = nullptr;
		}
	}
	for (int i = 0; i < frontBase.size(); i++)
	{
		if (frontBase[i] != nullptr)
		{
			delete(frontBase[i]);
			frontBase[i] = nullptr;
		}
	}
	for (int i = 0; i < backBase.size(); i++)
	{
		if (backBase[i] != nullptr)
		{
			delete(backBase[i]);
			backBase[i] = nullptr;
		}
	}
	for (int i = 0; i < building.size(); i++)
	{
		if (building[i] != nullptr)
		{
			delete(building[i]);
			building[i] = nullptr;
		}
	}
	if (skydome != nullptr)
	{
		delete(skydome);
		skydome = nullptr;
	}
}
void StageManager::Init()
{
	for (int i = 0; i < frontRoad.size(); i++)
	{
		frontRoad[i]->Init();
	}
	for (int i = 0; i < backRoad.size(); i++)
	{
		backRoad[i]->Init();
	}
	for (int i = 0; i < frontBase.size(); i++)
	{
		frontBase[i]->Init();
	}
	for (int i = 0; i < backBase.size(); i++)
	{
		backBase[i]->Init();
	}
	for (int i = 0; i < building.size(); i++)
	{
		building[i]->Init();
	}
}

/// <summary>
/// �ړ����錚���̐ݒ�
/// </summary>
void StageManager::SetMoveBuildingType()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& timer = GameTimer::GetInstance();
	if (timer.GetElapsetFrame() % 25 == 0)
	{
		int type = 0;
		int falseCount = 0;
		while (1)
		{
			type = GetRand(7);

			if (!building[type]->GetIsMove())
			{
				break;
			}
			falseCount++;
			if (falseCount >= 7)
			{
				break;
			}
		}
		building[type]->OnIsMove();
	}
}
/// <summary>
/// �X�V
/// </summary>
void StageManager::Update()
{
	for (int i = 0; i < frontBase.size(); i++)
	{
		frontBase[i]->Update();
	}
	for (int i = 0; i < backBase.size(); i++)
	{
		backBase[i]->Update();
	}
	for (int i = 0; i < frontRoad.size(); i++)
	{
		frontRoad[i]->Update();
	}
	for (int i = 0; i < backRoad.size(); i++)
	{
		backRoad[i]->Update();
	}
	SetMoveBuildingType();
	for (int i = 0; i < building.size(); i++)
	{
		building[i]->Update();
	}
	//skydome->Update();
}

/// <summary>
/// �`��
/// </summary>
const void StageManager::Draw()const
{
	for (int i = 0; i < frontBase.size(); i++)
	{
		frontBase[i]->Draw();
	}
	for (int i = 0; i < backBase.size(); i++)
	{
		backBase[i]->Draw();
	}
	for (int i = 0; i < building.size(); i++)
	{
		building[i]->Draw();
	}
	for (int i = 0; i < frontRoad.size(); i++)
	{
		frontRoad[i]->Draw();
	}
	for (int i = 0; i < backRoad.size(); i++)
	{
		backRoad[i]->Draw();
	}
}

/// <summary>
/// �����̍쐬
/// </summary>
void StageManager::CreateBuilding()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& asset = LoadingAsset::GetInstance();
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::STAGE);

	this->building.emplace_back(new Building(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::BUILDING_A))));
	this->building.emplace_back(new Building(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::BUILDING_B))));
	this->building.emplace_back(new Building(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::BUILDING_C))));
	this->building.emplace_back(new Building(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::BUILDING_D))));
	this->building.emplace_back(new Building(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::BUILDING_E))));
	this->building.emplace_back(new Building(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::BUILDING_F))));
	this->building.emplace_back(new Building(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::BUILDING_G))));
	this->building.emplace_back(new Building(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::BUILDING_H))));
}

/// <summary>
/// ���̍쐬
/// </summary>
void StageManager::CreateRoad()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& asset = LoadingAsset::GetInstance();
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::STAGE);

	/*�C���X�^���X�̍쐬*/
	WrapVECTOR firstRoadPos = 0.0f;
	WrapVECTOR offset = 0.0f;
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

}

/// <summary>
/// ���̍쐬
/// </summary>
void StageManager::CreateBase()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& asset = LoadingAsset::GetInstance();
	auto& json = JsonManager::GetInstance();
	int		jsonIndex = json.GetFileNameType(JsonManager::FileNameType::STAGE);

	/*�C���X�^���X�̍쐬*/
	WrapVECTOR firstBasePos = 0.0f;
	WrapVECTOR offset = 0.0f;
	offset.Convert(json.GetJson(jsonIndex)["BASE_POS_OFFSET"]);
	firstBasePos.Convert(json.GetJson(jsonIndex)["FIRST_FRONT_BASE_POS"]);
	for (int i = 0; i < json.GetJson(jsonIndex)["FRONT_BASE_NUM"]; i++)
	{
		WrapVECTOR basePos = firstBasePos;
		for (int j = 0; j < i; j++)
		{
			basePos += offset;
		}
		frontBase.emplace_back(new GameStage(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::BASE)), basePos));
	}
	firstBasePos.Convert(json.GetJson(jsonIndex)["FIRST_BACK_BASE_POS"]);
	for (int i = 0; i < json.GetJson(jsonIndex)["BACK_BASE_NUM"]; i++)
	{
		WrapVECTOR basePos = firstBasePos;
		for (int j = 0; j < i; j++)
		{
			basePos += offset;
		}
		backBase.emplace_back(new GameStage(asset.GetModel(static_cast<int>(LoadingAsset::ModelType::BASE)), basePos));
	}

}
