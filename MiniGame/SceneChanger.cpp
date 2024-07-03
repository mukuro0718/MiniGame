#include "Common.h"

SceneChanger* SceneChanger::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
SceneChanger::SceneChanger()
	:nowScene(SceneType::TITLE)
	, nextSceneType(nowScene)
{

}

/// <summary>
/// デストラクタ
/// </summary>
SceneChanger::~SceneChanger()
{

}

/// <summary>
/// シーンの同期
/// </summary>
const void SceneChanger::SynchroScene()
{
	this->nowScene = this->nextSceneType;
}

/// <summary>
/// シーンの変更
/// </summary>
const void SceneChanger::ChangeScene(const SceneType _nextScene)
{
	this->nextSceneType = _nextScene;
}
