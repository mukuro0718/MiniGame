#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
House::House(const int _modelHandle)
{

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
House::~House()
{

}

/// <summary>
/// ������
/// </summary>
void House::Init()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::STAGE);

	this->transform.pos.Convert(json.GetJson(jsonIndex)["HOUSE_POS"]);
	this->transform.rotate.Convert(json.GetJson(jsonIndex)["HOUSE_ROTATE"]);
	this->transform.scale.Convert(json.GetJson(jsonIndex)["HOUSE_SCALE"]);

}

/// <summary>
/// �X�V
/// </summary>
void House::Update()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& timer = GameTimer::GetInstance();
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::STAGE);

	if (timer.GetElapsetTime() >= json.GetJson(jsonIndex)["TARGET_TIME"])
	{
		this->transform.pos.value.x--;
		if (this->transform.pos.value.x <= json.GetJson(jsonIndex)["TARGET_TIME"])
		{
			this->transform.pos.value.x = json.GetJson(jsonIndex)["TARGET_TIME"];
		}
	}


	/*���f���̐ݒ�*/
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// �`��
/// </summary>
const void House::Draw()const
{
	MV1DrawModel(this->modelHandle);
}