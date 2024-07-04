#include"Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
FPSController::FPSController()
	: fps(0.0f)
	, startTime(0)
	, count(0)
{
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
FPSController::~FPSController()
{

}
/// <summary>
/// ������
/// </summary>
const void FPSController::Init()
{
	this->fps = 0.0f;
	this->startTime = 0;
	this->count = 0;
}
/// <summary>
/// FPS�̕���
/// </summary>
const void FPSController::Ave()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::FPS_CONTROLLER);

	//�J�E���g���O��������X�^�[�g�^�C����������
	if (this->count == 0)
	{
		this->startTime = GetNowCount();
	}
	//�J�E���g���ڕWFPS�ɂȂ�����
	if (this->count == json.GetJson(jsonIndex)["TARGET_FPS"])
	{
		//���݂̎������擾
		int nowTime = GetNowCount();
		//FPS�v�Z
		this->fps = 1000.0 / (static_cast<double>((nowTime - this->startTime)) / json.GetJson(jsonIndex)["TARGET_FPS"]);
		//������
		this->startTime = 0;
		this->count = 0;
	}
	else
	{
		this->count++;
	}
}
/// <summary>
/// FPS�̕`��
/// </summary>
const void FPSController::Draw()
{
#if _DEBUG
	//FPS�̕`��
	DrawFormatString(1650, 0, GetColor(255,255,255), "FPS:%lg", fps);
#endif // _DEBUG
}
/// <summary>
/// �ڕWFPS�ɂȂ�悤�ҋ@
/// </summary>
const void FPSController::Wait()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::FPS_CONTROLLER);

	//���݂̌o�ߎ���
	int elapsedTime = GetNowCount() - this->startTime;
	//�ҋ@����
	int waitTime = this->count * 1000 / json.GetJson(jsonIndex)["TARGET_FPS"] - elapsedTime;
	if (waitTime > 0)
	{
		Sleep(waitTime);
	}
}
