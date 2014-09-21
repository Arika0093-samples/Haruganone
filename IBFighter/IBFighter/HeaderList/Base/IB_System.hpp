// --------------------------------------------------------
//	IB_System.h
// --------------------------------------------------------
//	�V�X�e���֘A�̃N���X���L�ڂ���D
// --------------------------------------------------------
//	��x�����ǂݍ���
#pragma once

// --------------------------------------------------------
//	�K�v�ȃw�b�_�[��ǂݍ���
// --------------------------------------------------------
#include "IB_String.hpp"
#include "IB_BaseTemplate.hpp"

// --------------------------------------------------------
//	���O��Ԃ��g�p(IB_Base::System)
// --------------------------------------------------------
namespace IB_Base
{
	namespace System
	{
		/// <summary>
		///		�V�X�e���𓮂������߂̊e�평���ݒ荀�ڂ��܂Ƃ߂��N���X�D
		/// </summary>
		/// <remarks>
		///		���̃N���X�̒l��ύX���āCAccept�֐������s���邱�ƂœK�p����܂��D
		/// </remarks>
		class ApplicationConfig
		{
		public:
			/// <summary>
			///		�쐬�����E�C���h�E�̉����D
			/// </summary>
			static UINT				Width;
			/// <summary>
			///		�쐬�����E�C���h�E�̏c���D
			/// </summary>
			static UINT				Height;
			/// <summary>
			///		���t���b�V�����[�g�̒l�D�����l��60�D
			/// </summary>
			static UINT				Refresh;
			/// <summary>
			///		�쐬�����E�C���h�E�̃^�C�g�����D
			/// </summary>
			static tstring			Title;
			/// <summary>
			///		�쐬�����E�C���h�E�̃^�C�g�����D
			/// </summary>
			static tstring			ClassName;
			/// <summary>
			///		�W���̃t�H���g���D
			/// </summary>
			static tstring			DefaultFontName;
			/// <summary>
			///		��A�N�e�B�u���ł���ɓ��삷�邩�ǂ����D�����l��false�D
			/// </summary>
			static bool				ActiveAll;
			/// <summary>
			///		Windows Vista�ȍ~��Aero�𖳌������邩�ǂ����D�W���ł�false�D
			/// </summary>
			static bool				AeroDisable;
			/// <summary>
			///		��d�N�����\���ǂ����D�����l��false�D
			/// </summary>
			static bool				DualBoot;
			/// <summary>
			///		GDI�`����s�����ǂ����D�����l��false�D
			/// </summary>
			static bool				GDIDraw;
			/// <summary>
			///		�E�C���h�E���[�h�ŊJ�n���邩�ǂ����D�����l��true�D
			/// </summary>
			static bool				WindowMode;
			/// <summary>
			///		���ݒ��K�p����֐�
			/// </summary>
			static void				Accept();
			/// <summary>
			///		�J�����g�f�B���N�g����ύX����
			/// </summary>
			static void				SetProgramDirectory();
			/// <summary>
			///		�W���̃t�H���g�����擾
			/// </summary>
			static tstring			_GetDefaultFontName();
		};
	}
}
