//===========================================================================
//@brief アニメーションクラス
// 仕様先で柔軟に値を変更できるように、getter/setterが多用されているが
// これではカプセル化ができていないので、改良の余地あり
//===========================================================================

#pragma once
#include"DxLib.h"
#include<vector>
using namespace std;

class Animation
{
public:
    Animation();    //コンストラクタ
    ~Animation();   //デストラクタ

    void Add   (const int _animModelHandle,const int _useAnimIndex);//アニメーションの追加
    void Attach(int* _modelHandle);                                 //アニメーションのアタッチ
    void Play  (int* _modelHandle,const int _useAnimIndex ,const float _addAnimPlayTime);   //アニメーションの再生時間

private:
    //変数
    vector<int> m_animModelHandle;  //アニメーションのモデルのハンドル
    vector<int> m_useAnimIndex;     //使用したいアニメーションの番号
    float m_animTotalTime;          //アニメーション総再生時間
    float m_animPlayTime;           //アニメーション再生時間
    bool  m_isChangeAnim;           //アニメーション変更フラグ（true:変更可能 false:不可）
    int   m_animAttachIndex;        //アニメーションアタッチ番号
    int   m_prevAnim;               //前のアニメーション
    int   m_nowAnim;                //現在のアニメーション
};