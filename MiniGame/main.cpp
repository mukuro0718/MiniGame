#include "Common.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    /*�c�w���C�u�����̏�����*/
    if (DxLib_Init() == -1)
    {
        // �G���[�����������璼���ɏI��
        return -1;
    }
    /*�C���X�^���X�̍쐬*/
    JsonLoader::CreateInstance();
    JsonManager::CreateInstance();
    SetUpScreen::CreateInstance();
    LoadingAsset::CreateInstance();
    InputManager::CreateInstance();
    SceneChanger::CreateInstance();
    SceneManager::CreateInstance();
    CameraManager::CreateInstance();
    CharacterManager::CreateInstance();
    WeaponManager::CreateInstance();
    AmoManager::CreateInstance();
    StageManager::CreateInstance();
    GameTimer::CreateInstance();
    BackGround::CreateInstance();
    UIManager::CreateInstance();

    /*�Q�[���{��*/
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        auto& scene = SceneManager::GetInstance();
        scene.Update();
    }

    /*�C���X�^���X�̊J��*/
    GameTimer::DeleteInstance();
    BackGround::DeleteInstance();
    CameraManager::DeleteInstance();
    AmoManager::DeleteInstance();
    WeaponManager::DeleteInstance();
    CharacterManager::DeleteInstance();
    UIManager::DeleteInstance();
    StageManager::DeleteInstance();
    SceneChanger::DeleteInstance();
    InputManager::DeleteInstance();
    LoadingAsset::DeleteInstance();
    SceneManager::DeleteInstance();
    JsonManager::DeleteInstance();
    JsonLoader::DeleteInstance();
    SetUpScreen::DeleteInstance();

    /*�c�w���C�u�����̌�n��*/
    DxLib_End();

    /*�\�t�g�̏I��*/
    return 0;
}