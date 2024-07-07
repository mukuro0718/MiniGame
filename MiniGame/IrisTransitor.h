//=======================================
// @brief �A�C���X�C���E�A�E�g�N���X
// �~����ʂ̐^�񒆂Ɍ������ďk�܂�����A
// �t�ɐ^�񒆂���~�`�ɍL���銴��
//=======================================
class IrisTransitor : public Transitor
{
private:
	int handleForMaskScreen_;//�}�X�N�]���p�O���t�B�b�N�n���h��
	int maskH_;//�}�X�N�n���h��
	float diagonalLength_;//�Ίp���̒���
	bool irisOut_ = false;//�A�C���X�A�E�g�t���O(false�Ȃ�A�C���X�C��)
public:
	IrisTransitor(bool irisOut = false, int interval = 60, bool isTiled = false, int gHandle = -1);
	~IrisTransitor();
	virtual void Update() override;
	virtual void Draw() override;
};


