#include "Common.h"

CameraManager* CameraManager::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
CameraManager::CameraManager()
	:camera(nullptr)
{
	/*�C���X�^���X�̍쐬*/
	camera = new GameCamera();
	resultCamera = new ResultCamera();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CameraManager::~CameraManager()
{

}

/// <summary>
/// �X�V
/// </summary>
void CameraManager::Update()
{
	camera->Update();
}

/// <summary>
/// �X�V
/// </summary>
void CameraManager::ClearCameraUpdate()
{
	resultCamera->ClearUpdate();
}
/// <summary>
/// �X�V
/// </summary>
void CameraManager::OverCameraUpdate()
{
	resultCamera->OverUpdate();
}