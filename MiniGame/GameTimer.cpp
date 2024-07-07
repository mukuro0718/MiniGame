#include "Common.h"

GameTimer* GameTimer::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
GameTimer::GameTimer()
	: elapsetTime(0)
	, elapsetFrame(0)
{
	/*������*/
	Init();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
GameTimer::~GameTimer()
{

}

/// <summary>
/// ������
/// </summary>
void GameTimer::Init()
{
	this->elapsetTime = 0;
	this->elapsetFrame = 0;
}

/// <summary>
/// �X�V
/// </summary>
void GameTimer::Update()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::TIMER);

	/*�t���[�����̑���*/
	this->elapsetFrame++;

	/*�����t���[�������ő�t���[�����𒴂��Ă�����*/
	if (this->elapsetFrame >= json.GetJson(jsonIndex)["MAX_FRAME"])
	{
		//�o�ߎ��Ԃ𑝂₷
		this->elapsetTime++;
		//�t���[����������������
		this->elapsetFrame = 0;
	}
}

/// <summary>
/// �`��
/// </summary>
const void GameTimer::Draw()const
{
#ifdef _DEBUG
	printfDx("TIME:%d", this->elapsetTime);
#endif // _DEBUG

}

