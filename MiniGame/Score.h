//====================================================
// @brief �X�R�A�N���X
//====================================================
#pragma once

class Score
{
public:
	Score(const int _forPrice, const int _forSpecialPrice, const int _moneyBag);	//�R���X�g���N�^
	virtual ~Score();										//�f�X�g���N�^
	const void	Draw()const;								//�`��
private:
	/*�񋓑�*/
	//�\����
	struct Vec2d
	{
		int x = 0;
		int y = 0;
	};

	//�t�H���g�̎��
	enum class PosType
	{
		PRICE		  = 0,
		SPECIAL_SCORE = 1,
		IMAGE		  = 2,
	};
	/*�ÓI�萔*/
	static const int TEXT_COLOR_WHITE;//�������J���[

	/*���������֐�*/
	const void DrawPrice		(const int _price)const;//���i�̕`��
	const void DrawSpetialScore ()const;//���ʂȃX�R�A�̕`��
	Vec2d Convert(const vector<int> _in);

	/*�����o�ϐ�*/
	vector<int> fontHandle;
	vector<Vec2d> pos;
	int imageHandle;
};

