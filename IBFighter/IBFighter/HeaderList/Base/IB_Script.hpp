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
#include "IB_File.hpp"
#include <memory>
#include <lua.hpp>
#include <luabind/luabind.hpp>

// --------------------------------------------------------
//	簡易defineマクロ
// --------------------------------------------------------
#define NormalFunction(fc)		luabind::def(#fc, fc)
#define RegistClass(ty)			luabind::class_<ty>(#ty)
#define ClassConstructor(ty)	def(luabind::constructor<ty>())
#define ClassFunction(bs, fc)	def(#fc, &bs::fc)
#define ClassVariable(bs, va)	def_readwrite(#va, &bs::va)

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
			/// <param name = "File">
			///		開くファイルのパス。
			/// </param>
						LuaScript(const _FileBase &File);
			/// <summary>
			///		Luaで使用する変数、関数などを登録する関数
			/// </summary>
			bool		Regist(luabind::scope Rg);
			/// <summary>
			///		Main関数を呼び出す。
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
		private:
			/// <summary>
			///		開いているファイル名
			/// </summary>
			const _FileBase
						&_File;
			/// <summary>
			///		Luaスクリプトを扱う構造体
			/// </summary>
			lua_State*	_Ls;
			/// <summary>
			///		Luabindのエラー保存
			/// </summary>
			LuaError*	_Err;
		};
	}
}

