#include <GL3/gl3w.h>
#include <GL/glfw.h>
#include <GL3/gl3.h>
#include <iostream>
#include <stdexcept>
#include "singleton.h"
#include "renderer.h"

int main(int argc, char** argv)
{
	C_Renderer* r = C_Singleton::M_Renderer();
	C_Singleton::M_DestroySingletons();
}
