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
	titleCamera = new TitleCamera();
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
void CameraManager::TitleCameraUpdate()
{
	titleCamera->Update();
}