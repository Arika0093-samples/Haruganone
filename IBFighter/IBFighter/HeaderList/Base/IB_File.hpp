// --------------------------------------------------------
//	IB_File.hpp
// --------------------------------------------------------
//	�t�@�C�������֘A�̃N���X���L�ڂ���D
// --------------------------------------------------------
//	��x�����ǂݍ���
#pragma once

// --------------------------------------------------------
//	�K�v�ȃw�b�_�[��ǂݍ���
// --------------------------------------------------------
#include <DxLib.h>
#include <memory>
#include "IB_String.hpp"

// --------------------------------------------------------
//	���O��Ԃ��g�p(IB_Base::File)
// --------------------------------------------------------
namespace IB_Base
{
	namespace File
	{
		/// <summary>
		///		�t�@�C���V�[�N�ʒu���w�肷�邽�߂�enum class
		/// </summary>
		enum class FileSeekPosition
		{
			/// <summary>
			///		�����ʒu
			/// </summary>
			Begin = 0,
			/// <summary>
			///		���݂̈ʒu
			/// </summary>
			Current,
			/// <summary>
			///		�t�@�C���I�[
			/// </summary>
			End,
		};

		/// <summary>
		///		�t�@�C������������N���X�̊��N���X�B
		///		���̃N���X���p�����Ďg�p����B
		/// </summary>
		class _FileBase
		{
		public:
			typedef				std::shared_ptr<TCHAR>		TcharPtr;
			/// <summary>
			///		�ǂݍ��񂾃t�@�C���̃p�X���擾����
			/// </summary>
			tstring				GetPath() const;
			/// <summary>
			///		�t�@�C���𕶎���Ƃ��Ă��ׂĎ擾����B
			/// </summary>
			TcharPtr			Read() const;
			/// <summary>
			///		�t�@�C������Size��Buffer�ɓǂݍ��ށB
			/// </summary>
			/// <param name = "Buf">
			///		�ǂݍ��܂���Ώۂ̃|�C���^�B
			/// </param>
			/// <param name = "Size">
			///		�ǂݍ��܂���T�C�Y�B
			/// </param>
			virtual bool		Read(void* Buf, UINT Size) const = 0;
			/// <summary>
			///		�t�@�C�������s���ǂݍ���
			/// </summary>
			virtual tstring		Gets() const = 0;
			/// <summary>
			///		�t�@�C������ꕶ�����ǂݍ��ށB
			/// </summary>
			virtual TCHAR		Getc() const = 0;
			/// <summary>
			///		�t�@�C���̏I�[���ǂ������擾����B
			/// </summary>
			virtual bool		Eof() const = 0;
			/// <summary>
			///		�t�@�C���T�C�Y���擾����B
			/// </summary>
			virtual UINT		Size() const = 0;
			/// <summary>
			///		�t�@�C���|�C���^�̈ʒu���擾����B
			/// </summary>
			virtual UINT		Tell() const = 0;
			/// <summary>
			///		�t�@�C���|�C���^�̈ʒu��ύX����B
			/// </summary>
			/// <param name = "Pos">
			///		�ύX�����܂��Ȉʒu�B
			/// </param>
			/// <param name = "Offset">
			///		Pos�Ŏw�肵���_����ǂꂮ�炢�����������w�肷��B�W����0�B
			/// </param>
			virtual UINT		Seek(FileSeekPosition Pos, int Offset = 0) const = 0;
			/// <summary>
			///		�t�@�C���n���h�����L�����ǂ�����ԋp����֐��B
			/// </summary>
			virtual bool		Valid() const = 0;
			/// <summary>
			///		�t�@�C���n���h�����L�����ǂ�����ԋp����operator
			/// </summary>
								operator bool() const;
		protected:
			/// <summary>
			///		constructor
			/// </summary>
								_FileBase(tstring Path);
			/// <summary>
			///		copy constructor
			/// </summary>
			/// <remark>
			///		�R�s�[�R���X�g���N�^�y�ё�����Z�q�́A�W���Ŗ����ɂ��Ă���܂��B
			///		���̗��R�Ƃ��āA�t�@�C���n���h���̎�舵���̖�肪����܂��B
			///		��ʓI�ɑ������ۂɂ͑����̃n���h�����폜���Ă������Ƃ�����@��
			///		�g���܂����A���̊��N���X�̓t�@�C���n���h���������Ȃ�����protected���Ă��܂��B
			///		��������ۂ͏�L�̂��Ƃ�O���ɂ�������Ŏ������Ă��������B
			/// </remark>
								_FileBase(const _FileBase&);
			/// <summary>
			///		destructor
			/// </summary>
			virtual				~_FileBase(){}
			/// <summary>
			///		������Z�q
			/// </summary>
			/// <remark>
			///		�R�s�[�R���X�g���N�^�y�ё�����Z�q�́A�W���Ŗ����ɂ��Ă���܂��B
			///		���R�̓R�s�[�R���X�g���N�^�̕����m�F���Ă��������B
			/// </remark>
			_FileBase&			operator=(const _FileBase&);
			/// <summary>
			///		�ǂݍ��ރt�@�C���̃p�X
			/// </summary>
			tstring				_Path;
		};

		/// <summary>
		///		Dx���C�u�����̊֐��Q���g�p���ē��������Ńt�@�C������������N���X�B
		/// </summary>
		class DxLibFile : public _FileBase
		{
		public:
			/// <summary>
			///		constructor
			/// </summary>
			/// <param name = "Path">
			///		�ǂݍ��܂���Ώۂ̃t�@�C���B
			/// </param>
								DxLibFile(tstring Path);
			/// <summary>
			///		destructor
			/// </summary>
			virtual				~DxLibFile();
			/// <summary>
			///		�t�@�C������Size��Buffer�ɓǂݍ��ށB
			/// </summary>
			/// <param name = "Buf">
			///		�ǂݍ��܂���Ώۂ̃|�C���^�B
			/// </param>
			/// <param name = "Size">
			///		�ǂݍ��܂���T�C�Y�B
			/// </param>
			virtual bool		Read(void* Buf, UINT Size) const;
			/// <summary>
			///		�t�@�C�������s���ǂݍ���
			/// </summary>
			virtual tstring		Gets() const;
			/// <summary>
			///		�t�@�C������ꕶ�����ǂݍ��ށB
			/// </summary>
			virtual TCHAR		Getc() const;
			/// <summary>
			///		�t�@�C���̏I�[���ǂ������擾����B
			/// </summary>
			virtual bool		Eof() const;
			/// <summary>
			///		�t�@�C���T�C�Y���擾����B
			/// </summary>
			virtual UINT		Size() const;
			/// <summary>
			///		�t�@�C���|�C���^�̈ʒu���擾����B
			/// </summary>
			virtual UINT		Tell() const;
			/// <summary>
			///		�t�@�C���|�C���^�̈ʒu��ύX����B
			/// </summary>
			/// <param name = "Pos">
			///		�ύX�����܂��Ȉʒu�B
			/// </param>
			/// <param name = "Offset">
			///		Pos�Ŏw�肵���_����ǂꂮ�炢�����������w�肷��B�W����0�B
			/// </param>
			virtual UINT		Seek(FileSeekPosition Pos, int Offset = 0) const;
			/// <summary>
			///		�t�@�C���n���h�����L�����ǂ�����ԋp����֐��B
			/// </summary>
			virtual bool		Valid() const;
		protected:
			/// <summary>
			///		�t�@�C���n���h��
			/// </summary>
			int					_Handle;
		};
	}
}