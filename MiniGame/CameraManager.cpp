#include "Common.h"

CameraManager* CameraManager::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
CameraManager::CameraManager()
	:camera(nullptr)
{
	/*インスタンスの作成*/
	camera = new GameCamera();
	titleCamera = new TitleCamera();
}

/// <summary>
/// デストラクタ
/// </summary>
CameraManager::~CameraManager()
{

}

/// <summary>
/// 更新
/// </summary>
void CameraManager::Update()
{
	camera->Update();
}

/// <summary>
/// 更新
/// </summary>
void CameraManager::TitleCameraUpdate()
{
	titleCamera->Update();
}