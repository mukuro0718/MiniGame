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

    void Init();    //初期化
    void Update();  //更新
private:
    /*列挙隊*/

    /*メンバ変数*/
    vector<JetFlame*> flame;
    int useFlame;
    int addCount;
};
