//===================================
// @brief �T�E���h�N���X
//===================================
#pragma once
#include <cassert>

class Sound
{
public:
	virtual ~Sound();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new Sound();
	}

	/*�C���X�^���X�̎擾*/
	static Sound& GetInstance()
	{
		//�C���X�^���X��null���������O�𔭐�������
		assert(instance != nullptr);
		return *instance;
	}

	/*�C���X�^���X�̍폜*/
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
	/*���������֐�*/
	Sound();
	/*�����o�ϐ�*/
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

