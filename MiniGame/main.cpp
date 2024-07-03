#include "Common.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    /*ＤＸライブラリの初期化*/
    if (DxLib_Init() == -1)
    {
        // エラーが発生したら直ちに終了
        return -1;
    }
    /*インスタンスの作成*/
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

    /*ゲーム本編*/
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        auto& scene = SceneManager::GetInstance();
        scene.Update();
    }

    /*インスタンスの開放*/
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

    /*ＤＸライブラリの後始末*/
    DxLib_End();

    /*ソフトの終了*/
    return 0;
}