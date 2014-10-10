// --------------------------------------------------------
//	IB_BaseTemplate.h
// --------------------------------------------------------
//	テンプレートクラスを定義するファイル．
// --------------------------------------------------------
//	一度だけ読み込む
#pragma once

// --------------------------------------------------------
//	名前空間を使用
// --------------------------------------------------------
namespace IB_Base
{
	// ----------------------------------------------------
	//	Template名前空間内のクラスを記載
	// ----------------------------------------------------
	namespace Template
	{
		template <class T>
		///	<summary>
		///		<para>Singletonクラスを実装する際に使用するクラスのテンプレート．</para>
		///		<para>継承する形で使用する．</para>
		///	</summary>
		class _Singleton
		{
		public:
			/// <summary>
			///		実体を取得する
			/// </summary>
			static T&			GetInstance()
			{
				static T Instance;
				return Instance;
			}
		protected:
			/// <summary>
			///		コンストラクタ
			/// </summary>
								_Singleton(){}
			/// <summary>
			///		デストラクタ
			/// </summary>
			virtual				~_Singleton(){}
			/// <summary>
			///		コピーコンストラクタ
			/// </summary>
								_Singleton(const _Singleton&){}
			/// <summary>
			///		代入演算子
			/// </summary>
			void*				operator=(const _Singleton&){}
		};
	}
}