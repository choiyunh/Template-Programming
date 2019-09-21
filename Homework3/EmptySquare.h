#pragma once

#include <iostream>
#include "GeometricObject.h"

class EmptySquare : public GeometricObject
{
public:
	GeometricObject* geo;

	EmptySquare(GeometricObject* p) : geo(p) {}

	void draw(const int& i, const int& j, const int& r, const float& red, const float& green, const float& blue)
	{
		//geo->draw(i, j, r, red, green, blue);
		geo->ChangeCircle(i, j, r, geo->window);

		geo->drawLine(i - 25, j - 25, i + 25, j - 25, red, green, blue);
		geo->drawLine(i - 25, j - 25, i - 25, j + 25, red, green, blue);
		geo->drawLine(i - 25, j + 25, i + 25, j + 25, red, green, blue);
		geo->drawLine(i + 25, j - 25, i + 25, j + 25, red, green, blue);
	}
};