#include "Common.h"

SceneChanger* SceneChanger::instance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
SceneChanger::SceneChanger()
	:nowScene(SceneType::TITLE)
	, nextSceneType(nowScene)
{

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
SceneChanger::~SceneChanger()
{

}

/// <summary>
/// �V�[���̓���
/// </summary>
const void SceneChanger::SynchroScene()
{
	this->nowScene = this->nextSceneType;
}

/// <summary>
/// �V�[���̕ύX
/// </summary>
const void SceneChanger::ChangeScene(const SceneType _nextScene)
{
	this->nextSceneType = _nextScene;
}
