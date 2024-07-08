#include "Common.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    /*�C���X�^���X�̍쐬*/
    JsonLoader::CreateInstance();
    JsonManager::CreateInstance();
    SetUpScreen::CreateInstance();
    LoadingAsset::CreateInstance();
    BackGround::CreateInstance();
    InputManager::CreateInstance();
    SceneChanger::CreateInstance();
    SceneManager::CreateInstance();
    CameraManager::CreateInstance();
    CharacterManager::CreateInstance();
    WeaponManager::CreateInstance();
    AmoManager::CreateInstance();
    GemManager::CreateInstance();
    StageManager::CreateInstance();
    GameTimer::CreateInstance();
    Collision::CreateInstance();
    UIManager::CreateInstance();
    EffectManager::CreateInstance();

    /*�Q�[���{��*/
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        auto& scene = SceneManager::GetInstance();
        scene.Update();
    }

    /*�C���X�^���X�̊J��*/
    Collision::DeleteInstance();
    GameTimer::DeleteInstance();
    BackGround::DeleteInstance();
    CameraManager::DeleteInstance();
    GemManager::DeleteInstance();
    AmoManager::DeleteInstance();
    WeaponManager::DeleteInstance();
    CharacterManager::DeleteInstance();
    UIManager::DeleteInstance();
    EffectManager::DeleteInstance();
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