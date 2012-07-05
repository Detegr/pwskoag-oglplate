#pragma once
#include <GL3/gl3w.h>
#include <GL/glfw.h>
#include <GL3/gl3.h>

class C_Renderer
{
	private:
		friend class C_Singleton;
		C_Renderer(unsigned width, unsigned height);
		~C_Renderer();
	public:
		bool M_Opened() {return glfwGetWindowParam(GLFW_OPENED);}
		void M_Draw();
};
