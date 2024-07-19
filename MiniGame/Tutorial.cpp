#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Tutorial::Tutorial()
	: fontHandle(-1)
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& asset = LoadingAsset::GetInstance();
	this->fontHandle = asset.GetFont(asset.GetFontType(LoadingAsset::FontType::MUKASI_3));
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Tutorial::~Tutorial()
{

}

/// <summary>
/// �X�V
/// </summary>
void Tutorial::Update()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& backGround = BackGround::GetInstance();

	/*�X�V*/
	backGround.Update();

}

/// <summary>
/// �`��
/// </summary>
void Tutorial::Draw()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& backGround = BackGround::GetInstance();

	/*�`��*/
	backGround.Draw();
	DrawStringToHandle(0, 0, "���Ȃ��͉ƂɋA��r���ł��I\n�����ɉƂɋA���Ă��������I\n", GetColor(255, 255, 255), this->fontHandle);
}

/// <summary>
/// �I������
/// </summary>
void Tutorial::EndProcess()
{
	/*�C���v�b�g�}�l�[�W���[�̃C���X�^���X���擾*/
	auto& input = InputManager::GetInstance();

	/*�G���^�[�L�[�i���PAD�Ή�������j�������ꂽ��V�[����؂�ւ���*/
	if (input.GetReturnKeyState())
	{
		auto& changer = SceneChanger::GetInstance();
		changer.ChangeScene(SceneChanger::SceneType::GAME);
	}
}
