// --------------------------------------------------------
//	apcValue.hpp
// --------------------------------------------------------
//	�����֘A�̃N���X���L�ڂ���D
// --------------------------------------------------------
//	��x�����ǂݍ���
#pragma once

// --------------------------------------------------------
//	���O��Ԃ��g�p(IB_Base::Value)
// --------------------------------------------------------
namespace IB_Base
{
	namespace Value
	{
		///	<summary>
		///		double�ō��W���Ǘ�����POINT�\���́D
		///	</summary>
		class Point
		{
		public:
			///	<summary>
			///		�R���X�g���N�^�D
			///	</summary>
									Point();
			///	<summary>
			///		�R���X�g���N�^�D
			///	</summary>
									Point(double X, double Y);
			///	<summary>
			///		�ʒu��X���W�D
			///	</summary>
			double					X;
			///	<summary>
			///		�ʒu��Y���W�D
			///	</summary>
			double					Y;
			///	<summary>
			///		�������D
			///	</summary>
			void					operator()(double X, double Y);
			///	<summary>
			///		�R�s�[����D
			///	</summary>
			Point&					operator=(const Point& Pt);
			///	<summary>
			///		�R�s�[����D
			///	</summary>
			Point&					operator=(double Val);
			///	<summary>
			///		��r����D
			///	</summary>
			bool					operator==(const Point& Pt) const;
			///	<summary>
			///		��r����D
			///	</summary>
			bool					operator!=(const Point& Pt) const;
		};

		///	<summary>
		///		�J�n�ʒu�Əc�����Ŏl�p�`���Ǘ�����\���́D
		///	</summary>
		class RectangleArea
		{
		public:
			/// <summary>
			///		�R���X�g���N�^�D
			/// </summary>
									RectangleArea();
			/// <summary>
			///		�R���X�g���N�^�D
			/// </summary>
									RectangleArea(Value::Point &Pt, int Width, int Height);
			/// <summary>
			///		�l�p�`�̊J�n�n�_�D
			/// </summary>
			Point					Location;
			/// <summary>
			///		�l�p�`�̉���
			/// </summary>
			double					Width;
			/// <summary>
			///		�l�p�`�̏c��
			/// </summary>
			double					Height;
		};
	}
}