#define DEBUG

#include "DxLib.h"

#include "Constant.h"
#include "Game.h"	//ゲーム関連のヘッダーファイル

int Key[256];

#define W_WIDTH 640
#define W_HEIGHT 480

Game *game;			//ゲームクラス使用するためのポインタ

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
    ChangeWindowMode(TRUE);//ウィンドウモード
	SetUse3DFlag(TRUE);
	SetGraphMode(640,480,32,60);
	SetMainWindowText("IBFighters");//タイトル変更
	ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	if(ChangeFont("メイリオ")==-1)return 0;
	SetFontThickness(1);
	SetFontSize(16);

	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//初期化と裏画面化
 
    while(ProcessMessage()==0 && ClearDrawScreen()==0 && GetHitKeyStateAll_2(Key)==0 && Key[KEY_INPUT_ESCAPE]==0){

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
