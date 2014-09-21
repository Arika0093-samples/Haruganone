// --------------------------------------------------------
//	apcValue.hpp
// --------------------------------------------------------
//	数式関連のクラスを記載する．
// --------------------------------------------------------
//	一度だけ読み込む
#pragma once

// --------------------------------------------------------
//	名前空間を使用(IB_Base::Value)
// --------------------------------------------------------
namespace IB_Base
{
	namespace Value
	{
		///	<summary>
		///		doubleで座標を管理するPOINT構造体．
		///	</summary>
		class Point
		{
		public:
			///	<summary>
			///		コンストラクタ．
			///	</summary>
									Point();
			///	<summary>
			///		コンストラクタ．
			///	</summary>
									Point(double X, double Y);
			///	<summary>
			///		位置のX座標．
			///	</summary>
			double					X;
			///	<summary>
			///		位置のY座標．
			///	</summary>
			double					Y;
			///	<summary>
			///		代入する．
			///	</summary>
			void					operator()(double X, double Y);
			///	<summary>
			///		コピーする．
			///	</summary>
			Point&					operator=(const Point& Pt);
			///	<summary>
			///		コピーする．
			///	</summary>
			Point&					operator=(double Val);
			///	<summary>
			///		比較する．
			///	</summary>
			bool					operator==(const Point& Pt) const;
			///	<summary>
			///		比較する．
			///	</summary>
			bool					operator!=(const Point& Pt) const;
		};

		///	<summary>
		///		開始位置と縦横幅で四角形を管理する構造体．
		///	</summary>
		class RectangleArea
		{
		public:
			/// <summary>
			///		コンストラクタ．
			/// </summary>
									RectangleArea();
			/// <summary>
			///		コンストラクタ．
			/// </summary>
									RectangleArea(Value::Point &Pt, int Width, int Height);
			/// <summary>
			///		四角形の開始地点．
			/// </summary>
			Point					Location;
			/// <summary>
			///		四角形の横幅
			/// </summary>
			double					Width;
			/// <summary>
			///		四角形の縦幅
			/// </summary>
			double					Height;
		};
	}
}