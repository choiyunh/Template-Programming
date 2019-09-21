#pragma once

#include <iostream>
#include "GeometricObject.h"

class Cross : public GeometricObject
{
public:
	GeometricObject* geo;

	Cross(GeometricObject* p) : geo(p) {}

	void draw(const int& i, const int& j, const int& r, const float& red, const float& green, const float& blue)
	{
		//->draw(i, j, r, red, green, blue);
		geo->ChangeSquare(i, j, r, geo->window);

		for (int a = 0; a < 50; a++) {
			geo->drawPixel(i - 25 + a, j - 25 + a, 1.0f, 0.0f, 0.0f);
			geo->drawPixel(i - 25 + a, j + 25 - a, 1.0f, 0.0f, 0.0f);
		}


	}
};