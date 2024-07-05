#include "Common.h"

SetUpScreen* SetUpScreen::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
SetUpScreen::SetUpScreen()
{
    Init();
}

/// <summary>
/// デストラクタ
/// </summary>
SetUpScreen::~SetUpScreen()
{

}

int SetUpScreen::Init()
{
    /*Jsonマネージャーのインスタンスの取得*/
    auto& json = JsonManager::GetInstance();
    int jsonFileNum = static_cast<int>(JsonManager::FileNameType::SET_UP_SCREEN);


    /*仮の変数に代入*/
    int windowHeight = json.GetJson(jsonFileNum)["WINDOW_HEIGHT"];
    int windowWidth  = json.GetJson(jsonFileNum)["WINDOW_WIDTH"];
    int colorBit     = json.GetJson(jsonFileNum)["COLOR_BIT"];
	/*画面の作成*/
    SetGraphMode(windowWidth, windowHeight, colorBit);

    /*画面モードをウィンドウモードで描画するか*/
#if _DEBUG
    ChangeWindowMode(TRUE);
#else
    ChangeWindowMode(FALSE);
#endif// _DEBUG

    /*ScreenFlipを実行しても垂直同期信号を待たない*/
    SetWaitVSyncFlag(FALSE);
    
    /*ＤＸライブラリの初期化*/
    if (DxLib_Init() == -1)
    {
        // エラーが発生したら直ちに終了
        return -1;
    }


    /*フラグを立てることで非同期ロードが可能になる*/
    SetUseASyncLoadFlag(TRUE);

    /*描画先を裏画面にする*/
    SetDrawScreen(DX_SCREEN_BACK);
    return 0;
}