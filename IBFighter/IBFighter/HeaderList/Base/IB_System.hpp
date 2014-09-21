// --------------------------------------------------------
//	IB_System.h
// --------------------------------------------------------
//	システム関連のクラスを記載する．
// --------------------------------------------------------
//	一度だけ読み込む
#pragma once

// --------------------------------------------------------
//	必要なヘッダーを読み込む
// --------------------------------------------------------
#include "IB_String.hpp"
#include "IB_BaseTemplate.hpp"

// --------------------------------------------------------
//	名前空間を使用(IB_Base::System)
// --------------------------------------------------------
namespace IB_Base
{
	namespace System
	{
		/// <summary>
		///		システムを動かすための各種初期設定項目をまとめたクラス．
		/// </summary>
		/// <remarks>
		///		このクラスの値を変更して，Accept関数を実行することで適用されます．
		/// </remarks>
		class ApplicationConfig
		{
		public:
			/// <summary>
			///		作成されるウインドウの横幅．
			/// </summary>
			static UINT				Width;
			/// <summary>
			///		作成されるウインドウの縦幅．
			/// </summary>
			static UINT				Height;
			/// <summary>
			///		リフレッシュレートの値．初期値は60．
			/// </summary>
			static UINT				Refresh;
			/// <summary>
			///		作成されるウインドウのタイトル名．
			/// </summary>
			static tstring			Title;
			/// <summary>
			///		作成されるウインドウのタイトル名．
			/// </summary>
			static tstring			ClassName;
			/// <summary>
			///		標準のフォント名．
			/// </summary>
			static tstring			DefaultFontName;
			/// <summary>
			///		非アクティブ時でも常に動作するかどうか．初期値はfalse．
			/// </summary>
			static bool				ActiveAll;
			/// <summary>
			///		Windows Vista以降のAeroを無効化するかどうか．標準ではfalse．
			/// </summary>
			static bool				AeroDisable;
			/// <summary>
			///		二重起動が可能かどうか．初期値はfalse．
			/// </summary>
			static bool				DualBoot;
			/// <summary>
			///		GDI描画を行うかどうか．初期値はfalse．
			/// </summary>
			static bool				GDIDraw;
			/// <summary>
			///		ウインドウモードで開始するかどうか．初期値はtrue．
			/// </summary>
			static bool				WindowMode;
			/// <summary>
			///		環境設定を適用する関数
			/// </summary>
			static void				Accept();
			/// <summary>
			///		カレントディレクトリを変更する
			/// </summary>
			static void				SetProgramDirectory();
			/// <summary>
			///		標準のフォント名を取得
			/// </summary>
			static tstring			_GetDefaultFontName();
		};
	}
}
