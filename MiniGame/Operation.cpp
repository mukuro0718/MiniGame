#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Operation::Operation(const int _fontHandle)
	: fontHandle(0)
	, color(0)
	, moveX(0)
	, isStop(false)
	, stopFrameCount(0)
{
	this->fontHandle = _fontHandle;
	Init();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Operation::~Operation()
{

}

/// <summary>
/// ������
/// </summary>
void Operation::Init()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::UI);
	vector<int> color = json.GetJson(jsonIndex)["OPERATION_COLOR"];
	vector<int> pos = json.GetJson(jsonIndex)["OPERATION_START_POS"];
	vector<int> endPos = json.GetJson(jsonIndex)["OPERATION_END_POS"];
	this->endPosX = endPos;
	this->text.clear();
	this->text.emplace_back("A�{�^���ŏ㏸");
	this->text.emplace_back("�G�̍U���⓹�H�A�ԂȂǂɓ�����ƃQ�[���I�[�o�[�ł�");
	this->text.emplace_back("���̃o�[�̎Ԃ��A�Ƃ̃}�[�N�܂ł��ǂ蒅���ƃQ�[���N���A�ł�");
	this->moveX = 0;
	this->isStart = true;
	this->isStop = false;
	this->isEnd = false;
	this->isFinish = false;
	this->textIndex = 0;
	this->pos = pos;
	this->color = GetColor(color[0], color[1], color[2]);
}

/// <summary>
/// �X�V
/// </summary>
void Operation::Update()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	auto& timer = GameTimer::GetInstance();
	auto& character = CharacterManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::UI);
	int time = timer.GetElapsetTime();
	int frame = timer.GetElapsetFrame();

	if (!this->isFinish)
	{
		if (character.GetPlayerInstance().GetIsStop())
		{
			//X���W����~�ʒu�ɍs�������~����
			if (this->moveX >= json.GetJson(jsonIndex)["OPERATION_STOP_POS"])
			{
				this->moveX -= json.GetJson(jsonIndex)["OPERATION_MOVE_VELOCITY"];
			}
		}
		else
		{
			//X���W����~�ʒu�ɍs�������~����
			if (this->moveX <= this->endPosX[this->textIndex])
			{
				isFinish = true;
			}
			this->moveX -= json.GetJson(jsonIndex)["OPERATION_MOVE_VELOCITY"];
		}
	}
}

/// <summary>
/// �`��
/// </summary>
const void Operation::Draw()const
{
	if (!this->isFinish)
	{
		for (int i = 0; i < this->text.size(); i++)
		{
			DrawStringToHandle(this->pos[0] + this->moveX, this->pos[1] + POS_Y_OFFSET * i, this->text[i].c_str(), this->color, this->fontHandle);
		}
	}
}