#include "renderer.h"
#include <iostream>
#include <stdexcept>

C_Renderer::C_Renderer(unsigned width, unsigned height)
{
	std::cout << "Initializing renderer..." << std::flush;
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
	glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if(!glfwInit()) throw std::runtime_error("Could not initialize renderer.");
	if(!glfwOpenWindow(width,height,0,0,0,0,0,0,GLFW_WINDOW))
	{
		glfwTerminate();
		throw std::runtime_error("Could not open window.");
	}
	std::cout << "OK!" << std::endl;
}

C_Renderer::~C_Renderer()
{
	std::cout << "Destroying renderer..." << std::flush;
	glfwTerminate();
	std::cout << "OK!" << std::endl;
}
