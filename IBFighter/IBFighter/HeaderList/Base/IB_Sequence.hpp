// --------------------------------------------------------
//	IB_Sequence.hpp
// --------------------------------------------------------
//	システム関連のクラスを記載する．
// --------------------------------------------------------
//	一度だけ読み込む
#pragma once

// --------------------------------------------------------
//	必要なヘッダーを読み込む
// --------------------------------------------------------
#include <map>
#include <functional>

// --------------------------------------------------------
//	名前空間を使用(IB_Base::Sequence)
// --------------------------------------------------------
namespace IB_Base
{
	namespace Sequence
	{
		/// <summary>
		///		シンプルなシーケンス管理クラス
		/// </summary>
		/// <remarks>
		///		Status値と対応した関数を登録することで自動振り分けが行われます。
		/// </remarks>
		class Sequencer
		{
		public:
			/// <summary>
			///		コンストラクタ
			/// </summary>
			Sequencer();
			/// <summary>
			///		コンストラクタ(引数でStatusを初期化)
			/// </summary>
			Sequencer(unsigned int Stat);
			/// <summary>
			///		現在のシーケンス状況に適した関数を実行する関数
			/// </summary>
			/// <return>
			///		戻り値: 関数内でシーケンスが変更された場合その番号を返します。
			///		シーケンスが変更されなかった場合は0です。
			/// </return>
			unsigned int Process();
			/// <summary>
			///		シーケンスに対応する関数を登録する
			/// </summary>
			/// <remarks>
			///		同じシーケンスに別の関数を指定した場合上書きされます。
			///		登録関数を削除したい場合はempty関数を同じシーケンスに割り当てることで削除されます。
			/// </remarks>
			/// <param name = "Stat">
			///		割り当てる対象のシーケンス番号
			/// </param>
			/// <param name = "Func">
			///		シーケンスに割り当てる関数（引数はSequencerの参照、戻り値はvoidの関数です）
			/// </param>
			void RegistFunction(unsigned int Stat, std::function<void(Sequencer&)> Fc);
			/// <summary>
			///		シーケンス状態取得
			/// </summary>
			unsigned int GetStatus() const;
			/// <summary>
			///		シーケンス状態設定
			/// </summary>
			void SetStatus(unsigned int Stat);
		private:
			/// <summary>
			///		登録関数管理
			/// </summary>
			std::map<unsigned int, std::function<void(Sequencer&)>> _FuncList;
			/// <summary>
			///		現在のシーケンス状態
			/// </summary>
			unsigned int _Status;
			/// <summary>
			///		シーケンスが変更された際に使用
			/// </summary>
			unsigned int _SeqChanged;
		};
	}
}