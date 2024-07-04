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

    void Init();    //初期化
    void Update();  //更新
    const void SetPrice(const int _in);
    const void SetPos(const WrapVECTOR& _in);
private:
    /*内部処理関数*/
    const void Draw()const; //描画
    void Move();            //移動

    /*メンバ変数*/
    int modelHandle;//モデルハンドル
    int price;      //値段
};

