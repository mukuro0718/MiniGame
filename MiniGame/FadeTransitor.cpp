#include "Common.h"

void FadeTransitor::Update()
{
	if (frame_ < interval_) {
		++frame_;
		SetDrawScreen(newRT_);
	}
	else if (frame_ == interval_) {
		SetDrawScreen(DX_SCREEN_BACK);
	}
}

void FadeTransitor::Draw()
{
	if (IsEnd()) {
		return;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	auto rate = (float)frame_ / (float)interval_;//���������߂�
	DrawGraph(0, 0, oldRT_, true);
	//�؂�ւ����ʂ��A���t�@�u�����f�B���O
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, rate * 255);
	DrawGraph(0, 0, newRT_, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
