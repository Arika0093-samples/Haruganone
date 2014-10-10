// --------------------------------------------------------
//	IB_File.cpp
// --------------------------------------------------------
//	IB_File.hpp ÇÃÉÅÉìÉoä÷êîÇÃé¿ëÃÇíuÇ≠
// --------------------------------------------------------
#include "IB_BaseInclude.hpp"

// --------------------------------------------------------
//	_FileBase
// --------------------------------------------------------
//	_FileBase::_FileBase(constructor)
// --------------------------------------------------------
					_FileBase::_FileBase(tstring Path)
{
	_Path = Path;
}

// --------------------------------------------------------
//	_FileBase::FullRead
// --------------------------------------------------------
_FileBase::TcharPtr	_FileBase::Read() const
{
	auto Ptr = shared_ptr<TCHAR>();
	this->Read(Ptr.get(), this->Size());
	return Ptr;
}

// --------------------------------------------------------
//	_FileBase::GetFilePath
// --------------------------------------------------------
tstring				_FileBase::GetPath() const
{
	return _Path;
}

// --------------------------------------------------------
//	_FileBase::GetFilePath
// --------------------------------------------------------
					_FileBase::operator bool() const
{
	return this->Valid();
}

// --------------------------------------------------------
//	DxLibFile
// --------------------------------------------------------
//	DxLibFile::DxLibFile(constructor)
// --------------------------------------------------------
					DxLibFile::DxLibFile(tstring Path) : _FileBase(Path)
{
	// File Open
	_Handle = FileRead_open(_Path.c_str());
}

// --------------------------------------------------------
//	DxLibFile::~DxLibFile(destructor)
// --------------------------------------------------------
					DxLibFile::~DxLibFile()
{
	// File Close
	FileRead_close(_Handle);
}

// --------------------------------------------------------
//	DxLibFile::Load
// --------------------------------------------------------
DxLibFile::DxFlPtr	DxLibFile::Load(tstring Path)
{
	return make_shared<DxLibFile>();
}

// --------------------------------------------------------
//	DxLibFile::Read
// --------------------------------------------------------
bool				DxLibFile::Read(void* Buf, UINT Size) const
{
	// Read
	return ( FileRead_read(Buf, Size, _Handle) != -1 );
}

// --------------------------------------------------------
//	DxLibFile::Gets
// --------------------------------------------------------
tstring				DxLibFile::Gets() const
{
	// for read
	const int ReadSize = 1024;
	TCHAR Buf[ReadSize];
	FileRead_read(Buf, ReadSize - 1, _Handle);
	return tstring(Buf);
}

// --------------------------------------------------------
//	DxLibFile::Getc
// --------------------------------------------------------
TCHAR				DxLibFile::Getc() const
{
	return FileRead_getc(_Handle);
}

// --------------------------------------------------------
//	DxLibFile::Eof
// --------------------------------------------------------
bool				DxLibFile::Eof() const
{
	return ( FileRead_eof(_Handle) == TRUE );
}

// --------------------------------------------------------
//	DxLibFile::Size
// --------------------------------------------------------
UINT				DxLibFile::Size() const
{
	return FileRead_size(_Path.c_str());
}

// --------------------------------------------------------
//	DxLibFile::Tell
// --------------------------------------------------------
UINT				DxLibFile::Tell() const
{
	return FileRead_tell(_Handle);
}

// --------------------------------------------------------
//	DxLibFile::Seek
// --------------------------------------------------------
UINT				DxLibFile::Seek(FileSeekPosition Pos, int Offset) const
{
	return FileRead_seek((int)Pos, Offset, _Handle);
}

// --------------------------------------------------------
//	DxLibFile::Valid
// --------------------------------------------------------
bool				DxLibFile::Valid() const
{
	return ( _Handle != -1 );
}
