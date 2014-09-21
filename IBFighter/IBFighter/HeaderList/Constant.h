#ifndef H_CONSTANT
#define H_CONSTANT

//画面幅
#define W_WIDTH 640
#define W_HEIGHT 480

//ゲームのステータス(大分岐用)
#define G_INIT		900000
#define G_TITLE		900001
#define G_BATTLE	911451

//色の略記
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

//重力設定
#define IB_GRAVITY	9.8		//重力加速度をそのまま使用

//描画ブレンド定数再定義
#define A_ON	DX_BLENDMODE_ALPHA
#define A_OFF	DX_BLENDMODE_NOBLEND

//キャラクラスの設定
#define C_MAX_HANDLE	10		//キャラハンドル最大数
#define C_MAX_SE		10		//SEハンドル最大数
#endif 
