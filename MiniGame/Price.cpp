#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Price::Price(const int _fontHandle)
	: fontHandle(0)
{
	this->fontHandle = _fontHandle;
	Init();
}

/// <summary>
/// デストラクタ
/// </summary>
Price::~Price()
{

}

/// <summary>
/// 初期化
/// </summary>
void Price::Init()
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::UI);

	vector<int> color = json.GetJson(jsonIndex)["PRICE_COLOR"];
	vector<int> pos = json.GetJson(jsonIndex)["PRICE_MAIN_POS"];
	this->pos = pos;
	this->color = GetColor(color[0], color[1], color[2]);
}

/// <summary>
/// 更新
/// </summary>
void Price::Update()
{
	Draw();
}

/// <summary>
/// 描画
/// </summary>
const void Price::Draw()const
{
	DrawFormatStringToHandle(this->pos[0], this->pos[1], this->color, this->fontHandle, "しょじきん ￥%d円", 10000);
}