//==============================================================
// @brief　インプットマネージャークラス
// プロジェクト内で使用するパッド入力を保持する
// シングルトンで作成し、各クラスで入力状態を取得できるようにする
//==============================================================
#pragma once

class InputManager
{
public:
	virtual ~InputManager();//デストラクタ
	
	/*インスタンスの作成*/
	static void CreateInstance()
	{
		input = new InputManager();
	}
	
	/*インスタンスの削除*/
	static void DeleteInstance()
	{
		if (input != nullptr)
		{
			delete(input);
			input = nullptr;
		}
	}

	/*インスタンスを取得*/
	static InputManager& GetInstance()
	{
		return *input;
	}

	
	/*アナログスティック構造体*/
	struct InputAnalogStick
	{
		int XBuf = 0;
		int YBuf = 0;
	};
	
	/*移動に使用する一般的なキー*/
	enum class ComKeysForMove
	{
		W,
		A,
		S,
		D,
		SPACE,	 //上昇
		LCONTROL,//下降
	};

	/*矢印キー*/
	enum class ArrowKey
	{
		RIGHT,
		LEFT,
		UP,
		DOWN
	};

	void Update();//更新

	/*getter*/
	const int GetPadState()const { return this->pad; }//pad状態のgetter
	const bool GetReturnKeyState()const { return this->isInputReturnKey; }//key状態のgetter
	const bool GetComKeysForMoveState(const ComKeysForMove _index)const { return this->moveKey[convMoveKey.at(_index)]; }//移動キーの状態のgetter
	const bool GetArrowKeyState(const ArrowKey _index)const { return this->arrowKey[convArrowKey.at(_index)]; }//矢印キーの状態のgetter
	const InputAnalogStick GetLStickState()const { return this->lStick; }//左スティック状態のgetter
	const InputAnalogStick GetRStickState()const { return this->rStick; }//右スティック状態のgetter
	const DINPUT_JOYSTATE  GetButtonState()const { return this->button; }//十字ボタン入力取得用ボタン変数
private:
	/*静的定数*/
	static constexpr int ARROW_KEY_NUM = 4;//矢印キーの数
	static constexpr int COM_KEYS_FOR_MOVE = 6;//移動キーの数

	/*内部処理関数*/
	InputManager();//コンストラクタ
	void InputPadState();//PAD入力の取得
	void InputKeyState();//キーボード入力の取得

	/*メンバ変数*/
	static InputManager* input;//唯一のインスタンス
	InputAnalogStick lStick;
	InputAnalogStick rStick;
	DINPUT_JOYSTATE  button;
	int pad;//パッド入力変数
	bool isPrevInputReturnKey;//キー入力変数
	bool isInputReturnKey;//キー入力変数
	std::array<bool,COM_KEYS_FOR_MOVE> moveKey;//移動キー入力
	std::array<bool,ARROW_KEY_NUM> arrowKey;//矢印キー入力
	std::map< ComKeysForMove, int> convMoveKey;//移動キーの変換（列挙体からint）
	std::map< ArrowKey, int> convArrowKey;//矢印キーの変換（列挙体からint）
};

