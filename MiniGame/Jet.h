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

    void Init();    //������
    void Update();  //�X�V
private:
    /*�񋓑�*/

    /*�����o�ϐ�*/
    vector<JetFlame*> flame;
    int useFlame;
    int addCount;
};
