#include "Common.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Building::Building(const int _modelHandle)
	: modelHandle(0)
	, isMove(false)
{
	this->modelHandle = MV1DuplicateModel(_modelHandle);
	Init();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Building::~Building()
{

}

/// <summary>
/// ������
/// </summary>
void Building::Init()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::STAGE);
	this->transform.pos.Convert(json.GetJson(jsonIndex)["BUILDING_POS"]);
	this->transform.rotate.Convert(json.GetJson(jsonIndex)["BUILDING_ROTATE"]);
	this->transform.scale.Convert(json.GetJson(jsonIndex)["BUILDING_SCALE"]);

	this->isMove = false;
	MV1SetScale(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition(this->modelHandle, this->transform.pos.value);

}

/// <summary>
/// �X�V
/// </summary>
void Building::Update()
{
	if (this->isMove)
	{
 		this->transform.pos.value.x -= 2.0f;
		if (this->transform.pos.value.x <= -240.0f)
		{
			Init();
		}
	}
	MV1SetScale			(this->modelHandle, this->transform.scale.value);
	MV1SetRotationXYZ	(this->modelHandle, this->transform.rotate.value);
	MV1SetPosition		(this->modelHandle, this->transform.pos.value);
}

/// <summary>
/// �`��
/// </summary>
const void Building::Draw()const
{
	MV1DrawModel(this->modelHandle);
}