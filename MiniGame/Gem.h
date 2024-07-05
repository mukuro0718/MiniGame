//=============================================================
// @brief 宝石クラス
//=============================================================
#pragma once
#include "Object.h"

class Gem : public Object
{
public:
    Gem(const int _modelHandle, const int _price);  //コンストラクタ
    ~Gem(); //デストラクタ

    void        Init    ();                             //初期化
    void        Update  ();                             //更新
    const void  SetPrice(const int _in);                //値段のセット
    const void  SetPos  (const WrapVECTOR& _in);        //座標のgetter
    const int   GetPrice()const { return this->price; } //値段のgetter
    const bool  GetIsSet()const { return this->isSet; } //セットフラグのgetter
    const bool  GetIsHit()const { return this->isHit; } //ヒットフラグのgetter
private:
    /*内部処理関数*/
    const void  Draw()const;//描画
    void        Move();     //移動
    void		HitCheck(); //当たり判定

    /*メンバ変数*/
    int  modelHandle;   //モデルハンドル
    int  price;         //値段
    bool isSet;         //座標がセットされたか
    bool isHit;         //プレイヤーと当たったか
};

