#include "Common.h"

const int Score::TEXT_COLOR_WHITE = GetColor(255, 255, 255);

/// <summary>
/// コンストラクタ
/// </summary>
Score::Score(const int _forPrice,const int _forSpecialPrice,const int _moneyBag)
	:imageHandle(0)
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::UI);

	this->fontHandle.emplace_back(_forPrice);
	this->fontHandle.emplace_back(_forSpecialPrice);
	this->pos.emplace_back(Convert(json.GetJson(jsonIndex)["PRICE_POS"]));
	this->pos.emplace_back(Convert(json.GetJson(jsonIndex)["SPECIAL_SCORE_POS"]));
	this->pos.emplace_back(Convert(json.GetJson(jsonIndex)["MONEY_BAG_POS"]));
	this->imageHandle = _moneyBag;
}

/// <summary>
/// デストラクタ
/// </summary>
Score::~Score()
{

}

/// <summary>
/// 描画
/// </summary>
const void Score::Draw()const
{
	auto& character = CharacterManager::GetInstance();
	
	DrawPrice(character.GetPlayerInstance().GetPrice());
}

/// <summary>
/// 価格の描画
/// </summary>
const void Score::DrawPrice(const int _price)const
{
	/*シングルトンクラスのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	int jsonIndex = json.GetFileNameType(JsonManager::FileNameType::UI);

	int type = static_cast<int>(PosType::IMAGE);
	int size = json.GetJson(jsonIndex)["MONEY_BAG_SIZE"];
	DrawExtendGraph(this->pos[type].x, this->pos[type].y, this->pos[type].x + size, this->pos[type].y + size, this->imageHandle, TRUE);
	type = static_cast<int>(PosType::PRICE);
	DrawFormatStringToHandle(this->pos[type].x, this->pos[type].y, this->TEXT_COLOR_WHITE, this->fontHandle[type], ":%d", _price);
}

Score::Vec2d Score::Convert(const vector<int> _in)
{
	Vec2d out;
	out.x = _in[0];
	out.y = _in[1];
	return out;
}