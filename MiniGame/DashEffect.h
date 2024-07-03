//====================================
// @brief ダッシュエフェクトクラス
// 定数分だけベースクラスを作成する
//====================================
#pragma once
#include<DxLib.h>
#include<vector>
using namespace std;

class DashEffectConst;
class DashEffectBase;
class DashEffect
{
public:
	DashEffect();
	~DashEffect();

	const void Update(const bool _isRun, const VECTOR _targetPos);//更新
	const void Draw();	//描画

private:
	/*メンバ変数*/
	DashEffectConst* m_const;
	vector<DashEffectBase*> m_base;
	int m_nowEffectNum;
	int m_waitInitNum;
};

