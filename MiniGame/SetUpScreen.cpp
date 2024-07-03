#include "Common.h"

SetUpScreen* SetUpScreen::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
SetUpScreen::SetUpScreen()
{
    Init();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
SetUpScreen::~SetUpScreen()
{

}

void SetUpScreen::Init()
{
    /*Json�}�l�[�W���[�̃C���X�^���X�̎擾*/
    auto& json = JsonManager::GetInstance();
    int jsonFileNum = static_cast<int>(JsonManager::FileNameType::SET_UP_SCREEN);


    /*���̕ϐ��ɑ��*/
    int windowHeight = json.GetJson(jsonFileNum)["WINDOW_HEIGHT"];
    int windowWidth  = json.GetJson(jsonFileNum)["WINDOW_WIDTH"];
    int colorBit     = json.GetJson(jsonFileNum)["COLOR_BIT"];

	/*��ʂ̍쐬*/
    SetGraphMode(windowWidth, windowHeight, colorBit);
    //�t���O�𗧂Ă邱�ƂŔ񓯊����[�h���\�ɂȂ�
    SetUseASyncLoadFlag(TRUE);
    //ScreenFlip�����s���Ă����������M����҂��Ȃ�
    SetWaitVSyncFlag(FALSE);
    //�`���𗠉�ʂɂ���
    SetDrawScreen(DX_SCREEN_BACK);
    //��ʃ��[�h���E�B���h�E���[�h�ŕ`�悷�邩
#if _DEBUG
    ChangeWindowMode(TRUE);
#else
    ChangeWindowMode(FALSE);
#endif// _DEBUG
}