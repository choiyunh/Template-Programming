#pragma once

#include <iostream>
#include "GeometricObject.h"

class Form_A : public GeometricObject
{
public:
	GeometricObject* geo;

	Form_A(GeometricObject* p) : geo(p) {}

	void draw(const int& i, const int& j, const int& r, const float& red, const float& green, const float& blue)
	{
		//geo->draw(i, j, r, red, green, blue);
		geo->ChangeCircle(i, j, r, geo->window);

		geo->drawLine(i - 20, j, i + 20, j, red, green, blue);
		geo->drawLine(i - 35, j - 25, i, j + sqrt(1200), red, green, blue);
		geo->drawLine(i, j + sqrt(1200), i + 35, j - 25, red, green, blue);

	}
};