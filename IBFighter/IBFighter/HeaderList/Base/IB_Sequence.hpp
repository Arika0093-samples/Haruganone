// --------------------------------------------------------
//	IB_Sequence.hpp
// --------------------------------------------------------
//	�V�X�e���֘A�̃N���X���L�ڂ���D
// --------------------------------------------------------
//	��x�����ǂݍ���
#pragma once

// --------------------------------------------------------
//	�K�v�ȃw�b�_�[��ǂݍ���
// --------------------------------------------------------
#include <map>
#include <functional>

// --------------------------------------------------------
//	���O��Ԃ��g�p(IB_Base::Sequence)
// --------------------------------------------------------
namespace IB_Base
{
	namespace Sequence
	{
		/// <summary>
		///		�V���v���ȃV�[�P���X�Ǘ��N���X
		/// </summary>
		/// <remarks>
		///		Status�l�ƑΉ������֐���o�^���邱�ƂŎ����U�蕪�����s���܂��B
		/// </remarks>
		class Sequencer
		{
		public:
			/// <summary>
			///		�R���X�g���N�^
			/// </summary>
			Sequencer();
			/// <summary>
			///		�R���X�g���N�^(������Status��������)
			/// </summary>
			Sequencer(unsigned int Stat);
			/// <summary>
			///		���݂̃V�[�P���X�󋵂ɓK�����֐������s����֐�
			/// </summary>
			/// <return>
			///		�߂�l: �֐����ŃV�[�P���X���ύX���ꂽ�ꍇ���̔ԍ���Ԃ��܂��B
			///		�V�[�P���X���ύX����Ȃ������ꍇ��0�ł��B
			/// </return>
			unsigned int Process();
			/// <summary>
			///		�V�[�P���X�ɑΉ�����֐���o�^����
			/// </summary>
			/// <remarks>
			///		�����V�[�P���X�ɕʂ̊֐����w�肵���ꍇ�㏑������܂��B
			///		�o�^�֐����폜�������ꍇ��empty�֐��𓯂��V�[�P���X�Ɋ��蓖�Ă邱�Ƃō폜����܂��B
			/// </remarks>
			/// <param name = "Stat">
			///		���蓖�Ă�Ώۂ̃V�[�P���X�ԍ�
			/// </param>
			/// <param name = "Func">
			///		�V�[�P���X�Ɋ��蓖�Ă�֐��i������Sequencer�̎Q�ƁA�߂�l��void�̊֐��ł��j
			/// </param>
			void RegistFunction(unsigned int Stat, std::function<void(Sequencer&)> Fc);
			/// <summary>
			///		�V�[�P���X��Ԏ擾
			/// </summary>
			unsigned int GetStatus() const;
			/// <summary>
			///		�V�[�P���X��Ԑݒ�
			/// </summary>
			void SetStatus(unsigned int Stat);
		private:
			/// <summary>
			///		�o�^�֐��Ǘ�
			/// </summary>
			std::map<unsigned int, std::function<void(Sequencer&)>> _FuncList;
			/// <summary>
			///		���݂̃V�[�P���X���
			/// </summary>
			unsigned int _Status;
			/// <summary>
			///		�V�[�P���X���ύX���ꂽ�ۂɎg�p
			/// </summary>
			unsigned int _SeqChanged;
		};
	}
}