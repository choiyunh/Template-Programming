#pragma once

#include <iostream>
#include "GeometricObject.h"

class ThickLine : public GeometricObject
{
public:
	GeometricObject* geo;

	ThickLine(GeometricObject* p) : geo(p) {}

	void draw(const int& i, const int& j, const int& r, const float& red, const float& green, const float& blue)
	{
		//geo->draw(i, j, r, red, green, blue);
		geo->ChangeCircle(i, j, r, geo->window);
	
		for (int a = 0; a < 50; a++) {
			geo->drawPixel(i - 25 + a, j - 25 + a, red, green, blue);
			geo->drawPixel(i - 25 + a, j - 24 + a, red, green, blue);
			geo->drawPixel(i - 25 + a, j - 23 + a, red, green, blue);
			geo->drawPixel(i - 25 + a, j - 22 + a, red, green, blue);
		}
	}
};