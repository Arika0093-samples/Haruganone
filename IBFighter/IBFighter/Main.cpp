// ----------------------------------------------------
//	Include
// ----------------------------------------------------
#include "DxLib.h"
#include "Base/IB_BaseInclude.hpp"
#include "Constant.h"

// ----------------------------------------------------
//	ゲームの初期化を行う関数
// ----------------------------------------------------
bool GetSetup()
{
	// ディレクトリ変更
	ApplicationConfig::SetProgramDirectory();
	// 設定変更
	ApplicationConfig::Width = W_WIDTH;
	ApplicationConfig::Height = W_HEIGHT;
	ApplicationConfig::Title = _T("IB_Fighters");
	ApplicationConfig::ClassName = _T("IB_Fighters");
	// 適用
	ApplicationConfig::Accept();

	// 初期化と裏画面化
	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK ) != 0){
		return false;
	}
	return true;
}

// ----------------------------------------------------
//	1フレームごとにキーなどの判定と終了処理などを行う
// ----------------------------------------------------
bool GameProcess(){
	// 画面適用
    ScreenFlip();
	// 裏画面に描画されている内容を消去．
	ClearDrawScreen();
	// もし終了なら
	if(ProcessMessage() == -1){
		return false;
	}
	// キー/マウスの状態更新
	KeyBoard::GetInstance()._CheckKeyEvent();
	Mouse::GetInstance()._CheckMouseEvent();
	// 返却
	return KeyBoard::Pushing(Key::Escape) == 0;
}

// ----------------------------------------------------
//	Function WinMain
// ----------------------------------------------------
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	// シーケンス管理クラスを確保してG_INITで初期化
	Sequencer Sqr = G_INIT;
	// シーケンス関数を登録
	Sqr.RegistFunction(G_INIT, [](Sequencer& Sq)
		{
			//初期化処理を実行

			//初期化終了後の状態遷移
			Sq.SetStatus(G_BATTLE);
		}
	);
	Sqr.RegistFunction(G_BATTLE, [](Sequencer& Sq)
		{  
			DrawBox(100,100,150,150,WHITE,TRUE);
		}
	);

	// ---------------------------------------------------
	// ゲームの初期化を行い失敗なら終了
	if( GetSetup() == false ){
		return 0;
	}

	// 1フレームごとに判定を行う
    while( GameProcess() == true ){
		Sqr.Process();

		#ifdef DEBUG	//デバッグモード時のみ発動
		//F9キーで各種設定確認
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
