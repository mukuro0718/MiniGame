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
	this->imageHandle = asset.GetImage(asset.GetImageType(LoadingAsset::ImageType::TUTORIAL));
	this->movieHandle = LoadGraph("Data/Movie/TutorialMovie.mp4");
	PlayMovieToGraph(movieHandle);
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
	if (GetMovieStateToGraph(this->movieHandle) == 0)
	{
		//���[�r�[�̍Đ��ʒu��0�b�ڂɕύX���܂�
		SeekMovieToGraph(this->movieHandle, 0);
		//���[�r�[���Đ���Ԃɂ��܂�
		PlayMovieToGraph(this->movieHandle);
	}
}

/// <summary>
/// �`��
/// </summary>
void Tutorial::Draw()
{
	DrawExtendGraph(0, 0, 1920, 1080, this->imageHandle, TRUE);
	DrawExtendGraph(100, 50, 1240, 680, this->movieHandle, FALSE);
}

/// <summary>
/// �I������
/// </summary>
void Tutorial::EndProcess()
{
	/*�C���v�b�g�}�l�[�W���[�̃C���X�^���X���擾*/
	auto& input = InputManager::GetInstance();
	auto& sound = Sound::GetInstance();

	/*�G���^�[�L�[�i���PAD�Ή�������j�������ꂽ��V�[����؂�ւ���*/
	if (input.GetReturnKeyState() || input.GetPadState() & PAD_INPUT_3)
	{
		auto& changer = SceneChanger::GetInstance();
		changer.ChangeScene(SceneChanger::SceneType::GAME);
	}
}
