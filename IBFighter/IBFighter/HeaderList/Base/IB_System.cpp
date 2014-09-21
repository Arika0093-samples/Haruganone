// --------------------------------------------------------
//	apcSystem.cpp
// --------------------------------------------------------
//	apcSystem.h のメンバ関数の実体を置く
// --------------------------------------------------------
#include "IB_BaseInclude.hpp"

// ----------------------------------------------------
//	ApplicationConfig
// ----------------------------------------------------
//	(Global Constructor)
// ----------------------------------------------------
UINT		ApplicationConfig::Width			= 640;
UINT		ApplicationConfig::Height			= 480;
tstring		ApplicationConfig::Title			= _T("DxLib");
tstring		ApplicationConfig::ClassName		= _T("DXLIB_APPLICATION");
tstring		ApplicationConfig::DefaultFontName	= ApplicationConfig::_GetDefaultFontName();
UINT		ApplicationConfig::Refresh			= 60;
bool		ApplicationConfig::ActiveAll		= false;
bool		ApplicationConfig::DualBoot			= false;
bool		ApplicationConfig::GDIDraw			= true;
bool		ApplicationConfig::WindowMode		= true;
bool		ApplicationConfig::AeroDisable		= false;

// ----------------------------------------------------
//	ApplicationConfig::Accept
// ----------------------------------------------------
void			ApplicationConfig::Accept()
{
	// ウィンドウのタイトル変更．
	SetMainWindowText(Title.c_str());
	// ウィンドウのクラス名変更．
	SetMainWindowClassName(ClassName.c_str());
	// アイコン変更．
	SetWindowIconID(1);
	// GDI描画のフラグを指定する
	SetUseGDIFlag(GDIDraw);
	// 二重起動のフラグを指定する．
	SetDoubleStartValidFlag(DualBoot);
	// 常に動作させるかどうかのフラグを指定する．
	SetAlwaysRunFlag(ActiveAll);
	// ウィンドウモードを変更．
	ChangeWindowMode(WindowMode);
	// ウィンドウサイズの変更．
	SetWindowSize(Width, Height);
	// 描画ウインドウサイズの変更．
	SetGraphMode(Width, Height, 32, Refresh);
}

// ----------------------------------------------------
//	ApplicationConfig::_GetDefaultFontName
// ----------------------------------------------------
tstring			ApplicationConfig::_GetDefaultFontName()
{
	// フォント名取得に使用する
	LOGFONT lgFont;
	// ------------------------------------------------
	// リセット
	memset(&lgFont, NULL, sizeof(LOGFONT));
	// システムのフォントを取得する
	SystemParametersInfo(SPI_GETICONTITLELOGFONT, sizeof(LOGFONT), &lgFont, 0);
	// 返却
	return lgFont.lfFaceName;
}	
