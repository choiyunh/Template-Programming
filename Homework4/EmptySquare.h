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
		geo->ChangeSquare(i, j, r, geo->window);

		drawSquare(i, j, r - 25, red, green, blue);
	}

	void drawSquare(const int& i, const int& j, const int& r, const float& red, const float& green, const float& blue)
	{
		geo->drawLine(i - r, j - r, i + r, j - r, red, green, blue);
		geo->drawLine(i - r, j - r, i - r, j + r, red, green, blue);
		geo->drawLine(i - r, j + r, i + r, j + r, red, green, blue);
		geo->drawLine(i + r, j - r, i + r, j + r, red, green, blue);
	}
};