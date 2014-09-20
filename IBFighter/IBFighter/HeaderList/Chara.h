#ifndef H_CHARA
#define H_CHARA

#include "Constant.h"

//キャラクタークラス
class Chara
{
private :
	int handle[C_MAX_HANDLE];	//テスクチャハンドル設定
	int se[C_MAX_SE];			//キャラごとのSEハンドル
public :
	int x;						//キャラx座標
	int y;						//キャラy座標

	Chara();					//コンストラクタ

	void Load();				//0番目をロード	(多数使用しない場合はこっち)
	void Load(int num);			//num番目をロード

	void Update();				//様々な計算処理
	void Draw();				//キャラを描画
};

#endif