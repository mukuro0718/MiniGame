#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Result::Result()
{

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Result::~Result()
{

}

/// <summary>
/// �X�V
/// </summary>
void Result::Update()
{
	
}
/// <summary>
/// �`��
/// </summary>
void Result::Draw()
{
	ClearDrawScreen();
	clsDx();
	printfDx("Result");
}
/// <summary>
/// �I������
/// </summary>
void Result::EndProcess()
{
	/*�C���v�b�g�}�l�[�W���[�̃C���X�^���X���擾*/
	auto& input = InputManager::GetInstance();

	/*�G���^�[�L�[�i���PAD�Ή�������j�������ꂽ��V�[����؂�ւ���*/
	if (input.GetReturnKeyState())
	{
		auto& changer = SceneChanger::GetInstance();
		changer.ChangeScene(SceneChanger::SceneType::TITLE);
	}
}
