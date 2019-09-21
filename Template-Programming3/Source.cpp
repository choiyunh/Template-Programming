#include <iostream>
#include <string>
#include <vector>
#include "Painting2D.h"

Painting2D my_painting;

class Box // NO PARENT
{
public:
	void draw()
	{
		my_painting.drawLine(200, 350, 300, 350, 1.0f, 0.0f, 0.0f);
		my_painting.drawLine(200, 350, 200, 450, 1.0f, 0.0f, 0.0f);
		my_painting.drawLine(300, 350, 300, 450, 1.0f, 0.0f, 0.0f);
		my_painting.drawLine(200, 450, 300, 450, 1.0f, 0.0f, 0.0f);
	}
};

class Circle // NO PARENT
{
public:
	void draw()
	{
		my_painting.drawCircle(100, 400, 50, 1.0f, 0.0f, 0.0f);
	}
};

class GeometricObjectInterface
{
public:
	virtual void draw() = 0;
};

template<class T>
class GeometricObject : public GeometricObjectInterface
{
public:
	void draw()
	{
		T operation;
		operation.draw();
	}
};


// And implement an templatized GeometricObject class.
int main()
{
	std::vector<GeometricObjectInterface*> obj_list;

	obj_list.push_back(new GeometricObject<Box>);
	obj_list.push_back(new GeometricObject<Circle>);


	my_painting.initialize();
	while (!my_painting.CloseWindow())
	{
		// background
		for (int j = 0; j < my_painting.height; j++)
		{
			for (int i = 0; i < my_painting.width; i++)
				my_painting.drawPixel(i, j, 1.0f, 1.0f, 1.0f);
		}

		my_painting.BeforeDraw();

		for (auto itr : obj_list)
			itr->draw();

		my_painting.AfterDraw();

	}

	return 0;
}




