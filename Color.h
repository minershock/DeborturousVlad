#pragma once
#include "Vector.h"

class Color
{
public:
	Color()
	{
		r = g = b = a = 0.0f;
	}

	Color(float _r, float _g, float _b, float _a)
	{
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}

	Color(float _r, float _g, float _b)
	{
		r = _r;
		g = _g;
		b = _b;
		a = 255.f;
	}

	inline Vec4 Get()
	{
		return Vec4(r, g, b, a);
	}

	inline static Color White() { return Color(255.f, 255.f, 255.f); }
	inline static Color Black() { return Color(0.f, 0.f, 0.f); }
	inline static Color Red() { return Color(255.f, 0.f, 0.f); }
	inline static Color Green() { return Color(0.f, 255.f, 0.f); }
	inline static Color Blue() { return Color(0.f, 0.f, 255.f); }
	inline static Color LightBlue() { return Color(0.f, 115.f, 200.f); }
	inline static Color LightBlue2() { return Color(66.f, 173.f, 255.f); }
	inline static Color	LightGrey2() { return Color(150.f, 150.f, 150.f); }
	inline static Color Grey() { return Color(70.f, 70.f, 70.f); }
	inline static Color LightGrey() { return Color(170.f, 170.f, 170.f); }
	inline static Color DarkGrey() { return Color(45.f, 45.f, 45.f); }
	inline static Color Yellow() { return Color(255.f, 255.f, 0.f); }
	inline static Color Magenta() { return Color(255.f, 0.f, 255.f); }
	inline static Color DarkMagenta() { return Color(139.f, 0.f, 139.f); }
	inline static Color Purple() { return Color(128.f, 0.f, 128.f); }
	inline static Color DarkGreen() { return Color(0.f, 128.f, 0.f); }
	inline static Color DarkGreen2() { return Color(0.f, 100.f, 0.f); }
	inline static Color Crimson() { return Color(220.f, 20.f, 60.f); } // cuz people blush
	inline static Color LightRed() { return Color(255.f, 75.f, 75.f); }
	inline static Color LightGreen() { return Color(75.f, 255.f, 75.f); }

private:
	float a, r, g, b;
};