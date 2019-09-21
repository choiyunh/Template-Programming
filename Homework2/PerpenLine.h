#pragma once

#include <iostream>
#include "GeometricObject.h"

class PerpenLine : public GeometricObject
{
public:
	GeometricObject* geo;

	PerpenLine(GeometricObject* p) : geo(p) {}

	void draw(const int& i, const int& j, const int& r, const float& red, const float& green, const float& blue)
	{

		for (int a = 0; a < 50; a++) {
			geo->drawPixel(i, j + 25 - a, red, green, blue);
		}

	}
};