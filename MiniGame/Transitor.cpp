#include "Common.h"

void Transitor::Start()
{
	/*Jsonマネージャーのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	const int jsonFileNum = static_cast<int>(JsonManager::FileNameType::SET_UP_SCREEN);

	const int windowHeight = json.GetJson(jsonFileNum)["WINDOW_HEIGHT"];
	const int windowWidth = json.GetJson(jsonFileNum)["WINDOW_WIDTH"];

	this->oldRT_ = MakeScreen(windowWidth, windowHeight);
	this->newRT_ = MakeScreen(windowWidth, windowHeight);

	int result = GetDrawScreenGraph(0, 0, windowWidth, windowHeight, oldRT_);
	frame_ = 0;
}

Transitor::~Transitor()
{
	DeleteGraph(oldRT_);
	DeleteGraph(newRT_);
}

bool
Transitor::IsEnd() const
{
	return frame_ >= interval_;
}
