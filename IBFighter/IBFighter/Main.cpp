// ----------------------------------------------------
//	Include
// ----------------------------------------------------
#include "DxLib.h"
#include "Base/IB_BaseInclude.hpp"
#include "Constant.h"

// ----------------------------------------------------
//	�Q�[���̏��������s���֐�
// ----------------------------------------------------
bool GetSetup()
{
	// �f�B���N�g���ύX
	ApplicationConfig::SetProgramDirectory();
	// �ݒ�ύX
	ApplicationConfig::Width = W_WIDTH;
	ApplicationConfig::Height = W_HEIGHT;
	ApplicationConfig::Title = _T("IB_Fighters");
	ApplicationConfig::ClassName = _T("IB_Fighters");
	// �K�p
	ApplicationConfig::Accept();

	// �������Ɨ���ʉ�
	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK ) != 0){
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
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	// �V�[�P���X�Ǘ��N���X���m�ۂ���G_INIT�ŏ�����
	Sequencer Sqr = G_INIT;
	// �V�[�P���X�֐���o�^
	Sqr.RegistFunction(G_INIT, [](Sequencer& Sq)
		{
			//���������������s

			//�������I����̏�ԑJ��
			Sq.SetStatus(G_BATTLE);
		}
	);
	Sqr.RegistFunction(G_BATTLE, [](Sequencer& Sq)
		{  
			DrawBox(100,100,150,150,WHITE,TRUE);
		}
	);

	// ---------------------------------------------------
	// �Q�[���̏��������s�����s�Ȃ�I��
	if( GetSetup() == false ){
		return 0;
	}

	// 1�t���[�����Ƃɔ�����s��
    while( GameProcess() == true ){
		Sqr.Process();

		#ifdef DEBUG	//�f�o�b�O���[�h���̂ݔ���
		//F9�L�[�Ŋe��ݒ�m�F
			if(KeyBoard::Pushing(Key::F9) != 0){
				SetDrawBlendMode(A_ON,150);
				DrawFillBox(0,0, W_WIDTH, W_HEIGHT, BLACK);
				SetDrawBlendMode(A_OFF,0);
				DrawFormatString(0,0,WHITE, "STATUS:%d", Sqr.GetStatus());
			}
		#endif
    }
 
    DxLib_End();
    return 0;
}
