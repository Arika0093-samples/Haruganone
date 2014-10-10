// --------------------------------------------------------
//	IB_File.hpp
// --------------------------------------------------------
//	ファイル処理関連のクラスを記載する．
// --------------------------------------------------------
//	一度だけ読み込む
#pragma once

// --------------------------------------------------------
//	必要なヘッダーを読み込む
// --------------------------------------------------------
#include <DxLib.h>
#include <memory>
#include "IB_String.hpp"

// --------------------------------------------------------
//	名前空間を使用(IB_Base::File)
// --------------------------------------------------------
namespace IB_Base
{
	namespace File
	{
		/// <summary>
		///		ファイルシーク位置を指定するためのenum class
		/// </summary>
		enum class FileSeekPosition
		{
			/// <summary>
			///		初期位置
			/// </summary>
			Begin = 0,
			/// <summary>
			///		現在の位置
			/// </summary>
			Current,
			/// <summary>
			///		ファイル終端
			/// </summary>
			End,
		};

		/// <summary>
		///		ファイルを処理するクラスの基底クラス。
		///		このクラスを継承して使用する。
		/// </summary>
		class _FileBase
		{
		public:
			typedef				std::shared_ptr<TCHAR>		TcharPtr;
			/// <summary>
			///		読み込んだファイルのパスを取得する
			/// </summary>
			tstring				GetPath() const;
			/// <summary>
			///		ファイルを文字列としてすべて取得する。
			/// </summary>
			TcharPtr			Read() const;
			/// <summary>
			///		ファイルからSize分Bufferに読み込む。
			/// </summary>
			/// <param name = "Buf">
			///		読み込ませる対象のポインタ。
			/// </param>
			/// <param name = "Size">
			///		読み込ませるサイズ。
			/// </param>
			virtual bool		Read(void* Buf, UINT Size) const = 0;
			/// <summary>
			///		ファイルから一行分読み込む
			/// </summary>
			virtual tstring		Gets() const = 0;
			/// <summary>
			///		ファイルから一文字分読み込む。
			/// </summary>
			virtual TCHAR		Getc() const = 0;
			/// <summary>
			///		ファイルの終端かどうかを取得する。
			/// </summary>
			virtual bool		Eof() const = 0;
			/// <summary>
			///		ファイルサイズを取得する。
			/// </summary>
			virtual UINT		Size() const = 0;
			/// <summary>
			///		ファイルポインタの位置を取得する。
			/// </summary>
			virtual UINT		Tell() const = 0;
			/// <summary>
			///		ファイルポインタの位置を変更する。
			/// </summary>
			/// <param name = "Pos">
			///		変更する大まかな位置。
			/// </param>
			/// <param name = "Offset">
			///		Posで指定した点からどれぐらい動かすかを指定する。標準で0。
			/// </param>
			virtual UINT		Seek(FileSeekPosition Pos, int Offset = 0) const = 0;
			/// <summary>
			///		ファイルハンドルが有効かどうかを返却する関数。
			/// </summary>
			virtual bool		Valid() const = 0;
			/// <summary>
			///		ファイルハンドルが有効かどうかを返却するoperator
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
			///		コピーコンストラクタ及び代入演算子は、標準で無効にしてあります。
			///		その理由として、ファイルハンドルの取り扱いの問題があります。
			///		一般的に代入する際には代入先のハンドルを削除してから代入という手法が
			///		使われますが、この基底クラスはファイルハンドルを持たないためprotectedしています。
			///		実装する際は上記のことを念頭においた上で実装してください。
			/// </remark>
								_FileBase(const _FileBase&);
			/// <summary>
			///		destructor
			/// </summary>
			virtual				~_FileBase(){}
			/// <summary>
			///		代入演算子
			/// </summary>
			/// <remark>
			///		コピーコンストラクタ及び代入演算子は、標準で無効にしてあります。
			///		理由はコピーコンストラクタの方を確認してください。
			/// </remark>
			_FileBase&			operator=(const _FileBase&);
			/// <summary>
			///		読み込むファイルのパス
			/// </summary>
			tstring				_Path;
		};

		/// <summary>
		///		Dxライブラリの関数群を使用して同期処理でファイルを処理するクラス。
		/// </summary>
		class DxLibFile : public _FileBase
		{
		public:
			/// <summary>
			///		constructor
			/// </summary>
			/// <param name = "Path">
			///		読み込ませる対象のファイル。
			/// </param>
								DxLibFile(tstring Path);
			/// <summary>
			///		destructor
			/// </summary>
			virtual				~DxLibFile();
			/// <summary>
			///		ファイルからSize分Bufferに読み込む。
			/// </summary>
			/// <param name = "Buf">
			///		読み込ませる対象のポインタ。
			/// </param>
			/// <param name = "Size">
			///		読み込ませるサイズ。
			/// </param>
			virtual bool		Read(void* Buf, UINT Size) const;
			/// <summary>
			///		ファイルから一行分読み込む
			/// </summary>
			virtual tstring		Gets() const;
			/// <summary>
			///		ファイルから一文字分読み込む。
			/// </summary>
			virtual TCHAR		Getc() const;
			/// <summary>
			///		ファイルの終端かどうかを取得する。
			/// </summary>
			virtual bool		Eof() const;
			/// <summary>
			///		ファイルサイズを取得する。
			/// </summary>
			virtual UINT		Size() const;
			/// <summary>
			///		ファイルポインタの位置を取得する。
			/// </summary>
			virtual UINT		Tell() const;
			/// <summary>
			///		ファイルポインタの位置を変更する。
			/// </summary>
			/// <param name = "Pos">
			///		変更する大まかな位置。
			/// </param>
			/// <param name = "Offset">
			///		Posで指定した点からどれぐらい動かすかを指定する。標準で0。
			/// </param>
			virtual UINT		Seek(FileSeekPosition Pos, int Offset = 0) const;
			/// <summary>
			///		ファイルハンドルが有効かどうかを返却する関数。
			/// </summary>
			virtual bool		Valid() const;
		protected:
			/// <summary>
			///		ファイルハンドル
			/// </summary>
			int					_Handle;
		};
	}
}