#define DEBUG

#include "DxLib.h"

#include "Constant.h"
#include "Game.h"	//�Q�[���֘A�̃w�b�_�[�t�@�C��

int Key[256];

#define W_WIDTH 640
#define W_HEIGHT 480

Game *game;			//�Q�[���N���X�g�p���邽�߂̃|�C���^

int GetHitKeyStateAll_2(int GetHitKeyStateAll_InputKey[]){
    char GetHitKeyStateAll_Key[256];
    GetHitKeyStateAll( GetHitKeyStateAll_Key );
    for(int i=0;i<256;i++){
        if(GetHitKeyStateAll_Key[i]==1) GetHitKeyStateAll_InputKey[i]++;
        else                            GetHitKeyStateAll_InputKey[i]=0;
    }
    return 0;
}
 
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	{
		SIZE size;size.cx=W_WIDTH,size.cy=W_HEIGHT;
		game = new Game(size);
	}
    ChangeWindowMode(TRUE);//�E�B���h�E���[�h
	SetUse3DFlag(TRUE);
	SetGraphMode(640,480,32,60);
	SetMainWindowText("IBFighters");//�^�C�g���ύX
	ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	if(ChangeFont("���C���I")==-1)return 0;
	SetFontThickness(1);
	SetFontSize(16);

	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//�������Ɨ���ʉ�
 
    while(ProcessMessage()==0 && ClearDrawScreen()==0 && GetHitKeyStateAll_2(Key)==0 && Key[KEY_INPUT_ESCAPE]==0){

		//�Q�[���X�e�[�^�X�ɂ���ĕ���
		switch(game->GetStatus()){
		case G_INIT:	//���������(�E�C���h�E�v���V�[�W���ł�WM_CREATE�ɑΉ�)

			game->SetStatus(G_BATTLE);//�f�o�b�O�p�Ȃ̂Ńo�g����Ԃ֑J��

			break;
		case G_TITLE:	//�^�C�g�����(G_INIT�̌�A��������OP��ɑJ�ڂ���悤�ɂ���)
			break;
		case G_BATTLE:	//�o�g�����(���̃Q�[���̈�ԃl�b�N�ȏ�ԁA�����炭��������ԕ��G)
			DrawBox(100,100,150,150,WHITE,TRUE);
			break;
		}

		#ifdef DEBUG	//�f�o�b�O���[�h���̂ݔ���
			//F9�L�[�Ŋe��ݒ�m�F
			if(Key[KEY_INPUT_F9]!=0){
				SetDrawBlendMode(A_ON,150);
				DrawFillBox(0,0,game->screen.cx,game->screen.cy,BLACK);
				SetDrawBlendMode(A_OFF,0);
				DrawFormatString(0,0,WHITE,"STATUS:%d",game->GetStatus());
			}
		#endif

        ScreenFlip();
    }
 
    DxLib_End();
    return 0;
}
