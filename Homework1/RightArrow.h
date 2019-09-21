#pragma once

#include <iostream>
#include "GeometricObject.h"

class RightArrow : public GeometricObject
{
public:
	GeometricObject* geo;

	RightArrow(GeometricObject* p) : geo(p) {}

	void draw(const int& i, const int& j, const int& r, const float& red, const float& green, const float& blue)
	{
		geo->draw(i, j, r, red, green, blue);

		geo->drawLine(i - 25, j, i + 25, j, red, green, blue);
		for (int a = 0; a < 25; a++) {
			geo->drawPixel(i + a, j + 25 - a, red, green, blue);
			geo->drawPixel(i + a, j - 25 + a, red, green, blue);
		}

	}
};