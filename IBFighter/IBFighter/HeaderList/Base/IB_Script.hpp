// --------------------------------------------------------
//	IB_Script.hpp
// --------------------------------------------------------
//	Lua�X�N���v�g�����֘A�̃N���X���L�ڂ���D
// --------------------------------------------------------
//	��x�����ǂݍ���
#pragma once
// --------------------------------------------------------
//	�K�v�ȃw�b�_�[��ǂݍ���
// --------------------------------------------------------
<<<<<<< Updated upstream
#include "IB_String.hpp"
#include <lua.hpp>
#include <luabind/luabind.hpp>

// --------------------------------------------------------
//	define�}�N�����g�p����
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
//	���O��Ԃ��g�p(IB_Base::Script)
// --------------------------------------------------------
namespace IB_Base
{
	namespace Script
	{
		/// <summary>
		///		Lua�X�N���v�g�����s����֐��Q���܂Ƃ߂��N���X�B
		/// </summary>
		class LuaScript
		{
			typedef		luabind::error LuaError;
		public:
			/// <summary>
			///		Lua�X�N���v�g�g�p�̏������s���B
			/// </summary>
<<<<<<< Updated upstream
			/// <param name = "File">
			///		�J���t�@�C���̃p�X�B
			/// </param>
						LuaScript(const char* File);
			/// <summary>
			///		Lua�Ŏg�p����ϐ��A�֐��Ȃǂ�o�^����֐�
			/// </summary>
			bool		Regist(luabind::scope Rg);
			/// <summary>
			///		"Main"�֐����Ăяo���B
			/// </summary>
			bool		Call() const;
			/// <summary>
			///		�w�肵���֐����Ăяo���B
			/// </summary>
			/// <param name = "FuncName">
			///		�Ăяo���֐����B
			/// </param>
			bool		Call(const char* FuncName) const;
			/// <summary>
			///		�G���[���b�Z�[�W���擾����
			/// </summary>
			std::string	GetErrorMessage() const;
			/// <summary>
			///		��O��������Assert���o�����ǂ����B
			///		�W����true�BDEBUG���̂ݗL���B
			/// </summary>
			bool		IsAssert;
=======
			LuaScript();
>>>>>>> Stashed changes
		private:
			/// <summary>
			///		�J���Ă���t�@�C����
			/// </summary>
			const char*	_Name;
			/// <summary>
			///		Lua�X�N���v�g�������\����
			/// </summary>
<<<<<<< Updated upstream
			lua_State*	_Ls;
			/// <summary>
			///		Luabind�̃G���[�ۑ�
			/// </summary>
			LuaError*	_Err;
=======
//			lua_State *_Ls;

>>>>>>> Stashed changes
		};
	}
}

