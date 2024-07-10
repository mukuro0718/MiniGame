#include "Common.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
TitleCamera::TitleCamera()
	: Object()
	, pos(0.0f)
	, targetPos(0.0f)
{
	/*������*/
	Init();
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
TitleCamera::~TitleCamera()
{
	//�����Ȃ�
}
/// <summary>
/// ������
/// </summary>
void TitleCamera::Init()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::CAMERA);

	SetCameraNearFar(json.GetJson(jsonIndex)["CAMERA_NEAR"], json.GetJson(jsonIndex)["CAMERA_FAR"]);
}
/// <summary>
/// �X�V
/// </summary>
void TitleCamera::Update()
{
	/*�V���O���g���N���X�̃C���X�^���X�̎擾*/
	auto& json = JsonManager::GetInstance();
	auto& chara = CharacterManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::CAMERA);
	WrapVECTOR origin = 0;
	origin.Convert(json.GetJson(jsonIndex)["TITLE_CAMERA_TARGET"]);
	/*���W�̍X�V*/
	this->targetPos = origin;

	this->transform.pos = origin.Add(json.GetJson(jsonIndex)["TITLE_CAMERA_OFF_SET"]);

	/*�J�����̐ݒ�*/
	SetCameraPositionAndTargetAndUpVec(this->transform.pos.value, this->targetPos.value, VGet(0.0f, 1.0f, 0.0f));
}