#include "Common.h"


IrisTransitor::IrisTransitor(bool irisOut, int interval, bool isTiled, int gHandle) 
	:Transitor(interval)
	,irisOut_(irisOut)
{
	/*Jsonマネージャーのインスタンスの取得*/
	auto& json = JsonManager::GetInstance();
	const int jsonFileNum = static_cast<int>(JsonManager::FileNameType::SET_UP_SCREEN);

	const int windowHeight = json.GetJson(jsonFileNum)["WINDOW_HEIGHT"];
	const int windowWidth = json.GetJson(jsonFileNum)["WINDOW_WIDTH"];

	handleForMaskScreen_ = MakeScreen(windowWidth, windowHeight);
	maskH_ = CreateMaskScreen();
	diagonalLength_ = std::hypotf(windowWidth, windowHeight) / 2.0f;
}

IrisTransitor::~IrisTransitor()
{
	DeleteMaskScreen();
}

void IrisTransitor::Update()
{
	if (frame_ < interval_) {
		++frame_;
		SetDrawScreen(newRT_);
	}
	else if (frame_ == interval_) {
		SetDrawScreen(DX_SCREEN_BACK);
	}
}

void IrisTransitor::Draw()
{
	if (IsEnd()) {
		return;
	}

	auto rate = (float)frame_ / (float)interval_;
	int backRT = oldRT_;
	int maskedRT = newRT_;
	if (irisOut_) {
		backRT = newRT_;
		maskedRT = oldRT_;
		rate = 1.0f - rate;
	}
	//
	float radius = (diagonalLength_)*rate;
	SetDrawScreen(handleForMaskScreen_);
	ClearDrawScreen();

	DrawCircleAA(320, 240, radius, 32, 0xffffff, true);

	//隠し関数(現在のグラフィックハンドルをマスクスクリーンに転送)
	SetMaskScreenGraph(handleForMaskScreen_);
	//描画領域を反転する
	SetMaskReverseEffectFlag(true);

	SetDrawScreen(DX_SCREEN_BACK);
	SetUseMaskScreenFlag(false);
	DrawGraph(0, 0, backRT, true);
	SetUseMaskScreenFlag(true);
	DrawGraph(0, 0, maskedRT, true);
	SetUseMaskScreenFlag(false);
}
