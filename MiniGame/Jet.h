//=================================================
// @brief ジェットエフェクトクラス
//=================================================
#pragma once

class JetFlame;
class Jet
{
public:
    Jet();  //コンストラクタ
    ~Jet(); //デストラクタ

    void        Init    ();     //初期化
    void        Update  ();     //更新
    const void  Draw    ()const;//描画
private:
    /*列挙隊*/

    /*内部処理関数*/
    WrapVECTOR& GetRandomMoveVec(const float _x, const int _yRange);//移動ベクトルをランダムで取得
    float       GetRandom(const int _range);                        //float型値をランダムで取得
    float       GetRandomVelocity(const int _range);                //移動速度をランダムで取得
    /*メンバ変数*/
    vector<JetFlame*>   flame;
    int                 useFlame;
    int                 addCount;
};
