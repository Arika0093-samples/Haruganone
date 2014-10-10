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
			LuaScript::LuaScript(const _FileBase &File) : _File(File)
{
	IsAssert = true;
	// New
	_Ls = luaL_newstate();
	// Use Default Lib
	luaL_openlibs(_Ls);
	// Used Setup
	luabind::open(_Ls);
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
		// FileRead
		auto LuaText = _File.Read();
		// Do
		//luaL_dostring();
	}
	catch(luabind::error &er){
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
