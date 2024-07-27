//=================================================
// @brief �W�F�b�g�G�t�F�N�g�N���X
//=================================================
#pragma once

class JetFlame;
class Jet
{
public:
    Jet();  //�R���X�g���N�^
    ~Jet(); //�f�X�g���N�^

    void        Init    ();     //������
    void        Update  ();     //�X�V
    const void  Draw    ()const;//�`��
private:
    static constexpr int FLAME_NUM = 30;

    /*���������֐�*/
    WrapVECTOR GetRandomMoveVec(const float _x, const int _yRange);//�ړ��x�N�g���������_���Ŏ擾
    float       GetRandom(const int _range);                        //float�^�l�������_���Ŏ擾
    float       GetRandomVelocity(const int _range);                //�ړ����x�������_���Ŏ擾
    /*�����o�ϐ�*/
    JetFlame*   flame[FLAME_NUM];
    int                 useFlame;
    int                 addCount;
    bool isInit;
};
