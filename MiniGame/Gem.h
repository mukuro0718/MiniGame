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

    void        Init    ();                             //������
    void        Update  ();                             //�X�V
    const void  SetPrice(const int _in);                //�l�i�̃Z�b�g
    const void  SetPos  (const WrapVECTOR& _in);        //���W��getter
    const int   GetPrice()const { return this->price; } //�l�i��getter
    const bool  GetIsSet()const { return this->isSet; } //�Z�b�g�t���O��getter
    const bool  GetIsHit()const { return this->isHit; } //�q�b�g�t���O��getter
private:
    /*���������֐�*/
    const void  Draw()const;//�`��
    void        Move();     //�ړ�
    void		HitCheck(); //�����蔻��

    /*�����o�ϐ�*/
    int  modelHandle;   //���f���n���h��
    int  price;         //�l�i
    bool isSet;         //���W���Z�b�g���ꂽ��
    bool isHit;         //�v���C���[�Ɠ���������
};

