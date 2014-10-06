// --------------------------------------------------------
//	IB_Script.hpp
// --------------------------------------------------------
//	Luaスクリプト処理関連のクラスを記載する．
// --------------------------------------------------------
//	一度だけ読み込む
#pragma once
// --------------------------------------------------------
//	必要なヘッダーを読み込む
// --------------------------------------------------------
<<<<<<< Updated upstream
#include "IB_String.hpp"
#include <lua.hpp>
#include <luabind/luabind.hpp>

// --------------------------------------------------------
//	defineマクロを使用する
// --------------------------------------------------------

=======
/*
extern "C"{
	#include <include/lua.h>
}
#include <luabind/luabind.hpp>
*/
>>>>>>> Stashed changes

// --------------------------------------------------------
//	名前空間を使用(IB_Base::Script)
// --------------------------------------------------------
namespace IB_Base
{
	namespace Script
	{
		/// <summary>
		///		Luaスクリプトを実行する関数群をまとめたクラス。
		/// </summary>
		class LuaScript
		{
			typedef		luabind::error LuaError;
		public:
			/// <summary>
			///		Luaスクリプト使用の準備を行う。
			/// </summary>
<<<<<<< Updated upstream
			/// <param name = "File">
			///		開くファイルのパス。
			/// </param>
						LuaScript(const char* File);
			/// <summary>
			///		Luaで使用する変数、関数などを登録する関数
			/// </summary>
			bool		Regist(luabind::scope Rg);
			/// <summary>
			///		"Main"関数を呼び出す。
			/// </summary>
			bool		Call() const;
			/// <summary>
			///		指定した関数を呼び出す。
			/// </summary>
			/// <param name = "FuncName">
			///		呼び出す関数名。
			/// </param>
			bool		Call(const char* FuncName) const;
			/// <summary>
			///		エラーメッセージを取得する
			/// </summary>
			std::string	GetErrorMessage() const;
			/// <summary>
			///		例外発生時にAssertを出すかどうか。
			///		標準でtrue。DEBUG時のみ有効。
			/// </summary>
			bool		IsAssert;
=======
			LuaScript();
>>>>>>> Stashed changes
		private:
			/// <summary>
			///		開いているファイル名
			/// </summary>
			const char*	_Name;
			/// <summary>
			///		Luaスクリプトを扱う構造体
			/// </summary>
<<<<<<< Updated upstream
			lua_State*	_Ls;
			/// <summary>
			///		Luabindのエラー保存
			/// </summary>
			LuaError*	_Err;
=======
//			lua_State *_Ls;

>>>>>>> Stashed changes
		};
	}
}

