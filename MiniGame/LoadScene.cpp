#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
LoadScene::LoadScene()
	: alpha(0)
	, isIncTheValue(false)
	, isIncWaitFrameCount(0)
	, updateWaitFrameCount(0)
{
	Init();
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
LoadScene::~LoadScene()
{
	Final();
}
/// <summary>
/// ������
/// </summary>
void LoadScene::Init()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::LOAD_SCENE);

	SetFontSize(json.GetJson(jsonIndex)["FONT_SIZE"]);
}
/// <summary>
/// �㏈��
/// </summary>
void LoadScene::Final()
{
}
/// <summary>
/// �X�V
/// </summary>
void LoadScene::Update()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::LOAD_SCENE);

	this->updateWaitFrameCount++;
	if (this->updateWaitFrameCount >= json.GetJson(jsonIndex)["MAX_UPDATE_WAIT_FRAME_COUNT"])
	{
		//�����̕ύX
		if (this->isIncTheValue)
		{
			this->alpha += json.GetJson(jsonIndex)["ADD_ALPHA"];
			if (this->alpha >= json.GetJson(jsonIndex)["FONT_SIZE"])
			{
				this->isIncWaitFrameCount++;
				if (this->isIncWaitFrameCount >= json.GetJson(jsonIndex)["MAX_IS_INC_WAIT_FRAME_COUNT"])
				{
					this->isIncWaitFrameCount = 0;
					this->isIncTheValue = false;
				}
				this->alpha = json.GetJson(jsonIndex)["MAX_ALPHA"];
			}
		}
		else
		{
			this->alpha -= json.GetJson(jsonIndex)["ADD_ALPHA"];
			if (this->alpha <= json.GetJson(jsonIndex)["MIN_ALPHA"])
			{
				this->isIncWaitFrameCount++;
				if (this->isIncWaitFrameCount >= json.GetJson(jsonIndex)["MAX_IS_INC_WAIT_FRAME_COUNT"])
				{
					this->isIncWaitFrameCount = 0;
					this->isIncTheValue = true;
				}
				this->alpha = json.GetJson(jsonIndex)["MIN_ALPHA"];
			}
		}
		this->updateWaitFrameCount = 0;
	}
}
/// <summary>
/// �`��
/// </summary>
void LoadScene::Draw()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::LOAD_SCENE);

	int r = json.GetJson(jsonIndex)["FONT_COLOR"];
	int g, b;
	g = b = r;
	int fontColor = GetColor(r, g, b);
	ClearDrawScreen();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, this->alpha);
	DrawString(json.GetJson(jsonIndex)["X"], json.GetJson(jsonIndex)["Y"], "Now Loading", fontColor);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, this->alpha);
}