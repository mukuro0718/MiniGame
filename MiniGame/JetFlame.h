//======================================
// @brief ジェットの炎クラス
//======================================
#pragma once

class WrapVECTOR;
class Transform;
class JetFlame
{
public:
    JetFlame    (const int _imageHandle);//コンストラクタ
    ~JetFlame   ();//デストラクタ
    
    void                Init    (const float _size, const WrapVECTOR& _pos, const WrapVECTOR& _moveVec,const float _velocity);  //初期化
    void                Update  ();                                                                                             //更新
    const WrapVECTOR&   GetPos  ()const { return this->pos; }                                                                   //座標のgetter
    const void          Draw    ()const;                                                                                        //描画
private:
    /*内部処理関数*/
    void        Move();     //移動
    /*メンバ変数*/
    WrapVECTOR  moveVec;    //移動ベクトル
    WrapVECTOR  pos;        //描画座標
    float       centerX;    //X中心座標（0.0~1.0）
    float       centerY;    //Y中心座標（0.0~1.0）
    float       size;       //画像サイズ
    float       angle;      //画像アングル
    int         imageHandle;//画像ハンドル
};

