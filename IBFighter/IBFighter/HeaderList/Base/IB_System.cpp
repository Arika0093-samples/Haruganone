// --------------------------------------------------------
//	apcSystem.cpp
// --------------------------------------------------------
//	apcSystem.h �̃����o�֐��̎��̂�u��
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
	// �E�B���h�E�̃^�C�g���ύX�D
	SetMainWindowText(Title.c_str());
	// �E�B���h�E�̃N���X���ύX�D
	SetMainWindowClassName(ClassName.c_str());
	// �A�C�R���ύX�D
	SetWindowIconID(1);
	// GDI�`��̃t���O���w�肷��
	SetUseGDIFlag(GDIDraw);
	// ��d�N���̃t���O���w�肷��D
	SetDoubleStartValidFlag(DualBoot);
	// ��ɓ��삳���邩�ǂ����̃t���O���w�肷��D
	SetAlwaysRunFlag(ActiveAll);
	// �E�B���h�E���[�h��ύX�D
	ChangeWindowMode(WindowMode);
	// �E�B���h�E�T�C�Y�̕ύX�D
	SetWindowSize(Width, Height);
	// �`��E�C���h�E�T�C�Y�̕ύX�D
	SetGraphMode(Width, Height, 32, Refresh);
}

// ----------------------------------------------------
//	ApplicationConfig::_GetDefaultFontName
// ----------------------------------------------------
tstring			ApplicationConfig::_GetDefaultFontName()
{
	// �t�H���g���擾�Ɏg�p����
	LOGFONT lgFont;
	// ------------------------------------------------
	// ���Z�b�g
	memset(&lgFont, NULL, sizeof(LOGFONT));
	// �V�X�e���̃t�H���g���擾����
	SystemParametersInfo(SPI_GETICONTITLELOGFONT, sizeof(LOGFONT), &lgFont, 0);
	// �ԋp
	return lgFont.lfFaceName;
}	
