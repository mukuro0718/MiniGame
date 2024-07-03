//=====================================================
// @brief シーンベースクラス
// 各シーンで必ず実装したい関数を純粋仮想関数で実装
//=====================================================
#pragma once

class SceneBase abstract
{
public:
	SceneBase();	//コンストラクタ
	virtual ~SceneBase();	//デストラクタ

	/*純粋仮想関数（継承先で実装）*/
	virtual void Update()		abstract;	//更新
	virtual void EndProcess()	abstract;	//シーンの終了処理
};

