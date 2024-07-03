//===========================================================================
//@brief �A�j���[�V�����N���X
// �d�l��ŏ_��ɒl��ύX�ł���悤�ɁAgetter/setter�����p����Ă��邪
// ����ł̓J�v�Z�������ł��Ă��Ȃ��̂ŁA���ǂ̗]�n����
//===========================================================================

#pragma once
#include"DxLib.h"
#include<vector>
using namespace std;

class Animation
{
public:
    Animation();    //�R���X�g���N�^
    ~Animation();   //�f�X�g���N�^

    void Add   (const int _animModelHandle,const int _useAnimIndex);//�A�j���[�V�����̒ǉ�
    void Attach(int* _modelHandle);                                 //�A�j���[�V�����̃A�^�b�`
    void Play  (int* _modelHandle,const int _useAnimIndex ,const float _addAnimPlayTime);   //�A�j���[�V�����̍Đ�����

private:
    //�ϐ�
    vector<int> m_animModelHandle;  //�A�j���[�V�����̃��f���̃n���h��
    vector<int> m_useAnimIndex;     //�g�p�������A�j���[�V�����̔ԍ�
    float m_animTotalTime;          //�A�j���[�V�������Đ�����
    float m_animPlayTime;           //�A�j���[�V�����Đ�����
    bool  m_isChangeAnim;           //�A�j���[�V�����ύX�t���O�itrue:�ύX�\ false:�s�j
    int   m_animAttachIndex;        //�A�j���[�V�����A�^�b�`�ԍ�
    int   m_prevAnim;               //�O�̃A�j���[�V����
    int   m_nowAnim;                //���݂̃A�j���[�V����
};