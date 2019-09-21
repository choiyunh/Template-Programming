#pragma once


#include <iostream>
#include "GeometricObject.h"

class TopArrow : public GeometricObject
{
public:
	GeometricObject* geo;

	TopArrow(GeometricObject* p) : geo(p) {}

	
	void draw(const int& i, const int& j, const int& r, const float& red, const float& green, const float& blue)
	{
		geo->draw(i, j, r, red, green, blue);
		
		for (int a = 0; a < 50; a++) {
			geo->drawPixel(i, j + 25 - a, red, green, blue);
		}
		for (int a = 0; a < 25; a++) {
			geo->drawPixel(i - 25 + a, j + a, red, green, blue);
			geo->drawPixel(i + 25 - a, j + a, red, green, blue);
		}

	}
};