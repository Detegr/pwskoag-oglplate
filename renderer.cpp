#include "renderer.h"
#include <iostream>
#include <stdexcept>

C_Renderer::C_Renderer(unsigned width, unsigned height)
{
	std::cout << "Initializing renderer..." << std::flush;
	if(!glfwInit()) throw std::runtime_error("Could not initialize renderer.");
	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
	glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if(!glfwOpenWindow(width,height,0,0,0,0,0,0,GLFW_WINDOW))
	{
		glfwTerminate();
		throw std::runtime_error("Could not open window.");
	}
	if(gl3wInit())
	{
		glfwTerminate();
		throw std::runtime_error("Could not initialize gl3w.");
	}
	if(!gl3wIsSupported(3,2))
	{
		glfwTerminate();
		throw std::runtime_error("OpenGL 3.3 is not supported.");
	}
	glClearColor(0.0f, 0.0f, 0.3f, 0.0f);
	std::cout << "OK!" << std::endl;
}

void C_Renderer::M_Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers();
}

C_Renderer::~C_Renderer()
{
	std::cout << "Destroying renderer..." << std::flush;
	glfwTerminate();
	std::cout << "OK!" << std::endl;
}
