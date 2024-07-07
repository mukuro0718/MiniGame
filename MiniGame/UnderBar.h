//=======================================================
// @brief 下のバークラス
//=======================================================
#pragma once

class UnderBar final
{
public:
    UnderBar();  //コンストラクタ
    ~UnderBar();                                            //デストラクタ

    void Init();//初期化
    void        Update  ();     //更新
    const void  Draw    ()const;//描画
private:
    /*構造体・列挙体*/
    //描画範囲
    struct DrawRect
    {
        DrawRect()
            : lx(0)
            , ly(0)
            , rx(0)
            , ry(0)
        {
        }
        int lx = 0;
        int ly = 0;
        int rx = 0;
        int ry = 0;
    };
    //画像の種類
    enum class ImageType
    {
        PREV    = 0,
        NOW     = 1,
        CAR     = 2,
        HOUSE   = 3,
    };

    /*内部処理関数*/
    void Convert(DrawRect& _pos,const vector<int> _in);

    /*メンバ変数*/
    vector<DrawRect>pos ;//座標
    vector<int> imageHandle;//画像ハンドル
};

