#define DEBUG

#include "DxLib.h"

#include "Constant.h"
#include "Game.h"	//ゲーム関連のヘッダーファイル

Game *game;			//ゲームクラス使用するためのポインタ

bool GetSetup()
{
	// Window Mode
    ChangeWindowMode(TRUE);
	SetUse3DFlag(TRUE);
	SetGraphMode(640,480,32);
	// Title
	SetMainWindowText("IBFighters");
	ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	if(ChangeFont("メイリオ") == -1){
		return false;
	}
	SetFontThickness(1);
	SetFontSize(16);

	// 初期化と裏画面化
	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0){
		return false;
	}
	return true;
}

bool GameProcess(){
	// 画面適用
    ScreenFlip();
	// キー/マウスの状態更新
	KeyBoard::GetInstance()._CheckKeyEvent();
	Mouse::GetInstance()._CheckMouseEvent();
	// 返却
	return ProcessMessage() == 0
		&& ClearDrawScreen() == 0
		&& KeyBoard::Pushing(Key::Escape) == 0;
}


int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	{
		SIZE size;size.cx=W_WIDTH,size.cy=W_HEIGHT;
		game = new Game(size);
	}

	// ゲームの初期化を行い失敗なら終了
	if( GetSetup() == false ){
		return 0;
	}

	// 1フレームごとに判定を行う
    while( GameProcess() == true ){

		//ゲームステータスによって分岐
		switch(game->GetStatus()){
		case G_INIT:	//初期化状態(ウインドウプロシージャでのWM_CREATEに対応)

			game->SetStatus(G_BATTLE);//デバッグ用なのでバトル状態へ遷移

			break;
		case G_TITLE:	//タイトル状態(G_INITの後、もしくはOP後に遷移するようにする)
			break;
		case G_BATTLE:	//バトル状態(このゲームの一番ネックな状態、おそらくここが一番複雑)
			DrawBox(100,100,150,150,WHITE,TRUE);
			break;
		}

		#ifdef DEBUG	//デバッグモード時のみ発動
			//F9キーで各種設定確認
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
