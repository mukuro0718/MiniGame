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
	ChangeVolumeSoundMem(150, this->bgm);
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
	StopSoundMem(this->playerExplosionSound);
	this->isPlayButtonSound = false;
	this->isPlayBGM = false;
	this->isPlayTitleBGM = false;
	this->isPlayGameOverBGM = false;
	this->isPlayGameClearBGM = false;
	this->isPlayHouseExplosionSound = false;
	this->isPlayPlayerExplosionSound = false;
	this->isPlayMoneySound = false;
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