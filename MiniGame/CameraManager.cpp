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
	resultCamera = new ResultCamera();
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
void CameraManager::ClearCameraUpdate()
{
	resultCamera->ClearUpdate();
}
/// <summary>
/// 更新
/// </summary>
void CameraManager::OverCameraUpdate()
{
	resultCamera->OverUpdate();
}