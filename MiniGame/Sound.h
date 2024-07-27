//===================================
// @brief サウンドクラス
//===================================
#pragma once
#include <cassert>

class Sound
{
public:
	virtual ~Sound();//デストラクタ

	/*インスタンスの作成*/
	static void CreateInstance()
	{
		instance = new Sound();
	}

	/*インスタンスの取得*/
	static Sound& GetInstance()
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

	void Init();

	const void OnIsPlayButtonSound();
	const void OnIsPlayBGM();
	const void OnIsPlayTitleBGM();
	const void OnIsPlayGameOverBGM();
	const void OnIsPlayGameClearBGM();
	const void OnIsPlayHouseExplosionSound();
	const void OnIsPlayPlayerExplosionSound();
	const void OnIsPlayMoneySound();

	void PlayButtonSound();
	void PlayBGM();
	void PlayTitleBGM();
	void PlayGameOverBGM();
	void PlayGameClearBGM();
	void PlayHouseExplosionSound();
	void PlayPlayerExplosionSound();
	void PlayMoneySound();

	void PlayNormalShotSound();
	void PlayBossShotSound();
	void PlayEnemyStartMoveSound();
	void PlayJetSound();

	const void OnIsNormalShot();
	const void OnIsBossShot();
	const void OnIsEnemyStartMove();
	const void OnIsJetSound();
private:
	/*内部処理関数*/
	Sound();
	/*メンバ変数*/
	static Sound* instance;

	bool isPlayButtonSound;

	bool isPlayBGM;
	bool isPlayTitleBGM;
	bool isPlayGameOverBGM;
	bool isPlayGameClearBGM;

	bool isPlayHouseExplosionSound;
	bool isPlayPlayerExplosionSound;
	bool isPlayMoneySound;

	int buttonSound;
	int bgm;
	int bgm2;
	int gameoverBGM;
	int gameclearBGM;
	int houseExplosionSound;
	int playerExplosionSound;
	int moneySound;

	bool isPlayNormalShotSound;
	bool isPlayBossShotSound;
	bool isPlayEnemyStartMoveSound;
	bool isPlayPlayerJetSound;
	int normalEnemyShotSound;
	int bossShotSound;
	int enemyStartMoveSound;
	int playerJetSound;
	int jetSoundVolume;
};

