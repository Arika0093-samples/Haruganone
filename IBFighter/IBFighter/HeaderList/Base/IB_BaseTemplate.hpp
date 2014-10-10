// --------------------------------------------------------
//	IB_BaseTemplate.h
// --------------------------------------------------------
//	�e���v���[�g�N���X���`����t�@�C���D
// --------------------------------------------------------
//	��x�����ǂݍ���
#pragma once

// --------------------------------------------------------
//	���O��Ԃ��g�p
// --------------------------------------------------------
namespace IB_Base
{
	// ----------------------------------------------------
	//	Template���O��ԓ��̃N���X���L��
	// ----------------------------------------------------
	namespace Template
	{
		template <class T>
		///	<summary>
		///		<para>Singleton�N���X����������ۂɎg�p����N���X�̃e���v���[�g�D</para>
		///		<para>�p������`�Ŏg�p����D</para>
		///	</summary>
		class _Singleton
		{
		public:
			/// <summary>
			///		���̂��擾����
			/// </summary>
			static T&			GetInstance()
			{
				static T Instance;
				return Instance;
			}
		protected:
			/// <summary>
			///		�R���X�g���N�^
			/// </summary>
								_Singleton(){}
			/// <summary>
			///		�f�X�g���N�^
			/// </summary>
			virtual				~_Singleton(){}
			/// <summary>
			///		�R�s�[�R���X�g���N�^
			/// </summary>
								_Singleton(const _Singleton&){}
			/// <summary>
			///		������Z�q
			/// </summary>
			void*				operator=(const _Singleton&){}
		};
	}
}