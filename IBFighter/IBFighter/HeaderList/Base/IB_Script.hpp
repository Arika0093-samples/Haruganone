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
#include "IB_File.hpp"
#include <memory>
#include <lua.hpp>
#include <luabind/luabind.hpp>

// --------------------------------------------------------
//	�Ȉ�define�}�N��
// --------------------------------------------------------
#define NormalFunction(fc)		luabind::def(#fc, fc)
#define RegistClass(ty)			luabind::class_<ty>(#ty)
#define ClassConstructor(ty)	def(luabind::constructor<ty>())
#define ClassFunction(bs, fc)	def(#fc, &bs::fc)
#define ClassVariable(bs, va)	def_readwrite(#va, &bs::va)

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
			/// <param name = "File">
			///		�J���t�@�C���̃p�X�B
			/// </param>
						LuaScript(const _FileBase &File);
			/// <summary>
			///		Lua�Ŏg�p����ϐ��A�֐��Ȃǂ�o�^����֐�
			/// </summary>
			bool		Regist(luabind::scope Rg);
			/// <summary>
			///		Main�֐����Ăяo���B
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
		private:
			/// <summary>
			///		�J���Ă���t�@�C����
			/// </summary>
			const _FileBase
						&_File;
			/// <summary>
			///		Lua�X�N���v�g�������\����
			/// </summary>
			lua_State*	_Ls;
			/// <summary>
			///		Luabind�̃G���[�ۑ�
			/// </summary>
			LuaError*	_Err;
		};
	}
}

