#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Price::Price(const int _fontHandle)
	: fontHandle(0)
{
	this->fontHandle = _fontHandle;
	Init();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Price::~Price()
{

}

/// <summary>
/// ������
/// </summary>
void Price::Init()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::UI);

	vector<int> color = json.GetJson(jsonIndex)["PRICE_COLOR"];
	vector<int> pos = json.GetJson(jsonIndex)["PRICE_MAIN_POS"];
	this->pos = pos;
	this->color = GetColor(color[0], color[1], color[2]);
}

/// <summary>
/// �X�V
/// </summary>
void Price::Update()
{
	Draw();
}

/// <summary>
/// �`��
/// </summary>
const void Price::Draw()const
{
	DrawFormatStringToHandle(this->pos[0], this->pos[1], this->color, this->fontHandle, "���傶���� ��%d�~", 10000);
}