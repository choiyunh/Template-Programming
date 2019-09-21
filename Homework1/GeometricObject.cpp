#include <iostream>

#include <GLFW/glfw3.h>

#include "GeometricObject.h"
#include "ThickLine.h"
#include "EmptySquare.h"
#include "Circle.h"
#include "Cross.h"
#include "UnderArrow.h"
#include "RightArrow.h"
#include "Form_A.h"
#include "PerpenLine.h"
#include "LeftArrow.h"
#include "TopArrow.h"


GeometricObject::GeometricObject() {}

GeometricObject::GeometricObject(const int &w, const int &h) : width(w), height(h)
{
	pixels = new float[width * height * 3];
}

GeometricObject::~GeometricObject()
{
	delete[] pixels;
}

GeometricObject * GeometricObject::instance = NULL;
GeometricObject * GeometricObject::getInstance()
{
	if (!instance)
		instance = new GeometricObject();

	return instance;
}

void GeometricObject::background(const float& red, const float& green, const float& blue)
{
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
			drawPixel(i, j, red, green, blue);
	}
}

// Draw pixel
void GeometricObject::drawPixel(const int &x, const int &y, const float &red, const float &green, const float &blue)
{
	pixels[(x + width*y) * 3 + 0] = red;
	pixels[(x + width*y) * 3 + 1] = green;
	pixels[(x + width*y) * 3 + 2] = blue;
}

// Draw line
void GeometricObject::drawLine(const int &x_s, const int &y_s, const int &x_e, const int &y_e, const float &red, const float &green, const float &blue)
{
	if (x_e == x_s)
	{
		for (int y = y_s; y <= y_e; y++)
			drawPixel(x_s, y, red, green, blue);
	}
	else
	{
		for (int i = x_s; i <= x_e; i++)
		{
			const int j = (y_e - y_s)*(i - x_s) / (x_e - x_s) + y_s;
			drawPixel(i, j, red, green, blue);
		}
	}
}


// Draw circle around icon
void GeometricObject::draw(const int &i, const int &j, const int &r, const float &red, const float &green, const float &blue)
{
	Circle * circle = new Circle(getInstance());

	circle->drawCircle(i, j, r, red, green, blue);
}

// Factory pattern
GeometricObject* GeometricObject::drawGeometricObject(const int &object, GeometricObject *temp)
{
	int i, j, r;

	if (object == 0)
	{
		temp = new ThickLine(temp);
		i = 100; j = 600; r = 50;
	}
	else if (object == 1)
	{
		temp = new Circle(temp);
		i = 250; j = 600; r = 50;
	}
	else if (object == 2)
	{
		temp = new EmptySquare(temp);
		i = 400; j = 600; r = 50;
	}
	else if (object == 3)
	{
		temp = new Cross(temp);
		i = 550; j = 600; r = 50;
	}
	else if (object == 4)
	{
		temp = new UnderArrow(temp);
		i = 700; j = 600; r = 50;
	}
	else if (object == 5)
	{
		temp = new RightArrow(temp);
		i = 100; j = 450; r = 50;
	}
	else if (object == 6)
	{
		temp = new Form_A(temp);
		i = 250; j = 450; r = 50;
	}
	else if (object == 7)
	{
		temp = new PerpenLine(temp);
		i = 400; j = 450; r = 50;
	}
	else if (object == 8)
	{
		temp = new LeftArrow(temp);
		i = 550; j = 450; r = 50;
	}
	else if (object == 9)
	{
		temp = new TopArrow(temp);
		i = 700; j = 450; r = 50;
	}
	if (object == 10)
	{
		temp = new ThickLine(temp);
		i = 100; j = 300; r = 50;
	}
	else if (object == 11)
	{
		temp = new Circle(temp);
		i = 250; j = 300; r = 50;
	}
	else if (object == 12)
	{
		temp = new EmptySquare(temp);
		i = 400; j = 300; r = 50;
	}
	else if (object == 13)
	{
		temp = new Cross(temp);
		i = 550; j = 300; r = 50;
	}
	else if (object == 14)
	{
		temp = new UnderArrow(temp);
		i = 700; j = 300; r = 50;
	}
	else if (object == 15)
	{
		temp = new RightArrow(temp);
		i = 100; j = 150; r = 50;
	}
	else if (object == 16)
	{
		temp = new Form_A(temp);
		i = 250; j = 150; r = 50;
	}
	else if (object == 17)
	{
		temp = new PerpenLine(temp);
		i = 400; j = 150; r = 50;
	}
	else if (object == 18)
	{
		temp = new LeftArrow(temp);
		i = 550; j = 150; r = 50;
	}
	else if (object == 19)
	{
		temp = new TopArrow(temp);
		i = 700; j = 150; r = 50;
	}
	
	temp->draw(i, j, r, 1.0f, 0.0f, 0.0f);

	return nullptr;
}



