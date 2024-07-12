#include "Common.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
ResultCamera::ResultCamera()
	: pos(0.0f)
	, targetPos(0.0f)
{
	/*������*/
	Init();
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
ResultCamera::~ResultCamera()
{
	//�����Ȃ�
}
/// <summary>
/// ������
/// </summary>
void ResultCamera::Init()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::CAMERA);

	SetCameraNearFar(json.GetJson(jsonIndex)["CAMERA_NEAR"], json.GetJson(jsonIndex)["CAMERA_FAR"]);
}
/// <summary>
/// �Q�[���N���A���X�V
/// </summary>
void ResultCamera::ClearUpdate()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	auto& chara = CharacterManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::CAMERA);
	WrapVECTOR target = 0;
	target.Convert(json.GetJson(jsonIndex)["ORIGIN"]);
	/*���W�̍X�V*/
	this->targetPos = target;

	this->pos = target.Add(json.GetJson(jsonIndex)["CLEAR_CAMERA_OFFSET"]);

	/*�J�����̐ݒ�*/
	SetCameraPositionAndTargetAndUpVec(this->pos.value, this->targetPos.value, VGet(0.0f, 1.0f, 0.0f));
}
/// <summary>
/// �Q�[���I�[�o�[���X�V
/// </summary>
void ResultCamera::OverUpdate()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	auto& chara = CharacterManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::CAMERA);
	WrapVECTOR target = 0;
	target = chara.GetPlayerPos();
	/*���W�̍X�V*/
	this->targetPos = target.Add(json.GetJson(jsonIndex)["OVER_TARGET_OFFSET"]);

	this->pos = target.Add(json.GetJson(jsonIndex)["OVER_CAMERA_OFFSET"]);

	/*�J�����̐ݒ�*/
	SetCameraPositionAndTargetAndUpVec(this->pos.value, this->targetPos.value, VGet(0.0f, 1.0f, 0.0f));
}