#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Tutorial::Tutorial()
{

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
	clsDx();
	printfDx("Tutorial");

	/*�I������*/
	EndProcess();
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
