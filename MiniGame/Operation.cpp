#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Operation::Operation(const int _fontHandle)
	: fontHandle(0)
	, color(0)
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
	vector<int> pos = json.GetJson(jsonIndex)["OPERATION_POS"];
	this->pos = pos;
	this->color = GetColor(color[0], color[1], color[2]);
}

/// <summary>
/// �X�V
/// </summary>
void Operation::Update()
{
	Draw();
}

/// <summary>
/// �`��
/// </summary>
const void Operation::Draw()const
{
	DrawStringToHandle(this->pos[0], this->pos[1], "A�{�^����\n��ɂ�����", this->color, this->fontHandle);
}