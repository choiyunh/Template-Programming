#pragma once

#include <iostream>
#include "GeometricObject.h"

class Circle : public GeometricObject
{
public:
	GeometricObject* geo;

	Circle() {}
	Circle(GeometricObject* p) : geo(p) {}

	void draw(const int& i, const int& j, const int& r, const float& red, const float& green, const float& blue)
	{		
		drawCircle(i, j, r - 25, red, green, blue);
	}

	void drawCircle(const int &i0, const int & j0, const int &r, const float& red, const float& green, const float& blue)
	{
		for (int i = i0 - r; i <= i0 + r; i++)
		{
			for (int j = j0 - r; j <= j0 + r; j++)
			{
				int n = ((i - i0)*(i - i0) + (j - j0)*(j - j0) - r*r);

				int m = ((i - i0)*(i - i0) + (j - j0)*(j - j0) - (r - 2)*(r - 2));

				if (n < 0 && m>0)

				{
					geo->drawPixel(i, j, red, green, blue);
				}
			}
		}
	}

};
