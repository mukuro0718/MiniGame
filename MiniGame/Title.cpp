#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Title::Title()
{

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Title::~Title()
{

}

/// <summary>
/// �X�V
/// </summary>
void Title::Update()
{
}

/// <summary>
/// �`��
/// </summary>
void Title::Draw()
{
	ClearDrawScreen();
	clsDx();
	printfDx("TITLE");
}

/// <summary>
/// �I������
/// </summary>
void Title::EndProcess()
{
	/*�C���v�b�g�}�l�[�W���[�̃C���X�^���X���擾*/
	auto& input = InputManager::GetInstance();

	/*�G���^�[�L�[�i���PAD�Ή�������j�������ꂽ��V�[����؂�ւ���*/
	if (input.GetReturnKeyState())
	{
		auto& changer = SceneChanger::GetInstance();
		changer.ChangeScene(SceneChanger::SceneType::TUTORIAL);
	}
}
