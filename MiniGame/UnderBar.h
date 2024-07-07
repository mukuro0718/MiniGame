//=======================================================
// @brief ���̃o�[�N���X
//=======================================================
#pragma once

class UnderBar final
{
public:
    UnderBar();  //�R���X�g���N�^
    ~UnderBar();                                            //�f�X�g���N�^

    void Init();//������
    void        Update  ();     //�X�V
    const void  Draw    ()const;//�`��
private:
    /*�\���́E�񋓑�*/
    //�`��͈�
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
    //�摜�̎��
    enum class ImageType
    {
        PREV    = 0,
        NOW     = 1,
        CAR     = 2,
        HOUSE   = 3,
    };

    /*���������֐�*/
    void Convert(DrawRect& _pos,const vector<int> _in);

    /*�����o�ϐ�*/
    vector<DrawRect>pos ;//���W
    vector<int> imageHandle;//�摜�n���h��
};

