
#include "DxLib.h"
#include "Constant.h"
#include "Game.h"	//�Q�[���֘A�̃w�b�_�[�t�@�C��

Game *game;			//�Q�[���N���X�g�p���邽�߂̃|�C���^

// ----------------------------------------------------
//	�Q�[���̏��������s���֐�
// ----------------------------------------------------
bool GetSetup()
{
	// �ݒ�ύX
	ApplicationConfig::Width = W_WIDTH;
	ApplicationConfig::Height = W_HEIGHT;
	ApplicationConfig::Title = _T("IB_Fighters");

	// �K�p
	ApplicationConfig::Accept();

	// �������Ɨ���ʉ�
	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0){
		return false;
	}
	return true;
}

// ----------------------------------------------------
//	1�t���[�����ƂɃL�[�Ȃǂ̔���ƏI�������Ȃǂ��s��
// ----------------------------------------------------
bool GameProcess(){
	// ��ʓK�p
    ScreenFlip();
	// ����ʂɕ`�悳��Ă�����e�������D
	ClearDrawScreen();
	// �����I���Ȃ�
	if(ProcessMessage() == -1){
		return false;
	}
	// �L�[/�}�E�X�̏�ԍX�V
	KeyBoard::GetInstance()._CheckKeyEvent();
	Mouse::GetInstance()._CheckMouseEvent();
	// �ԋp
	return KeyBoard::Pushing(Key::Escape) == 0;
}

// ----------------------------------------------------
//	Function WinMain
// ----------------------------------------------------
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	{
		SIZE size;size.cx=W_WIDTH,size.cy=W_HEIGHT;
		game = new Game(size);
	}

	// �Q�[���̏��������s�����s�Ȃ�I��
	if( GetSetup() == false ){
		return 0;
	}

	// 1�t���[�����Ƃɔ�����s��
    while( GameProcess() == true ){
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
			if(KeyBoard::Pushing(Key::F9) != 0){
				SetDrawBlendMode(A_ON,150);
				DrawFillBox(0,0,game->screen.cx,game->screen.cy,BLACK);
				SetDrawBlendMode(A_OFF,0);
				DrawFormatString(0,0,WHITE,"STATUS:%d",game->GetStatus());
			}
		#endif

    }
 
    DxLib_End();
    return 0;
}
