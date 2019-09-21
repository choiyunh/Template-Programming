#pragma once

#include <iostream>
#include "GeometricObject.h"

class LeftArrow : public GeometricObject
{
public:
	GeometricObject* geo;

	LeftArrow(GeometricObject* p) : geo(p) {}

	void draw(const int& i, const int& j, const int& r, const float& red, const float& green, const float& blue)
	{
		geo->drawLine(i - 25, j, i + 25, j, red, green, blue);
		geo->drawLine(i - 25, j, i, j + 25, red, green, blue);
		geo->drawLine(i - 25, j, i, j - 25, red, green, blue);

	}
};