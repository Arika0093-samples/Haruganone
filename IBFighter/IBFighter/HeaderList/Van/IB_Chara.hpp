// --------------------------------------------------------
//	IB_Chara.hpp
// --------------------------------------------------------
//	キャラクタの状態・動作を操作するクラスの生成
// --------------------------------------------------------
//
#pragma once

// --------------------------------------------------------
//	名前空間を使用(Apocalypse::Input)
// --------------------------------------------------------
namespace IB_Van
{
	namespace Charas
	{
		class Chara
		{
		public:
			/// <summary>
			///		コンストラクタ
			/// </summary>
			Chara();
			///	<summary>
			///		キャラの設定を行う関数
			///		name		:キャラクタの名前を記述
			///		戻り値はTRUE でキャラ生成成功
			///				FALSEでキャラ生成失敗
			///	</summary>
			bool SetChara(char *name);
			///	<summary>
			///		キャラを削除する関数
			///	</summary>
			void DeleteChara();
		private:
			/// <summary>
			///		各種キャラクタの状態を記憶
			/// </summary>
			//	描画関係
			int *handle;		//キャラの画像ハンドル
			int UsingMode;		//キャラの処理モード(CHARA_2Dで2Dキャラ,CHARA_3Dで3Dキャラを操作)
			int Subject;		//キャラの属性
			//	パラメ―タ関係
			double x;			//x座標(描画時はint型にキャストして使用)
			double y;			//y座標(描画時はint型にキャストして使用)
			int life;			//キャラのHP(0でdeadをTRUE)
			int IBP;			//キャラのIBP(InfinitBreakPercentage)
								//[使用例]IBP=126 -> 表示では12.6%を指すようにする
			int heavy;			//キャラの重量(重量ID CH_LITE,CH_NORMAL,CH_HEAVY)<-吹っ飛ばしやすさに関連
			int theform;		//第n形態を指す(nがtheformの値)
			//	キャラ状態関係
			bool player;		//プレイヤーキャラならTRUE(CPUキャラならFALSE)
			bool input;			//入力を許可していたらTRUE
			bool stand;			//地面に立っていたらTRUE
			bool attack;		//攻撃していたらTRUE
			bool dash;			//ダッシュしていたらTRUE
			bool exattack;		//必殺技中ならTRUE
			bool damage;		//ダメージを受けていたらTRUE
			bool dead;			//死亡状態に陥ったらTRUE
		};
	}
}
