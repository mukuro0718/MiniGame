#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Operation::Operation(const int _fontHandle)
	: fontHandle(0)
	, color(0)
{
	this->fontHandle = _fontHandle;
	Init();
}

/// <summary>
/// デストラクタ
/// </summary>
Operation::~Operation()
{

}

/// <summary>
/// 初期化
/// </summary>
void Operation::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::UI);

	vector<int> color = json.GetJson(jsonIndex)["OPERATION_COLOR"];
	vector<int> pos = json.GetJson(jsonIndex)["OPERATION_POS"];
	this->pos = pos;
	this->color = GetColor(color[0], color[1], color[2]);
}

/// <summary>
/// 更新
/// </summary>
void Operation::Update()
{
	Draw();
}

/// <summary>
/// 描画
/// </summary>
const void Operation::Draw()const
{
	DrawStringToHandle(this->pos[0], this->pos[1], "Aボタンで\n上にあがる", this->color, this->fontHandle);
}