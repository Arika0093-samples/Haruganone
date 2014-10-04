#ifndef H_CONSTANT
#define H_CONSTANT

//DEBUG
#define DEBUG

//画面幅
#define W_WIDTH 1024
#define W_HEIGHT 576

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

//重力設定(重力加速度をそのまま使用)
#define GRAVITY	9.8

//描画ブレンド定数再定義(プログラム効率上昇を試みる)
#define A_ON	DX_BLENDMODE_ALPHA
#define A_OFF	DX_BLENDMODE_NOBLEND

//キャラクタの処理モードのID
#define CHARA_2D		222
#define CHARA_3D		333

//キャラクタの重量ID(吹っ飛ばしやすさに関連)
#define CH_LITE			25
#define CH_NORMAL		50
#define CH_HEAVY		75
#endif 
