#ifndef H_GAME
#define H_GAME

#include <windows.h>

#include "Constant.h"

class Game{
private :
	int status;		//ゲーム状態を記憶
public :
	SIZE screen;	//クライアント領域サイズ
	Game(SIZE data);			//コンストラクタ

	int GetStatus();	//ゲームステータスを取得
	void SetStatus(int data);	//ゲームステータスを設定



};

#endif 