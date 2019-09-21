#pragma once


class GeometricObject
{
public:
	int width;
	int height;
	float *pixels;
	static GeometricObject* instance;

	GeometricObject();
	GeometricObject(const int& w, const int& h);

	~GeometricObject();

	static GeometricObject* getInstance();

	static GeometricObject* drawGeometricObject(const int& object, GeometricObject* test);

	void background(const float& red, const float& green, const float& blue);

	virtual void draw(const int& i, const int& j, const int& r, const float& red, const float& green, const float& blue);
	void drawPixel(const int& x, const int& y, const float& red, const float& green, const float& blue);
	void drawLine(const int& x_s, const int& y_s, const int& x_e, const int& y_e, const float& red, const float& green, const float& blue);
	
};

