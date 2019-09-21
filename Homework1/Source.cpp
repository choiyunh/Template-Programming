#include <algorithm>
#include <stdbool.h>
#include <cstring>
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds

#include <iostream>
#include <GLFW/glfw3.h>
#include "GeometricObject.h"

void main()
{
	GeometricObject* geo = new GeometricObject(900, 700);
	geo->instance = geo;
	
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(geo->width, geo->height, "HelloWorld", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return;
	}


	/* Make the window's context current */
	glfwMakeContextCurrent(window);


	geo->background(1.0f, 1.0f, 1.0f);

	/* Loop until the user closes the window */

	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		//assign all pixels red color
		//////////////////////////////////////////////////////////////////////

		for (int i = 0; i < 20; i++)
		{
			geo->drawGeometricObject(i, geo);
		}

		//////////////////////////////////////////////////////////////////////

		glDrawPixels(geo->width, geo->height, GL_RGB, GL_FLOAT, geo->pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

	}

	glfwTerminate();

	delete geo;

	return;
}
