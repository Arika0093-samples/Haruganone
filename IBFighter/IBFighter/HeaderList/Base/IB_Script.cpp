// --------------------------------------------------------
//	IB_Script.cpp
// --------------------------------------------------------
//	IB_Script.h ÇÃÉÅÉìÉoä÷êîÇÃé¿ëÃÇíuÇ≠
// --------------------------------------------------------
#include "IB_BaseInclude.hpp"

// ----------------------------------------------------
//	LuaScript
// ----------------------------------------------------
//	LuaScript::LuaScript (Constructor)
// ----------------------------------------------------
			LuaScript::LuaScript(const char* File)
{
	IsAssert = true;
	// New
	_Ls = luaL_newstate();
	// Use Default Lib
	luaL_openlibs(_Ls);
	// Used Setup
	luabind::open(_Ls);
	_Name = File;
}

// ----------------------------------------------------
//	LuaScript::Regist
// ----------------------------------------------------
bool		LuaScript::Regist(luabind::scope Rg)
{
	try{
		// regist
		luabind::module(_Ls)[Rg];
	}
	catch(luabind::error &er){
		// assert
		Assert(IsAssert);
		// error copy
		*_Err = er;
		return false;
	}
	return true;
}

// ----------------------------------------------------
//	LuaScript::Call
// ----------------------------------------------------
bool		LuaScript::Call() const
{
	return LuaScript::Call("Main");
}

// ----------------------------------------------------
//	LuaScript::Call
// ----------------------------------------------------
bool		LuaScript::Call(const char* FuncName) const
{
	try{
		// FileOpen
		int Ret = luaL_dofile(_Ls, _Name);
		Assert(Ret == 0);
		// 
	}
	catch(luabind::error &er){
		// assert
		Assert(IsAssert);
		// error copy
		*_Err = er;
		return false;
	}
	return true;
}

// ----------------------------------------------------
//	LuaScript::GetErrorMessage
// ----------------------------------------------------
std::string	LuaScript::GetErrorMessage() const
{
	return lua_tostring(_Ls, -1);
}
