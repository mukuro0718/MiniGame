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