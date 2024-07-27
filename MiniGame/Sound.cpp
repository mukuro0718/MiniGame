#include "Common.h"

Sound* Sound::instance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
Sound::Sound()
	: isPlayButtonSound(false)
	, isPlayBGM(false)
	, isPlayGameOverBGM(false)
	, isPlayGameClearBGM(false)
	, isPlayHouseExplosionSound(false)
	, isPlayPlayerExplosionSound(false)
	, isPlayMoneySound(false)
	, buttonSound(-1)
	, bgm(-1)
	, bgm2(-1)
	, gameoverBGM(-1)
	, gameclearBGM(-1)
	, houseExplosionSound(-1)
	, playerExplosionSound(-1)
	, moneySound(-1)
	, jetSoundVolume(0)
{
	SetCreateSoundDataType(DX_SOUNDDATATYPE_FILE);
	//サウンドハンドルの
	this->buttonSound			= LoadSoundMem("Data/Sound/ButtonPressSound.mp3");
	this->bgm					= LoadSoundMem("Data/Sound/gameBGM.mp3");
	this->bgm2= LoadSoundMem("Data/Sound/A.mp3");
	this->gameoverBGM			= LoadSoundMem("Data/Sound/gameoverBGM.mp3");
	this->gameclearBGM			= LoadSoundMem("Data/Sound/gameclearBGM.mp3");
	this->houseExplosionSound	= LoadSoundMem("Data/Sound/HouseExplosionSound.mp3");
	this->playerExplosionSound	= LoadSoundMem("Data/Sound/PlayerExplosionSound.mp3");
	this->moneySound			= LoadSoundMem("Data/Sound/money.mp3");
	this->normalEnemyShotSound	= LoadSoundMem("Data/Sound/ミサイル.mp3");
	this->bossShotSound			= LoadSoundMem("Data/Sound/大砲2.mp3");
	this->enemyStartMoveSound	= LoadSoundMem("Data/Sound/紙袋を割る・破裂.mp3");
	this->playerJetSound		= LoadSoundMem("Data/Sound/きらきら輝く2.mp3");
	ChangeVolumeSoundMem(200, this->bgm);
	ChangeVolumeSoundMem(150, this->moneySound);
	Init();
}

/// <summary>
/// デストラクタ
/// </summary>
Sound::~Sound()
{
	//サウンドハンドルの削除
	DeleteSoundMem(this->buttonSound);
	DeleteSoundMem(this->bgm);
	DeleteSoundMem(this->bgm2);
	DeleteSoundMem(this->gameoverBGM);
	DeleteSoundMem(this->gameclearBGM);
	DeleteSoundMem(this->houseExplosionSound);
	DeleteSoundMem(this->playerExplosionSound);
	DeleteSoundMem(this->moneySound);
	DeleteSoundMem(this->normalEnemyShotSound);
	DeleteSoundMem(this->bossShotSound);
	DeleteSoundMem(this->enemyStartMoveSound);
	DeleteSoundMem(this->playerJetSound);
}

void Sound::Init()
{
	if (this->isPlayBGM)
	{
		StopSoundMem(this->bgm);
	}
	if (this->isPlayTitleBGM)
	{
		StopSoundMem(this->bgm2);
	}
	if (this->isPlayGameOverBGM)
	{
		StopSoundMem(this->gameoverBGM);
	}
	if (this->isPlayGameClearBGM)
	{
		StopSoundMem(this->gameclearBGM);
	}
	if (this->isPlayPlayerJetSound)
	{
		StopSoundMem(this->playerJetSound);
	}
	StopSoundMem(this->playerExplosionSound);
	this->isPlayButtonSound			 = false;
	this->isPlayBGM					 = false;
	this->isPlayTitleBGM			 = false;
	this->isPlayGameOverBGM			 = false;
	this->isPlayGameClearBGM		 = false;
	this->isPlayHouseExplosionSound  = false;
	this->isPlayPlayerExplosionSound = false;
	this->isPlayMoneySound			 = false;
	this->isPlayNormalShotSound		 = false;
	this->isPlayBossShotSound		 = false;
	this->isPlayEnemyStartMoveSound  = false;
	this->isPlayPlayerJetSound		 = false;
	this->jetSoundVolume = 100;
}

void Sound::PlayButtonSound()
{
	if (this->isPlayButtonSound)
	{
		if (CheckSoundMem(this->buttonSound) == 0)
		{
			this->isPlayButtonSound = false;
			StopSoundMem(this->buttonSound);
		}
	}

}
void Sound::PlayBGM()
{
	if (this->isPlayBGM)
	{
		if (CheckSoundMem(this->bgm) == 0)
		{
			this->isPlayBGM = false;
			StopSoundMem(this->bgm);
		}
	}
}
void Sound::PlayTitleBGM()
{
	if (this->isPlayTitleBGM)
	{
		if (CheckSoundMem(this->bgm2) == 0)
		{
			this->isPlayTitleBGM = false;
			StopSoundMem(this->bgm2);
		}
	}
}
void Sound::PlayGameOverBGM()
{
	if (this->isPlayGameOverBGM)
	{
		if (CheckSoundMem(this->gameoverBGM) == 0)
		{
			this->isPlayGameOverBGM = false;
			StopSoundMem(this->gameoverBGM);
		}
	}
}
void Sound::PlayGameClearBGM()
{
	if (this->isPlayGameClearBGM)
	{
		if (CheckSoundMem(this->gameclearBGM) == 0)
		{
			this->isPlayGameClearBGM = false;
			StopSoundMem(this->gameclearBGM);
		}
	}
}
void Sound::PlayHouseExplosionSound()
{
	if (this->isPlayHouseExplosionSound)
	{
		if (CheckSoundMem(this->houseExplosionSound) == 0)
		{
			this->isPlayHouseExplosionSound = false;
			StopSoundMem(this->houseExplosionSound);
		}
	}
}
void Sound::PlayPlayerExplosionSound()
{
	if (this->isPlayPlayerExplosionSound)
	{
		if (CheckSoundMem(this->playerExplosionSound) == 0)
		{
			this->isPlayPlayerExplosionSound = false;
			StopSoundMem(this->playerExplosionSound);
		}
	}
}
void Sound::PlayMoneySound()
{
	if (this->isPlayMoneySound)
	{
		if (CheckSoundMem(this->moneySound) == 0)
		{
			this->isPlayMoneySound = false;
			StopSoundMem(this->moneySound);
		}
	}
}
const void Sound::OnIsPlayButtonSound()
{ 
	if (!this->isPlayButtonSound)
	{
		this->isPlayButtonSound = true;
		PlaySoundMem(this->buttonSound, DX_PLAYTYPE_BACK, TRUE);
	}
}
const void Sound::OnIsPlayBGM() 
{ 
	if (!this->isPlayBGM)
	{
		this->isPlayBGM = true;
		PlaySoundMem(this->bgm, DX_PLAYTYPE_LOOP, TRUE);
	}

}
const void Sound::OnIsPlayTitleBGM()
{
	int check = 0;
	if (!this->isPlayTitleBGM)
	{
		this->isPlayTitleBGM = true;
		check = PlaySoundMem(this->bgm2, DX_PLAYTYPE_LOOP, TRUE);
	}

}
const void Sound::OnIsPlayGameOverBGM()
{
	if (!this->isPlayGameOverBGM)
	{
		this->isPlayGameOverBGM = true;
		PlaySoundMem(this->gameoverBGM, DX_PLAYTYPE_LOOP, TRUE);
	}

}
const void Sound::OnIsPlayGameClearBGM()
{
	if (!this->isPlayGameClearBGM)
	{
		this->isPlayGameClearBGM = true;
		PlaySoundMem(this->gameclearBGM, DX_PLAYTYPE_LOOP, TRUE);
	}

}
const void Sound::OnIsPlayHouseExplosionSound()
{ 
	if (!this->isPlayHouseExplosionSound)
	{
		this->isPlayHouseExplosionSound = true;
		PlaySoundMem(this->houseExplosionSound, DX_PLAYTYPE_BACK, TRUE);
	}

}
const void Sound::OnIsPlayPlayerExplosionSound()
{ 
	if (!this->isPlayPlayerExplosionSound)
	{
		this->isPlayPlayerExplosionSound = true;
		PlaySoundMem(this->playerExplosionSound, DX_PLAYTYPE_BACK, TRUE);
	}

}
const void Sound::OnIsPlayMoneySound()
{
	//if (!this->isPlayMoneySound)
	//{
		this->isPlayMoneySound = true;
		PlaySoundMem(this->moneySound, DX_PLAYTYPE_BACK, TRUE);
	//}
}

const void Sound::OnIsNormalShot()
{
	if (!this->isPlayNormalShotSound)
	{
		this->isPlayNormalShotSound = true;
		PlaySoundMem(this->normalEnemyShotSound, DX_PLAYTYPE_BACK, TRUE);
	}
}
const void Sound::OnIsBossShot()
{
	if (!this->isPlayBossShotSound)
	{
		this->isPlayBossShotSound = true;
		PlaySoundMem(this->bossShotSound, DX_PLAYTYPE_BACK, TRUE);
	}

}
const void Sound::OnIsEnemyStartMove()
{
	if (!this->isPlayEnemyStartMoveSound)
	{
		this->isPlayEnemyStartMoveSound = true;
		PlaySoundMem(this->enemyStartMoveSound, DX_PLAYTYPE_BACK, TRUE);
	}
}
const void Sound::OnIsJetSound()
{
	if (!this->isPlayPlayerJetSound)
	{
		this->isPlayPlayerJetSound = true;
		PlaySoundMem(this->playerJetSound, DX_PLAYTYPE_LOOP, TRUE);
	}
}
void Sound::PlayNormalShotSound()
{
	if (this->isPlayNormalShotSound)
	{
		if (CheckSoundMem(this->normalEnemyShotSound) == 0)
		{
			this->isPlayNormalShotSound = false;
			StopSoundMem(this->normalEnemyShotSound);
		}
	}
}
void Sound::PlayBossShotSound()
{
	if (this->isPlayBossShotSound)
	{
		if (CheckSoundMem(this->bossShotSound) == 0)
		{
			this->isPlayBossShotSound = false;
			StopSoundMem(this->bossShotSound);
		}
	}
}
void Sound::PlayEnemyStartMoveSound()
{
	if (this->isPlayEnemyStartMoveSound)
	{
		if (CheckSoundMem(this->enemyStartMoveSound) == 0)
		{
			this->isPlayEnemyStartMoveSound = false;
			StopSoundMem(this->enemyStartMoveSound);
		}
	}
}
void Sound::PlayJetSound()
{
	if (this->isPlayPlayerJetSound)
	{
		auto& character = CharacterManager::GetInstance();
		if (character.GetPlayerInstance().GetIsInput())
		{
			this->jetSoundVolume += 30;
			if (this->jetSoundVolume >= 255)
			{
				this->jetSoundVolume = 255;
			}
		}
		else
		{
			this->jetSoundVolume -= 1;
			if (this->jetSoundVolume <= 0)
			{
				this->jetSoundVolume = 0;
			}
		}


		if (CheckSoundMem(this->playerJetSound) == 0)
		{
			this->isPlayPlayerJetSound = false;
			StopSoundMem(this->playerJetSound);
		}
		ChangeVolumeSoundMem(jetSoundVolume, this->playerJetSound);
	}
}