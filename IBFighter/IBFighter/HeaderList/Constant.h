#ifndef H_CONSTANT
#define H_CONSTANT

//DEBUG
#define DEBUG

//��ʕ�
#define W_WIDTH 1024
#define W_HEIGHT 576

//�Q�[���̃X�e�[�^�X(�啪��p)
#define G_INIT		900000
#define G_TITLE		900001
#define G_BATTLE	911451

//�F�̗��L
#define BLACK	GetColor(  0,  0,  0)
#define WHITE	GetColor(255,255,255)
#define GRAY	GetColor(150,150,150)
#define BLUE	GetColor(  0,  0,255)
#define SKY		GetColor(  0, 80,255)
#define GREEN	GetColor(  0,255,  0)
#define YELLOW	GetColor(255,255,  0)
#define RED		GetColor(255,  0,  0)
#define ORANGE  GetColor(255,150,  0)
#define PINK	GetColor(255,  0,150)

//�d�͐ݒ�(�d�͉����x�����̂܂܎g�p)
#define GRAVITY	9.8

//�`��u�����h�萔�Ē�`(�v���O���������㏸�����݂�)
#define A_ON	DX_BLENDMODE_ALPHA
#define A_OFF	DX_BLENDMODE_NOBLEND

//�L�����N�^�̏������[�h��ID
#define CHARA_2D		222
#define CHARA_3D		333

//�L�����N�^�̏d��ID(������΂��₷���Ɋ֘A)
#define CH_LITE			25
#define CH_NORMAL		50
#define CH_HEAVY		75
#endif 
