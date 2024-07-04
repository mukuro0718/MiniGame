//=============================================================
// @brief ��΃N���X
//=============================================================
#pragma once
#include "Object.h"

class Gem : public Object
{
public:
    Gem(const int _modelHandle, const int _price);  //�R���X�g���N�^
    ~Gem(); //�f�X�g���N�^

    void Init();    //������
    void Update();  //�X�V
    const void SetPrice(const int _in);
    const void SetPos(const WrapVECTOR& _in);
private:
    /*���������֐�*/
    const void Draw()const; //�`��
    void Move();            //�ړ�

    /*�����o�ϐ�*/
    int modelHandle;//���f���n���h��
    int price;      //�l�i
};

