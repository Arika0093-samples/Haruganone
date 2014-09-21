// --------------------------------------------------------
//	IB_Input.cpp
// --------------------------------------------------------
//	IB_Input.h �̃����o�֐��̎��̂�u��
// --------------------------------------------------------
#include "IB_BaseInclude.hpp"

// ----------------------------------------------------
//	KeyBoard
// ----------------------------------------------------
//	KeyBoard::KeyBoard (Constructor)
// ----------------------------------------------------
				KeyBoard::KeyBoard()
{
	// �L�[�̏�Ԓl�����Z�b�g����
	memset(_KeyInput, 0, sizeof(_KeyInput));
	return;
}

// ----------------------------------------------------
//	KeyBoard::AnyKeyPushing
// ----------------------------------------------------
bool			KeyBoard::AnyPushing()
{
	// ���͏�Ԃ�ԋp����
	return (CheckHitKeyAll() != 0);
}

// ----------------------------------------------------
//	KeyBoard::KeyPushing
// ----------------------------------------------------
UINT			KeyBoard::Pushing(const _KeysData &TargetKey)
{
	// ���ʕԋp�p
	int Result = 0;
	// �L�[�̏�Ԃ��擾����
	for(size_t i = 0; i < TargetKey._Size(); i++){
		// �����������or�O�̒l��菬�����Ȃ�
		if(Result == 0 || Result > GetInstance()._KeyInput[TargetKey._Get(i)]){
			// �擾
			Result = GetInstance()._KeyInput[TargetKey._Get(i)];
		}
		// �����l���}�C�i�X�őS��������Ȃ�
		if((Result < 0) && TargetKey.IsCheckAllKey){
			// ������Ă��Ȃ�
			return 0;
		}
	}
	// �ԋp
	return max(Result, 0);
}

// ----------------------------------------------------
//	KeyBoard::KeyPushStarted
// ----------------------------------------------------
bool			KeyBoard::PushStart(const _KeysData &TargetKey)
{
	// ���ʕԋp�p
	bool Result = false, NowTime = false;
	// �L�[�̏�Ԃ��擾����
	for(size_t i = 0; i < TargetKey._Size(); i++){
		// �Ώۂ̃L�[��������Ă邩�m�F
		Result	= (GetInstance()._KeyInput[TargetKey._Get(i)] > 0);
		// 1�ȏ�̃L�[�����݉����ꂽ�΂��肩�ǂ����擾
		NowTime = (NowTime ? true : (GetInstance()._KeyInput[TargetKey._Get(i)] == 1));
		// �����l��false�őS��������Ȃ�
		if(!Result && TargetKey.IsCheckAllKey){
			// ������Ă��Ȃ�
			return false;
		}
	}
	// �S��������Ȃ�ΏۃL�[���S�ĉ�����Ă��邩�ǂ��� + ���݂ǂꂩ��ȏオ�����ꂽ��
	// �����łȂ��Ȃ猻�݂ǂꂩ��ȏオ�����ꂽ���̏���ԋp����
	return (( Result || !TargetKey.IsCheckAllKey) && NowTime);
}

// ----------------------------------------------------
//	KeyBoard::KeyPushStarted
// ----------------------------------------------------
bool			KeyBoard::OutStart(const _KeysData &TargetKey)
{
	// ���ʕԋp�p
	bool Result = false, NowTime = false;
	// �L�[�̏�Ԃ��擾����
	for(size_t i = 0; i < TargetKey._Size(); i++){
		// �Ώۂ̃L�[��������Ă��邩�m�F
		Result	= (GetInstance()._KeyInput[TargetKey._Get(i)] < 0);
		// 1�ȏ�̃L�[�����ݗ����ꂽ�΂��肩�ǂ����擾
		NowTime = (NowTime ? true : (GetInstance()._KeyInput[TargetKey._Get(i)] == -1));
		// �����l��false�őS��������Ȃ�
		if(!Result && TargetKey.IsCheckAllKey){
			// ������Ă���
			return false;
		}
	}
	// �S��������Ȃ�ΏۃL�[���S�ė�����Ă��邩�ǂ��� + ���݂ǂꂩ��ȏオ�����ꂽ��
	// �����łȂ��Ȃ猻�݂ǂꂩ��ȏオ�����ꂽ���̏���ԋp����
	return (( Result || !TargetKey.IsCheckAllKey) && NowTime);
}

// ----------------------------------------------------
//	KeyBoard::_CheckKeyEvent
// ----------------------------------------------------
void			KeyBoard::_CheckKeyEvent()
{
	// �L�[�̏�Ԃ��擾���邽�߂̕ϐ�
	char KeyEvent[256];
	// ------------------------------------------------
	// �擾����
	GetHitKeyStateAll(KeyEvent);
	// �v�f���������[�v����
	for(int Loop = 0; Loop < 256; Loop++)
	{
		// ����������Ă���
		if(KeyEvent[Loop] == 1){
			// ���߂ĉ�����Ă��Ȃ�
			if(_KeyInput[Loop] < 0){
				// 0�Ƀ��Z�b�g
				_KeyInput[Loop] = 0;
			}
			// �C���N�������g����
			_KeyInput[Loop]++;
		}
		// ����������Ă��Ȃ���
		else{
			// �����L�[�̒l��0�Ȃ�i������ԂȂ�j
			if(_KeyInput[Loop] == 0){
				// �������đ��s����
				continue;
			}
			// ���߂ė����ꂽ�Ȃ�
			if(_KeyInput[Loop] > 0){
				// 0�Ƀ��Z�b�g
				_KeyInput[Loop] = 0;
			}
			// �f�N�������g����
			_KeyInput[Loop]--;
		}
	}
	// �I��
	return;
}

// ----------------------------------------------------
//	Mouse
// ----------------------------------------------------
//	Mouse::Mouse
// ----------------------------------------------------
				Mouse::Mouse()
{
	_MousePushTimeLeft = 0;
	_MousePushTimeRight = 0;
}

// ----------------------------------------------------
//	Mouse::MousePushing
// ----------------------------------------------------
int				Mouse::LeftPushing()
{
	// �}�E�X�̏�Ԃ��擾���Đ��̒l�Ȃ炻�̂܂ܕԋp����
	return (GetInstance()._MousePushTimeLeft > 0 ?
			GetInstance()._MousePushTimeLeft : 0);
}

// ----------------------------------------------------
//	Mouse::MousePushStarted
// ----------------------------------------------------
bool			Mouse::LeftPushStart()
{
	// �}�E�X��Ԃ��擾���ĉ����ꂽ�u�ԂȂ�true��Ԃ�
	return (GetInstance()._MousePushTimeLeft == 1);
}

// ----------------------------------------------------
//	Mouse::MouseOutStart
// ----------------------------------------------------
bool			Mouse::LeftOutStart()
{
	// �}�E�X��Ԃ��擾���ė����ꂽ�u�ԂȂ�true��Ԃ�
	return (GetInstance()._MousePushTimeLeft == -1);
}

// ----------------------------------------------------
//	Mouse::MousePushing
// ----------------------------------------------------
int				Mouse::RightPushing()
{
	// �}�E�X�̏�Ԃ��擾���Đ��̒l�Ȃ炻�̂܂ܕԋp����
	return (GetInstance()._MousePushTimeRight > 0 ?
			GetInstance()._MousePushTimeRight : 0);
}

// ----------------------------------------------------
//	Mouse::MousePushStarted
// ----------------------------------------------------
bool			Mouse::RightPushStart()
{
	// �}�E�X��Ԃ��擾���ĉ����ꂽ�u�ԂȂ�true��Ԃ�
	return (GetInstance()._MousePushTimeRight == 1);
}

// ----------------------------------------------------
//	Mouse::MouseOutStart
// ----------------------------------------------------
bool			Mouse::RightOutStart()
{
	// �}�E�X��Ԃ��擾���ė����ꂽ�u�ԂȂ�true��Ԃ�
	return (GetInstance()._MousePushTimeRight == -1);
}

// ----------------------------------------------------
//	Mouse::IsMove
// ----------------------------------------------------
bool			Mouse::IsMove()
{
	return (GetInstance()._MouseLocation != GetInstance()._MouseBeforeLoc);
}

// ----------------------------------------------------
//	Mouse::GetMousePosition
// ----------------------------------------------------
Value::Point	Mouse::GetPosition()
{
	// �擾���Ă������}�E�X�ʒu��ԋp����
	return GetInstance()._MouseLocation;
}

// ----------------------------------------------------
//	Mouse::SetMousePosition
// ----------------------------------------------------
void			Mouse::SetPosition(int X, int Y)
{
	// �}�E�X�ʒu���w��̈ʒu�Ɉړ�������
	SetMousePoint( X, Y);
	// ���炩���ߎ擾�����ʒu���ύX����
	GetInstance()._MouseLocation.X = X;
	GetInstance()._MouseLocation.Y = Y;
	// �I��
	return;
}

// ----------------------------------------------------
//	Mouse::CheckMouseEvent
// ----------------------------------------------------
void			Mouse::_CheckMouseEvent()
{
	// �}�E�X��X, Y���W���擾���邽�߂̕ϐ�
	int MouseX, MouseY;
	// ------------------------------------------------
	// �����}�E�X��������Ă���
	if(GetMouseInput() & MOUSE_INPUT_LEFT){
		// ���߂ĉ�����Ă��Ȃ�
		if(_MousePushTimeLeft < 0){
			// 0�Ƀ��Z�b�g
			_MousePushTimeLeft = 0;
		}
		// �C���N�������g����
		_MousePushTimeLeft++;
	}
	// �����}�E�X��������Ă��Ȃ���
	else{
		// ���߂ė����ꂽ�Ȃ�
		if(_MousePushTimeLeft > 0){
			// 0�Ƀ��Z�b�g
			_MousePushTimeLeft = 0;
		}
		// �f�N�������g����
		_MousePushTimeLeft--;
	}
	// �����}�E�X��������Ă���
	if(GetMouseInput() & MOUSE_INPUT_RIGHT){
		// ���߂ĉ�����Ă��Ȃ�
		if(_MousePushTimeRight < 0){
			// 0�Ƀ��Z�b�g
			_MousePushTimeRight = 0;
		}
		// �C���N�������g����
		_MousePushTimeRight++;
	}
	// �����}�E�X��������Ă��Ȃ���
	else{
		// ���߂ė����ꂽ�Ȃ�
		if(_MousePushTimeRight > 0){
			// 0�Ƀ��Z�b�g
			_MousePushTimeRight = 0;
		}
		// �f�N�������g����
		_MousePushTimeRight--;
	}
	// ���݈ʒu���擾
	GetMousePoint( &MouseX, &MouseY );
	// ���݂̍��W��ۑ�
	_MouseBeforeLoc = _MouseLocation;
	// �擾�������ʂ�������
	_MouseLocation( MouseX, MouseY);
	// �I��
	return;
}

// ----------------------------------------------------
//	_KeysData
// ----------------------------------------------------
//	_KeysData::_KeysData (Constructor)
// ----------------------------------------------------
				_KeysData::_KeysData()
{
	// ������
	_CheckKeyList.clear();
	// ���胂�[�h���w��
	IsCheckAllKey = false;
}

// ----------------------------------------------------
//	_KeysData::_KeysData (Constructor)
// ----------------------------------------------------
				_KeysData::_KeysData(int FstKey)
{
	// ������
	_CheckKeyList.clear();
	// �ǉ�
	_CheckKeyList.insert(FstKey);
	// ���胂�[�h���w��
	IsCheckAllKey = false;
}

// ----------------------------------------------------
//	_KeysData::_KeysData (Constructor)
// ----------------------------------------------------
				_KeysData::_KeysData(int FstKey_1, int FstKey_2)
{
	// ������
	_CheckKeyList.clear();
	// �ǉ�
	_CheckKeyList.insert(FstKey_1);
	_CheckKeyList.insert(FstKey_2);
	// ���胂�[�h���w��
	IsCheckAllKey = false;
}

// ----------------------------------------------------
//	_KeysData::_KeysData (Constructor)
// ----------------------------------------------------
				_KeysData::_KeysData(int Fst_KeysData[], size_t Size)
{
	// ������
	_CheckKeyList.clear();
	// ���[�v����
	for(size_t i = 0; i < Size; i++){
		// �ǉ�
		_CheckKeyList.insert(Fst_KeysData[i]);
	}
	// ���胂�[�h���w��
	IsCheckAllKey = false;
}

// ----------------------------------------------------
//	_KeysData::Compare
// ----------------------------------------------------
bool			_KeysData::Compare(const _KeysData &KeyList) const
{
	// �����T�C�Y���Ⴄ�Ȃ�
	if(_Size() != KeyList._Size()){
		// false
		return false;
	}
	// ���[�v����
	for(size_t i = 0; i < _Size(); i++){
		// ������v���Ȃ��v�f�����݂���Ȃ�
		if(KeyList && _Get(i) == false){
			// false
			return false;
		}
	}
	return true;
}

// ----------------------------------------------------
//	_KeysData::operator+
// ----------------------------------------------------
_KeysData&		_KeysData::operator+(const _KeysData &KeyList) const
{
	// ���g���R�s�[
	_KeysData* New_KeysData = new _KeysData(*this);
	// ������ǉ�
	*New_KeysData += KeyList;
	// �ԋp
	return *New_KeysData;
}

// ----------------------------------------------------
//	_KeysData::operator-
// ----------------------------------------------------
_KeysData&		_KeysData::operator-(const _KeysData &KeyList) const
{
	// ���g���R�s�[
	_KeysData* New_KeysData = new _KeysData(*this);
	// ����������
	*New_KeysData -= KeyList;
	// �ԋp
	return *New_KeysData;
}

// ----------------------------------------------------
//	_KeysData::operator+=
// ----------------------------------------------------
_KeysData&		_KeysData::operator+=(const _KeysData &KeyList)
{
	// �ǉ����Ă���
	for(size_t i = 0; i < KeyList._Size(); i++){
		_CheckKeyList.insert(KeyList._Get(i));
	}
	// ���g��ԋp
	return *this;
}

// ----------------------------------------------------
//	_KeysData::operator-=
// ----------------------------------------------------
_KeysData&		_KeysData::operator-=(const _KeysData &KeyList)
{
	// �폜���Ă���
	for(size_t i = 0; i < KeyList._Size(); i++){
		_CheckKeyList.erase(KeyList._Get(i));
	}
	// ���g��ԋp
	return *this;
}

// ----------------------------------------------------
//	_KeysData::operator&&
// ----------------------------------------------------
bool			_KeysData::operator&&(int Key) const
{
	// �l���܂܂�Ă���Ȃ�true
	return (_CheckKeyList.count(Key) >= 1);
}

// ----------------------------------------------------
//	_KeysData::operator==
// ----------------------------------------------------
bool			_KeysData::operator==(const _KeysData &KeyList) const
{
	return Compare(KeyList);
}

// ----------------------------------------------------
//	_KeysData::_Size
// ----------------------------------------------------
size_t			_KeysData::_Size() const
{
	// �T�C�Y��ԋp
	return _CheckKeyList.size();
}

// ----------------------------------------------------
//	_KeysData::_Get
// ----------------------------------------------------
int				_KeysData::_Get(int Val) const
{
	// �C�e���[�^
	auto Iterator = _CheckKeyList.begin();
	// �����̒l�������߂�
	for(int i = 0; i < Val; i++){
		// 1�ǉ�
		Iterator++;
		// �����I�[�܂Ō����Ȃ�
		if(Iterator == _CheckKeyList.end()){
			// -1��Ԃ�
			return -1;
		}
	}
	// �ԋp
	return *Iterator;
}

// ----------------------------------------------------
//	Key
// ----------------------------------------------------
//	Initialization
// ----------------------------------------------------
const _KeysData		Key::A			(KEY_INPUT_A);
const _KeysData		Key::B			(KEY_INPUT_B);
const _KeysData		Key::C			(KEY_INPUT_C);
const _KeysData		Key::D			(KEY_INPUT_D);
const _KeysData		Key::E			(KEY_INPUT_E);
const _KeysData		Key::F			(KEY_INPUT_F);
const _KeysData		Key::G			(KEY_INPUT_G);
const _KeysData		Key::H			(KEY_INPUT_H);
const _KeysData		Key::I			(KEY_INPUT_I);
const _KeysData		Key::J			(KEY_INPUT_J);
const _KeysData		Key::K			(KEY_INPUT_K);
const _KeysData		Key::L			(KEY_INPUT_L);
const _KeysData		Key::M			(KEY_INPUT_M);
const _KeysData		Key::N			(KEY_INPUT_N);
const _KeysData		Key::O			(KEY_INPUT_O);
const _KeysData		Key::P			(KEY_INPUT_P);
const _KeysData		Key::Q			(KEY_INPUT_Q);
const _KeysData		Key::R			(KEY_INPUT_R);
const _KeysData		Key::S			(KEY_INPUT_S);
const _KeysData		Key::T			(KEY_INPUT_T);
const _KeysData		Key::U			(KEY_INPUT_U);
const _KeysData		Key::V			(KEY_INPUT_V);
const _KeysData		Key::W			(KEY_INPUT_W);
const _KeysData		Key::X			(KEY_INPUT_X);
const _KeysData		Key::Y			(KEY_INPUT_Y);
const _KeysData		Key::Z			(KEY_INPUT_Z);
const _KeysData		Key::F1			(KEY_INPUT_F1);
const _KeysData		Key::F2			(KEY_INPUT_F2);
const _KeysData		Key::F3			(KEY_INPUT_F3);
const _KeysData		Key::F4			(KEY_INPUT_F4);
const _KeysData		Key::F5			(KEY_INPUT_F5);
const _KeysData		Key::F6			(KEY_INPUT_F6);
const _KeysData		Key::F7			(KEY_INPUT_F7);
const _KeysData		Key::F8			(KEY_INPUT_F8);
const _KeysData		Key::F9			(KEY_INPUT_F9);
const _KeysData		Key::F10		(KEY_INPUT_F10);
const _KeysData		Key::F11		(KEY_INPUT_F11);
const _KeysData		Key::F12		(KEY_INPUT_F12);
const _KeysData		Key::N1			(KEY_INPUT_1,			KEY_INPUT_NUMPAD1);
const _KeysData		Key::N2			(KEY_INPUT_2,			KEY_INPUT_NUMPAD2);
const _KeysData		Key::N3			(KEY_INPUT_3,			KEY_INPUT_NUMPAD3);
const _KeysData		Key::N4			(KEY_INPUT_4,			KEY_INPUT_NUMPAD4);
const _KeysData		Key::N5			(KEY_INPUT_5,			KEY_INPUT_NUMPAD5);
const _KeysData		Key::N6			(KEY_INPUT_6,			KEY_INPUT_NUMPAD6);
const _KeysData		Key::N7			(KEY_INPUT_7,			KEY_INPUT_NUMPAD7);
const _KeysData		Key::N8			(KEY_INPUT_8,			KEY_INPUT_NUMPAD8);
const _KeysData		Key::N9			(KEY_INPUT_9,			KEY_INPUT_NUMPAD9);
const _KeysData		Key::N0			(KEY_INPUT_0,			KEY_INPUT_NUMPAD0);
const _KeysData		Key::Enter		(KEY_INPUT_RETURN);
const _KeysData		Key::Delete		(KEY_INPUT_DELETE);
const _KeysData		Key::Escape		(KEY_INPUT_ESCAPE);
const _KeysData		Key::Tab		(KEY_INPUT_TAB);
const _KeysData		Key::Shift		(KEY_INPUT_LSHIFT,		KEY_INPUT_RSHIFT);
const _KeysData		Key::Control	(KEY_INPUT_LCONTROL,	KEY_INPUT_RCONTROL);
const _KeysData		Key::Alt		(KEY_INPUT_LALT,		KEY_INPUT_RALT);
const _KeysData		Key::Space		(KEY_INPUT_SPACE);
const _KeysData		Key::Up			(KEY_INPUT_UP);
const _KeysData		Key::Left		(KEY_INPUT_LEFT);
const _KeysData		Key::Right		(KEY_INPUT_RIGHT);
const _KeysData		Key::Down		(KEY_INPUT_DOWN);

