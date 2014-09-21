// --------------------------------------------------------
//	apcValue.cpp
// --------------------------------------------------------
//	apcValue.hpp ‚Ìƒƒ“ƒoŠÖ”‚ÌŽÀ‘Ì‚ð’u‚­
// --------------------------------------------------------
#include "IB_BaseInclude.hpp"

// ----------------------------------------------------
//	Point
// ----------------------------------------------------
//	Point::Point (constructor)
// ----------------------------------------------------
				Point::Point()
{
	X = 0;
	Y = 0;
}

// ----------------------------------------------------
//	Point::Point (constructor)
// ----------------------------------------------------
				Point::Point(double X, double Y)
{
	this->X = X;
	this->Y = Y;
}

// ----------------------------------------------------
//	Point::operator ()
// ----------------------------------------------------
void			Point::operator()(double X, double Y)
{
	this->X = X;
	this->Y = Y;
}

// ----------------------------------------------------
//	Point::operator =
// ----------------------------------------------------
Point&			Point::operator=(const Point& Pt)
{
	X = Pt.X;
	Y = Pt.Y;
	return *this;
}

// ----------------------------------------------------
//	Point::operator =
// ----------------------------------------------------
Point&			Point::operator=(double Val)
{
	X = Val;
	Y = Val;
	return *this;
}

// ----------------------------------------------------
//	Point::operator ==
// ----------------------------------------------------
bool			Point::operator==(const Point& Pt) const
{
	return ((this->X == Pt.X) && (this->Y == Pt.Y));
}

// ----------------------------------------------------
//	Point::operator ==
// ----------------------------------------------------
bool			Point::operator!=(const Point& Pt) const 
{
	return ((this->X != Pt.X) || (this->Y != Pt.Y));
}

// ----------------------------------------------------
//	RectangleArea
// ----------------------------------------------------
//	RectangleArea::RectangleArea (constructor)
// ----------------------------------------------------
				RectangleArea::RectangleArea()
{
	// ‘ã“ü
	Location(0, 0);
	Width = 0;
	Height = 0;
}

// ----------------------------------------------------
//	RectangleArea::RectangleArea (constructor)
// ----------------------------------------------------
				RectangleArea::RectangleArea(Point &Pt, int Wid, int Hgt)
{
	// ‘ã“ü
	Location = Pt;
	Width = Wid;
	Height = Hgt;
}