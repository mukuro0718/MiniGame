//=========================================
// @brief シーン遷移時演出クラス
// 参考：https://qiita.com/tsuchinokoman/items/b6d7f500ab0d05478a2c#transitor%E5%9F%BA%E5%BA%95%E3%82%AF%E3%83%A9%E3%82%B9
//=========================================
#pragma once
/// <summary>
/// シーン遷移時演出基底クラス
/// </summary>
class Transitor
{
protected:
	const int interval_;//切り替えにかかる時間
	int frame_ = 0;//開始から現在までのフレーム数
	int oldRT_ = 0;//切り替え前の画面
	int newRT_ = 0;//切り替え後の画面
public:
	Transitor(int interval = 60) : interval_(interval) {}
	virtual ~Transitor();
	void Start();//演出開始
	virtual void Update() = 0;//Scene::Updateの最後に呼んでね
	virtual void Draw() = 0;//Scene::Drawの最後に呼んでね
	virtual bool IsEnd()const;//演出が終了した
};

