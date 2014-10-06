// --------------------------------------------------------
//	IB_Chara.hpp
// --------------------------------------------------------
//	�L�����N�^�̏�ԁE����𑀍삷��N���X�̐���
// --------------------------------------------------------
//
#pragma once

// --------------------------------------------------------
//	���O��Ԃ��g�p(Apocalypse::Input)
// --------------------------------------------------------
namespace IB_Van
{
	namespace Charas
	{
		class Chara
		{
		public:
			/// <summary>
			///		�R���X�g���N�^
			/// </summary>
			Chara();
			///	<summary>
			///		�L�����̐ݒ���s���֐�
			///		name		:�L�����N�^�̖��O���L�q
			///		�߂�l��TRUE �ŃL������������
			///				FALSE�ŃL�����������s
			///	</summary>
			bool SetChara(char *name);
			///	<summary>
			///		�L�������폜����֐�
			///	</summary>
			void DeleteChara();
		private:
			/// <summary>
			///		�e��L�����N�^�̏�Ԃ��L��
			/// </summary>
			//	�`��֌W
			int *handle;		//�L�����̉摜�n���h��
			int UsingMode;		//�L�����̏������[�h(CHARA_2D��2D�L����,CHARA_3D��3D�L�����𑀍�)
			int Subject;		//�L�����̑���
			//	�p�����\�^�֌W
			double x;			//x���W(�`�掞��int�^�ɃL���X�g���Ďg�p)
			double y;			//y���W(�`�掞��int�^�ɃL���X�g���Ďg�p)
			int life;			//�L������HP(0��dead��TRUE)
			int IBP;			//�L������IBP(InfinitBreakPercentage)
								//[�g�p��]IBP=126 -> �\���ł�12.6%���w���悤�ɂ���
			int heavy;			//�L�����̏d��(�d��ID CH_LITE,CH_NORMAL,CH_HEAVY)<-������΂��₷���Ɋ֘A
			int theform;		//��n�`�Ԃ��w��(n��theform�̒l)
			//	�L������Ԋ֌W
			bool player;		//�v���C���[�L�����Ȃ�TRUE(CPU�L�����Ȃ�FALSE)
			bool input;			//���͂������Ă�����TRUE
			bool stand;			//�n�ʂɗ����Ă�����TRUE
			bool attack;		//�U�����Ă�����TRUE
			bool dash;			//�_�b�V�����Ă�����TRUE
			bool exattack;		//�K�E�Z���Ȃ�TRUE
			bool damage;		//�_���[�W���󂯂Ă�����TRUE
			bool dead;			//���S��ԂɊׂ�����TRUE
		};
	}
}
