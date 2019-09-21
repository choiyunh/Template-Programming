#pragma once
#include <GLFW/glfw3.h>
#include <iostream>


class Painting2D
{
public:
	GLFWwindow* window;

	const int width = 800;
	const int height = 600;

	float *pixels;

	//default constructor
	Painting2D()
		:window(nullptr), pixels(nullptr) {}

	//destructor
	~Painting2D() 
	{

		if (pixels != nullptr)
			delete pixels;

		glfwTerminate();
	}


	void initialize()
	{
		/* Initialize the library */
		if (!glfwInit())
		{
			exit(1);
		}

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
		if (!window)
		{
			glfwTerminate();

			exit(1);
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);

		pixels = new float[width * height * 3];
	}


	void drawPixel(const int& x, const int& y, const float& red, const float& green, const float& blue)
	{
		pixels[(x + width*y) * 3 + 0] = red;
		pixels[(x + width*y) * 3 + 1] = green;
		pixels[(x + width*y) * 3 + 2] = blue;
	}

	void drawLine(const int& x_s, const int& y_s, const int& x_e, const int& y_e, const float& red, const float& green, const float& blue)
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
					drawPixel(i, j, red, green, blue);
				}
			}
		}
	}


	bool CloseWindow()
	{
		return (bool)glfwWindowShouldClose(window);
	}

	void BeforeDraw()
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
	}


	void AfterDraw()
	{
		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

};
