//========================================
// @brief 共通クラス
//jsonファイルを読み込み各変数に代入
// getterのみを実装し、ほかクラスに
// 値の変更を許可しない
//========================================
#pragma once
#include <DxLib.h>
#include <iostream>
#include <map>
#include <vector>
#include <array>
#include <string>
#include <list>
#include "json.hpp"
#include <fstream>
#include<cassert>
using json = nlohmann::json;
using namespace std;

#include "JsonManager.h"
#include "JsonLoader.h"
#include "SetUpScreen.h"
#include "InputManager.h"
#include "LoadingAsset.h"
#include "Animation.h"
#include "GameTimer.h"

#include "WrapVECTOR.h"
#include "Transform.h"
#include "Object.h"
#include "Character.h"
#include "Weapon.h"
#include "Amo.h"
#include "Adapter.h"
#include "Shadow.h"
#include "Skydome.h"
#include "HitResult.h"
#include "Gem.h"
#include "Building.h"
#include "House.h"
#include "BackGround.h"

#include "Cannon.h"
#include "Bazooka.h"
#include "Fish1.h"
#include "Fish2.h"
#include "Fish3.h"
#include "Fish4.h"
#include "Shark.h"
#include "GameCamera.h"
#include "TitleCamera.h"
#include "CameraManager.h"
#include "GamePlayer.h"
#include "Enemy.h"
#include "Normal.h"
#include "Boss.h"
#include "CharacterManager.h"
#include "WeaponManager.h"
#include "AmoManager.h"
#include "GameStage.h"
#include "StageManager.h"
#include "GemManager.h"

#include "Collision.h"
#include "SceneBase.h"
#include "SceneChanger.h"
#include "Game.h"
#include "Title.h"
#include "Result.h"
#include "Tutorial.h"
#include "LoadScene.h"
#include "FPSController.h"
#include "SceneManager.h"

#include "UI.h"
#include "Operation.h"
#include "UnderBar.h"

#include "UIManager.h"

#include "JetFlame.h"
#include "Jet.h"
#include "Explosion.h"
#include "EffectManager.h"