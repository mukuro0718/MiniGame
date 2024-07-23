//================================================================
// @brief �A�Z�b�g�̃��[�h�N���X
//================================================================
#pragma once
#include <cassert>

class LoadingAsset
{
public:
	virtual ~LoadingAsset();//�f�X�g���N�^

	/*�C���X�^���X�̍쐬*/
	static void CreateInstance()
	{
		instance = new LoadingAsset();
	}

	/*�C���X�^���X�̎擾*/
	static LoadingAsset& GetInstance()
	{
		//�C���X�^���X��null�̎��A��O�𔭐�������
		assert(instance != nullptr);
		return *instance;
	}

	/*�C���X�^���X�̍폜*/
	static void DeleteInstance()
	{
		//�����C���X�^���X��null����Ȃ�������
		if (instance != nullptr)
		{
			//�C���X�^���X���J�����Anull�ŏ���������
			delete(instance);
			instance = nullptr;
		}
	}


	/*���f���̎��*/
	enum class ModelType
	{
		CAR			= 0,
		CAR_BREAK	= 1,
		BAZOOKA		= 2,
		CANNON		= 3,
		BLUE_CAR	= 4,
		GRY_CAR		= 5,
		GREEN_CAR	= 6,
		RED_CAR		= 7,
		POLICE_CAR	= 8,
		FISH_1		= 9,
		FISH_2		= 10,
		FISH_3		= 11,
		FISH_4		= 12,
		BOSS_FISH	= 13,
		SKYDOME		= 14,
		ROAD		= 15,
		GEM_1		= 16,
		GEM_2		= 17,
		BUILDING_A	= 18,
		BUILDING_B	= 19,
		BUILDING_C	= 20,
		BUILDING_D	= 21,
		BUILDING_E	= 22,
		BUILDING_F	= 23,
		BUILDING_G	= 24,
		BUILDING_H	= 25,
		BASE		= 26,
		HOUSE		= 27,
		PLAYER		= 28,
	};

	/*�摜�̎��*/
	enum class ImageType
	{
		BACKGROUND_1	= 0,
		BACKGROUND_2	= 1,
		BACKGROUND_3	= 2,
		BACKGROUND_4	= 3,
		BACKGROUND_5	= 4,
		BACKGROUND_6	= 5,
		BACKGROUND_7	= 6,
		BACKGROUND_8	= 7,
		BACKGROUND_9	= 8,
		BACKGROUND_10	= 9,
		BACKGROUND_11	= 10,
		BACKGROUND_12	= 11,
		BACKGROUND_13	= 12,
		CAR				= 13,
		HOUSE			= 14,
		NOW_BAR			= 15,
		PREV_BAR		= 16,
		STAR_BLUE		= 17,
		STAR_GREEN		= 18,
		STAR_PURPLE		= 19,
		STAR_RED		= 20,
		STAR_YELLOW		= 21,
		EXPLOSION_01	= 22,
		EXPLOSION_02	= 23,
		EXPLOSION_03	= 24,
		EXPLOSION_04	= 25,
		EXPLOSION_05	= 26,
		EXPLOSION_06	= 27,
		EXPLOSION_07	= 28,
		EXPLOSION_08	= 29,
		EXPLOSION_09	= 30,
		EXPLOSION_10	= 31,
		EXPLOSION_11	= 32,
		EXPLOSION_12	= 33,
		EXPLOSION_13	= 34,
		EXPLOSION_14	= 35,
		EXPLOSION_15	= 36,
		EXPLOSION_16	= 37,
		EXPLOSION_17	= 38,
		EXPLOSION_18	= 39,
		EXPLOSION_19	= 40,
		EXPLOSION_20	= 41,
		EXPLOSION_21	= 42,
		EXPLOSION_22	= 43,
		EXPLOSION_23	= 44,
		EXPLOSION_24	= 45,
		EXPLOSION_25	= 46,
		EXPLOSION_26	= 47,
		EXPLOSION_27	= 48,
		EXPLOSION_28	= 49,
		TITLE_IMAGE		= 50,
		CLOUD			= 51,
		SMOKE_BLACK		= 52,
		MONEY_BAG		= 53,
		BUBBLE			= 54,
		SHADOW			= 55,
		BUTTON			= 56,
		TUTORIAL		= 57,
	};

	enum class FontType
	{
		MUKASI	 = 0,
		MUKASI_2 = 1,
		MUKASI_3 = 2,
		DOT = 3,
	};
	/*���f����getter*/
	const int GetModel(const int _index) { return modelHandle[_index]; }
	const int GetModelType(const ModelType _index) { return static_cast<int>(_index); }

	/*�摜��getter*/
	const int GetImage(const int _index) { return imageHandle[_index]; }
	const int GetImageType(const ImageType _index) { return static_cast<int>(_index); }

	/*�t�H���g��getter*/
	const int GetFont(const int _index) { return fontHandle[_index]; }
	const int GetFontType(const FontType _index) { return static_cast<int>(_index); }
private:
	/*���������֐�*/
	LoadingAsset();	 //�R���X�g���N�^

	/*�����o�ϐ�*/
	static LoadingAsset* instance;//�B��̃C���X�^���X

	vector<int> modelHandle;//���f���n���h��
	vector<int> imageHandle;//�摜�n���h��
	vector<int>	fontHandle; //�t�H���g�n���h��
};

