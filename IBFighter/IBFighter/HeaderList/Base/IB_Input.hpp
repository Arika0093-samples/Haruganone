// --------------------------------------------------------
//	IB_Input.hpp
// --------------------------------------------------------
//	���͂��Ǘ�����N���X���쐬����D
// --------------------------------------------------------
//	��x�����ǂݍ���
#pragma once

// --------------------------------------------------------
//	�K�v�ȃw�b�_�[��ǂݍ���
// --------------------------------------------------------
#include <set>
#include "IB_BaseTemplate.hpp"
#include "IB_Value.hpp"

// --------------------------------------------------------
//	���O��Ԃ��g�p(Apocalypse::Input)
// --------------------------------------------------------
namespace IB_Base
{
	// ----------------------------------------------------
	//	Input���O��ԓ��̃N���X���L��
	// ----------------------------------------------------
	namespace Input
	{
		// ------------------------------------------------
		//	Front Declaration
		// ------------------------------------------------
		class _KeysData;

		///	<summary>
		///		�L�[�����Ǘ�����p�̃N���X�D
		///	</summary>
		/// <remarks>
		///		Key::XX�̌`�ŃL�[�����擾�ł��܂��D���̃N���X��singleton�ł��D
		/// </remarks>
		/// <example>
		///		�g�p��: 
		///		<code>
		///		// ����Z�L�[��������Ă����
		///		if(Key::Pushing(KeyList::Z)){
		///			�c
		///		}
		///		// ����X�L�[�������ꂽ�u�ԂȂ��
		///		if(Key::OutStart(KeyList::X)){
		///			�c
		///		}
		///		</code>
		/// </example>
		class KeyBoard : public Template::_Singleton<KeyBoard>
		{
			/// <summary>
			///		Singleton�N���X�͑S�Ẵ����o�ɃA�N�Z�X�\�ł��D
			/// </summary>
			friend class		Template::_Singleton<KeyBoard>;
		public:
			/// <summary>
			///		�����̃L�[/�}�E�X��������Ă��邩�ǂ����̏����擾����D
			/// </summary>
			static bool			AnyPushing();
			/// <summary>
			///		<para>�w�肵���L�[��������Ă��邩�ǂ����̏����擾����D</para>
			///		<para>0�Ȃ牟����Ă��Ȃ��D1�ȏ�Ȃ牟����Ă��鎞�ԁD</para>
			/// </summary>
			/// <param name = "TargetKey">
			///		�擾����Ώۂ̃L�[�DKeyList�Œ�`���ꂽ�l���g�p���ĉ������D
			/// </param>
			static unsigned int Pushing(const _KeysData &TargetKey);
			/// <summary>
			///		�w�肵���L�[�����̃t���[���ŏ��߂ĉ����ꂽ���ǂ����̏����擾����D
			/// </summary>
			/// <param name = "TargetKey">
			///		�擾����Ώۂ̃L�[�DKeyList�Œ�`���ꂽ�l���g�p���ĉ������D
			/// </param>
			static bool			PushStart(const _KeysData &TargetKey);
			/// <summary>
			///		�w�肵���L�[�����̃t���[���ŏ��߂ė����ꂽ���ǂ����̏����擾����D
			/// </summary>
			/// <param name = "TargetKey">
			///		�擾����Ώۂ̃L�[�DKeyList�Œ�`���ꂽ�l���g�p���ĉ������D
			/// </param>
			static bool			OutStart(const _KeysData &TargetKey);
			/// <summary>
			///		�L�[�̏�Ԃ��X�V����D1�t���[����1�x�Ăяo���D
			/// </summary>
			void				_CheckKeyEvent();
		private:
			/// <summary>
			///		Constructor
			/// </summary>
								KeyBoard();
			/// <summary>
			///		�L�[�̓��͏���ۑ�����ϐ��D
			/// </summary>
			int					_KeyInput[256];
		};

		///	<summary>
		///		�}�E�X�����Ǘ�����p�̃N���X�D
		///	</summary>
		/// <remarks>
		///		Mouse::XX�̌`�ŃL�[�����擾�ł��܂��D���̃N���X��singleton�ł��D
		/// </remarks>
		/// <example>
		///		�g�p��: 
		///		<code>
		///		// �����}�E�X��������Ă����
		///		if(Mouse::Pushing()){
		///			�c
		///		}
		///		// �����}�E�X�������ꂽ�u�ԂȂ��
		///		if(Mouse::OutStart()){
		///			�c
		///		}
		///		</code>
		/// </example>
		class Mouse : public Template::_Singleton<Mouse>
		{
			/// <summary>
			///		Singleton�N���X�͑S�Ẵ����o�ɃA�N�Z�X�\�ł��D
			/// </summary>
			friend class		Template::_Singleton<Mouse>;
		public:
			/// <summary>
			///		<para>�}�E�X��������Ă��邩�ǂ����̏����擾����D</para>
			///		<para>0�Ȃ牟����Ă��Ȃ��D1�ȏ�Ȃ牟����Ă��鎞�ԁD</para>
			/// </summary>
			static int			LeftPushing();
			/// <summary>
			///		�}�E�X�����̃t���[���ŏ��߂ĉ����ꂽ���ǂ����̏����擾����D
			/// </summary>
			static bool			LeftPushStart();
			/// <summary>
			///		�}�E�X�����̃t���[���Ŏn�߂ė����ꂽ���ǂ����̏����擾����D
			/// </summary>
			static bool			LeftOutStart();
			/// <summary>
			///		<para>�}�E�X��������Ă��邩�ǂ����̏����擾����D</para>
			///		<para>0�Ȃ牟����Ă��Ȃ��D1�ȏ�Ȃ牟����Ă��鎞�ԁD</para>
			/// </summary>
			static int			RightPushing();
			/// <summary>
			///		�}�E�X�����̃t���[���ŏ��߂ĉ����ꂽ���ǂ����̏����擾����D
			/// </summary>
			static bool			RightPushStart();
			/// <summary>
			///		�}�E�X�����̃t���[���Ŏn�߂ė����ꂽ���ǂ����̏����擾����D
			/// </summary>
			static bool			RightOutStart();
			/// <summary>
			///		�}�E�X�̈ʒu���擾����D
			/// </summary>
			static bool			IsMove();
			/// <summary>
			///		�}�E�X�̈ʒu���擾����D
			/// </summary>
			static Value::Point	GetPosition();
			/// <summary>
			///		�}�E�X�̈ʒu��ݒ肷��D
			/// </summary>
			/// <param name = "X">
			///		�w�肷��X���W�D
			/// </param>
			/// <param name = "Y">
			///		�w�肷��Y���W�D
			/// </param>
			static void			SetPosition(int X, int Y);
			/// <summary>
			///		�}�E�X�̏�Ԃ��X�V����D1�t���[����1�x�Ăяo���D
			/// </summary>
			void				_CheckMouseEvent();
		private:
			/// <summary>
			///		�R���X�g���N�^
			/// </summary>
								Mouse();
			/// <summary>
			///		<para>(��)�}�E�X���͂̎��Ԃ��擾���܂��D</para>
			///		<para>���̒l: ������Ă��鎞�� / ���̒l: ������Ă��鎞��</para>
			/// </summary>
			int					_MousePushTimeLeft;
			/// <summary>
			///		<para>(�E)�}�E�X���͂̎��Ԃ��擾���܂��D</para>
			///		<para>���̒l: ������Ă��鎞�� / ���̒l: ������Ă��鎞��</para>
			/// </summary>
			int					_MousePushTimeRight;
			/// <summary>
			///		�}�E�X�̈ʒu���擾����
			/// </summary>
			Value::Point		_MouseLocation;
			/// <summary>
			///		1�t���[���O�̃}�E�X�̈ʒu���擾����
			/// </summary>
			Value::Point		_MouseBeforeLoc;
		};

		///	<summary>
		///		�L�[�����Ǘ�����N���X�D
		///	</summary>
		/// <remarks>
		///		�L�[�̏�Ԃ��擾����֐��̈����Ɏg�p���܂��D
		/// </remarks>
		class _KeysData
		{
		public:
			///	<summary>
			///		�����L�[�Ƃ��ē��ɉ��������Ȃ�_KeysData�N���X�̃R���X�g���N�^�D
			///	</summary>
								_KeysData();
			///	<summary>
			///		�����L�[�Ƃ��Ĉ����Ɏw�肳�ꂽ�L�[������_KeysData�N���X�̃R���X�g���N�^�D
			///	</summary>
			///	<param name = "FstKey">
			///		�����L�[�D
			///	</param>
								_KeysData(int FstKey);
			///	<summary>
			///		�����L�[�Ƃ��Ĉ����Ɏw�肳�ꂽ2�̃L�[������_KeysData�N���X�̃R���X�g���N�^�D
			///	</summary>
			///	<param name = "FstKey_1">
			///		�����L�[����1�D
			///	</param>
			///	<param name = "FstKey_2">
			///		�����L�[����2�D
			///	</param>
								_KeysData(int FstKey_1, int FstKey_2);
			///	<summary>
			///		�����L�[�Ƃ��Ĉ����Ɏw�肳�ꂽ�����̃L�[������_KeysData�N���X�̃R���X�g���N�^�D
			///	</summary>
			///	<param name = "Fst_KeysData">
			///		�����̏����L�[�D
			///	</param>
			///	<param name = "Size">
			///		�o�^����L�[�̌��D
			///	</param>
								_KeysData(int FstKey[], size_t Size);
			///	<summary>
			///		�f�X�g���N�^�D
			///	</summary>
								~_KeysData(){}
			///	<summary>
			///		2�̃L�[�̏�Ԃ��r����֐��D
			///	</summary>
			///	<param name = "_KeysDataList">
			///		��r����L�[�̏�ԃN���X�D
			///	</param>
			bool				Compare(const _KeysData &_KeysDataList) const;
			///	<summary>
			///		�L�[�ǉ���operator�D
			///	</summary>
			///	<param name = "_KeysDataList">
			///		�ǉ�����L�[�̏�ԃN���X�D
			///	</param>
			_KeysData&			operator+(const _KeysData &_KeysDataList) const;
			///	<summary>
			///		�L�[�폜��operator�D
			///	</summary>
			///	<param name = "_KeysDataList">
			///		�폜����L�[�̏�ԃN���X�D
			///	</param>
			_KeysData&			operator-(const _KeysData &_KeysDataList) const;
			///	<summary>
			///		�L�[�ǉ���operator�D
			///	</summary>
			///	<param name = "_KeysDataList">
			///		�ǉ�����L�[�̏�ԃN���X�D
			///	</param>
			_KeysData&			operator+=(const _KeysData &_KeysDataList);
			///	<summary>
			///		�L�[�폜��operator�D
			///	</summary>
			///	<param name = "_KeysDataList">
			///		�폜����L�[�̏�ԃN���X�D
			///	</param>
			_KeysData&			operator-=(const _KeysData &_KeysDataList);
			///	<summary>
			///		��r��operator�D
			///	</summary>
			///	<param name = "Key">
			///		��r����L�[�̃R�[�h�D
			///	</param>
			bool				operator&&(int Key) const;
			///	<summary>
			///		��r��operator�D
			///	</summary>
			///	<param name = "_KeysDataList">
			///		��r����L�[�̏�ԃN���X�D
			///	</param>
			bool				operator==(const _KeysData &_KeysDataList) const;
			///	<summary>
			///		<para>����֐��őS�Ă�������Ă�ꍇ�𔻒肷�邩�ǂ����D</para>
			///		<para>�W���ł�false�i�ǂꂩ���������Ă���ꍇ�𔻒肷��j�D</para>
			///	</summary>
			bool				IsCheckAllKey;
			///	<summary>
			///		�o�^�L�[�T�C�Y���擾����D
			///	</summary>
			size_t				_Size() const;
			///	<summary>
			///		�o�^�L�[�̔ԍ����擾����D
			///	</summary>
			int					_Get(int Val) const;
		private:
			///	<summary>
			///		�m�F����L�[�̎�ށD
			///	</summary>
			std::set<int>		_CheckKeyList;
		};

		///	<summary>
		///		�L�[�{�[�h�̑Ή�������񋓂����N���X�D
		///	</summary>
		class Key
		{
		public:
			///	<summary>
			///		�L�[�{�[�h��A�L�[�D
			///	</summary>
			static const _KeysData	A;
			///	<summary>
			///		�L�[�{�[�h��B�L�[�D
			///	</summary>
			static const _KeysData	B;
			///	<summary>
			///		�L�[�{�[�h��C�L�[�D
			///	</summary>
			static const _KeysData	C;
			///	<summary>
			///		�L�[�{�[�h��D�L�[�D
			///	</summary>
			static const _KeysData	D;
			///	<summary>
			///		�L�[�{�[�h��E�L�[�D
			///	</summary>
			static const _KeysData	E;
			///	<summary>
			///		�L�[�{�[�h��F�L�[�D
			///	</summary>
			static const _KeysData	F;
			///	<summary>
			///		�L�[�{�[�h��G�L�[�D
			///	</summary>
			static const _KeysData	G;
			///	<summary>
			///		�L�[�{�[�h��H�L�[�D
			///	</summary>
			static const _KeysData	H;
			///	<summary>
			///		�L�[�{�[�h��I�L�[�D
			///	</summary>
			static const _KeysData	I;
			///	<summary>
			///		�L�[�{�[�h��J�L�[�D
			///	</summary>
			static const _KeysData	J;
			///	<summary>
			///		�L�[�{�[�h��K�L�[�D
			///	</summary>
			static const _KeysData	K;
			///	<summary>
			///		�L�[�{�[�h��L�L�[�D
			///	</summary>
			static const _KeysData	L;
			///	<summary>
			///		�L�[�{�[�h��M�L�[�D
			///	</summary>
			static const _KeysData	M;
			///	<summary>
			///		�L�[�{�[�h��N�L�[�D
			///	</summary>
			static const _KeysData	N;
			///	<summary>
			///		�L�[�{�[�h��O�L�[�D
			///	</summary>
			static const _KeysData	O;
			///	<summary>
			///		�L�[�{�[�h��P�L�[�D
			///	</summary>
			static const _KeysData	P;
			///	<summary>
			///		�L�[�{�[�h��Q�L�[�D
			///	</summary>
			static const _KeysData	Q;
			///	<summary>
			///		�L�[�{�[�h��R�L�[�D
			///	</summary>
			static const _KeysData	R;
			///	<summary>
			///		�L�[�{�[�h��S�L�[�D
			///	</summary>
			static const _KeysData	S;
			///	<summary>
			///		�L�[�{�[�h��T�L�[�D
			///	</summary>
			static const _KeysData	T;
			///	<summary>
			///		�L�[�{�[�h��U�L�[�D
			///	</summary>
			static const _KeysData	U;
			///	<summary>
			///		�L�[�{�[�h��V�L�[�D
			///	</summary>
			static const _KeysData	V;
			///	<summary>
			///		�L�[�{�[�h��W�L�[�D
			///	</summary>
			static const _KeysData	W;
			///	<summary>
			///		�L�[�{�[�h��X�L�[�D
			///	</summary>
			static const _KeysData	X;
			///	<summary>
			///		�L�[�{�[�h��Y�L�[�D
			///	</summary>
			static const _KeysData	Y;
			///	<summary>
			///		�L�[�{�[�h��Z�L�[�D
			///	</summary>
			static const _KeysData	Z;
			///	<summary>
			///		�L�[�{�[�h��1�L�[�D
			///	</summary>
			static const _KeysData	N1;
			///	<summary>
			///		�L�[�{�[�h��2�L�[�D
			///	</summary>
			static const _KeysData	N2;
			///	<summary>
			///		�L�[�{�[�h��3�L�[�D
			///	</summary>
			static const _KeysData	N3;
			///	<summary>
			///		�L�[�{�[�h��4�L�[�D
			///	</summary>
			static const _KeysData	N4;
			///	<summary>
			///		�L�[�{�[�h��5�L�[�D
			///	</summary>
			static const _KeysData	N5;
			///	<summary>
			///		�L�[�{�[�h��6�L�[�D
			///	</summary>
			static const _KeysData	N6;
			///	<summary>
			///		�L�[�{�[�h��7�L�[�D
			///	</summary>
			static const _KeysData	N7;
			///	<summary>
			///		�L�[�{�[�h��8�L�[�D
			///	</summary>
			static const _KeysData	N8;
			///	<summary>
			///		�L�[�{�[�h��9�L�[�D
			///	</summary>
			static const _KeysData	N9;
			///	<summary>
			///		�L�[�{�[�h��0�L�[�D
			///	</summary>
			static const _KeysData	N0;
			///	<summary>
			///		�L�[�{�[�h��F1�L�[�D
			///	</summary>
			static const _KeysData	F1;
			///	<summary>
			///		�L�[�{�[�h��F2�L�[�D
			///	</summary>
			static const _KeysData	F2;
			///	<summary>
			///		�L�[�{�[�h��F3�L�[�D
			///	</summary>
			static const _KeysData	F3;
			///	<summary>
			///		�L�[�{�[�h��F4�L�[�D
			///	</summary>
			static const _KeysData	F4;
			///	<summary>
			///		�L�[�{�[�h��F5�L�[�D
			///	</summary>
			static const _KeysData	F5;
			///	<summary>
			///		�L�[�{�[�h��F6�L�[�D
			///	</summary>
			static const _KeysData	F6;
			///	<summary>
			///		�L�[�{�[�h��F7�L�[�D
			///	</summary>
			static const _KeysData	F7;
			///	<summary>
			///		�L�[�{�[�h��F8�L�[�D
			///	</summary>
			static const _KeysData	F8;
			///	<summary>
			///		�L�[�{�[�h��F9�L�[�D
			///	</summary>
			static const _KeysData	F9;
			///	<summary>
			///		�L�[�{�[�h��F10�L�[�D
			///	</summary>
			static const _KeysData	F10;
			///	<summary>
			///		�L�[�{�[�h��F11�L�[�D
			///	</summary>
			static const _KeysData	F11;
			///	<summary>
			///		�L�[�{�[�h��F12�L�[�D
			///	</summary>
			static const _KeysData	F12;
			///	<summary>
			///		�L�[�{�[�h��Enter�L�[�D
			///	</summary>
			static const _KeysData	Enter;
			///	<summary>
			///		�L�[�{�[�h��Esc�L�[�D
			///	</summary>
			static const _KeysData	Escape;
			///	<summary>
			///		�L�[�{�[�h��Tab�L�[�D
			///	</summary>
			static const _KeysData	Tab;
			///	<summary>
			///		�L�[�{�[�h�̗�Shift�L�[�D
			///	</summary>
			static const _KeysData	Shift;
			///	<summary>
			///		�L�[�{�[�h�̗�Ctrl�L�[�D
			///	</summary>
			static const _KeysData	Control;
			///	<summary>
			///		�L�[�{�[�h�̗�Alt�L�[�D
			///	</summary>
			static const _KeysData	Alt;
			///	<summary>
			///		�L�[�{�[�h��Space�L�[�D
			///	</summary>
			static const _KeysData	Space;
			///	<summary>
			///		�L�[�{�[�h��BackSpace�L�[�D
			///	</summary>
			static const _KeysData	BackSpace;
			///	<summary>
			///		�L�[�{�[�h��Delete�L�[�D
			///	</summary>
			static const _KeysData	Delete;
			///	<summary>
			///		�L�[�{�[�h�̏�L�[�D
			///	</summary>
			static const _KeysData	Up;
			///	<summary>
			///		�L�[�{�[�h�̍��L�[�D
			///	</summary>
			static const _KeysData	Left;
			///	<summary>
			///		�L�[�{�[�h�̉E�L�[�D
			///	</summary>
			static const _KeysData	Right;
			///	<summary>
			///		�L�[�{�[�h�̉��L�[�D
			///	</summary>
			static const _KeysData	Down;
		};
	}
}
