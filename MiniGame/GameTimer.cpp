#include "Common.h"

GameTimer* GameTimer::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
GameTimer::GameTimer()
	: elapsetTime(1)
	, elapsetFrame(1)
{
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
	this->elapsetTime = 1;
	this->elapsetFrame = 1;
}

/// <summary>
/// �X�V
/// </summary>
void GameTimer::Update()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	auto& character = CharacterManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::TIMER);

	if (!character.GetPlayerInstance().GetIsStop())
	{
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
}

/// <summary>
/// �`��
/// </summary>
const void GameTimer::Draw()const
{
//#ifdef _DEBUG
//	clsDx();
//	printfDx("TIME:%d", this->elapsetTime);
//#endif // _DEBUG

}

