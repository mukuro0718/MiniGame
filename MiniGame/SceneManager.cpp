#include "Common.h"

SceneManager* SceneManager::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
SceneManager::SceneManager()
	:scene(nullptr)
{
	this->scene		= new Title();
	this->fps		= new FPSController();
	this->load		= new LoadScene();
}
/// <summary>
/// デストラクタ
/// </summary>
SceneManager::~SceneManager()
{

}
/// <summary>
/// 更新
/// </summary>
void SceneManager::Update()
{
	if (GetASyncLoadNum() == 0)
	{
		/*インプットマネージャーのインスタンスを取得*/
		auto& input = InputManager::GetInstance();

		/*インプットマネージャーの更新*/
		input.Update();

		/*シーンの更新*/
		this->scene->Update();

		/*シーンの描画*/
		ClearDrawScreen();
		this->scene->Draw();

		/*シーンの終了処理*/
		this->scene->EndProcess();

		/*シーンの変更*/
		SceneChange();

		/*ＦＰＳの平均を算出*/
		this->fps->Ave();

		/*fpsの描画*/
		this->fps->Draw();

		/*ＦＰＳの処理*/
		this->fps->Wait();

		/*裏画面の内容を表に反映させる*/
		ScreenFlip();
	}
	else
	{
		this->load->Update();
		this->load->Draw();
	}
}
/// <summary>
/// シーンの変更
/// </summary>
void SceneManager::SceneChange()
{
	/*シーンチェンジャークラスのインスタンスを取得*/
	auto& changer = SceneChanger::GetInstance();

	/*もし現在のシーンタイプと前のシーンタイプが異なっていたら処理を行う*/
	if (changer.GetNowSceneType() != changer.GetNextSceneType())
	{
		//シーンタイプによって作成するインスタンスを変える
		switch (changer.GetNextSceneType())
		{
		case SceneChanger::SceneType::TITLE:
			delete(this->scene);
			this->scene = new Title();
			break;
		case SceneChanger::SceneType::GAME:
			delete(this->scene);
			this->scene = new Game();
			break;
		case SceneChanger::SceneType::RESULT:
			delete(this->scene);
			this->scene = new Result();
			break;
		}
		//シーンを同期させる
		changer.SynchroScene();
	}
}
