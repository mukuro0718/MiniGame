//======================================
// @brief �W�F�b�g�̉��N���X
//======================================
#pragma once

class WrapVECTOR;
class Transform;
class JetFlame
{
public:
    JetFlame    (const int _imageHandle);//�R���X�g���N�^
    ~JetFlame   ();//�f�X�g���N�^
    
    void                Init    (const float _size, const WrapVECTOR& _pos, const WrapVECTOR& _moveVec,const float _velocity);  //������
    void                Update  ();                                                                                             //�X�V
    const WrapVECTOR&   GetPos  ()const { return this->pos; }                                                                   //���W��getter
    const void          Draw    ()const;                                                                                        //�`��
private:
    /*���������֐�*/
    void        Move();     //�ړ�
    /*�����o�ϐ�*/
    WrapVECTOR  moveVec;    //�ړ��x�N�g��
    WrapVECTOR  pos;        //�`����W
    float       centerX;    //X���S���W�i0.0~1.0�j
    float       centerY;    //Y���S���W�i0.0~1.0�j
    float       size;       //�摜�T�C�Y
    float       angle;      //�摜�A���O��
    int         imageHandle;//�摜�n���h��
};

