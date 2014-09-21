
#include "DxLib.h"
#include "Constant.h"
#include "Game.h"	//ゲーム関連のヘッダーファイル

Game *game;			//ゲームクラス使用するためのポインタ

// ----------------------------------------------------
//	ゲームの初期化を行う関数
// ----------------------------------------------------
bool GetSetup()
{
	// 設定変更
	ApplicationConfig::Width = W_WIDTH;
	ApplicationConfig::Height = W_HEIGHT;
	ApplicationConfig::Title = _T("IB_Fighters");

	// 適用
	ApplicationConfig::Accept();

	// 初期化と裏画面化
	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0){
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
