//================================================================
// @brief 宝石管理クラス
//================================================================
#pragma once
#include <cassert>

class Gem;
class GemManager
{
public:
	virtual ~GemManager();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new GemManager();
	}

	/*インスタンスの取得*/
	static GemManager& GetInstance()
	{
		//インスタンスがnullだったら例外を発生させる
		assert(instance != nullptr);
		return *instance;
	}

	/*インスタンスの削除*/
	static void DeleteInstance()
	{
		if (instance != nullptr)
		{
			delete(instance);
			instance = nullptr;
		}
	}

	void		Update			();											//更新
	const void	Draw			()const;									//描画
	const int	GetUseNum		()const { return this->useCurrentlyNum; }	//使用している数のgetter
	const Gem&	GetGemInstance	(const int _index)const;					//ジェムのインスタンスのgetter

	void InitUseGem();	//使用しているジェムの初期化
	const bool GetGemIsHit(const int _index)const;
	const bool GetGemIsSet(const int _index)const;
private:
	/*列挙体*/
	enum class PatternType
	{
		CENTER	= 0,
		BOTTOM	= 1,
		TOP		= 2,
		UP		= 3,
		DOWN	= 4,
	};

	/*内部処理関数*/
	GemManager();		//コンストラクタ
	void SetUseGem();	//使用するジェムのセット

	/*メンバ変数*/
	static GemManager*	instance;	//唯一のインスタンス
	vector<Gem*>		gem;		//宝石
	Gem*				specialGem;
	int					useCurrentlyNum;
};


