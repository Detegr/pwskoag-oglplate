#include <iostream>
#include <stdexcept>
#include "singleton.h"
#include "renderer.h"

int main()
{
	bool run=true;
	/*C_Renderer* r = */C_Singleton::M_Renderer();
	C_ShaderManager* s = C_Singleton::M_ShaderManager();
	if(s->M_Load("minimal")) s->M_Get("minimal").M_Use();
	C_ModelManager* m = C_Singleton::M_ModelManager();
	m->M_Load("triangle", "test.2dmodel");
	C_Model mod=m->M_Get("triangle");
	while(run)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		mod.M_Draw();
		glfwSwapBuffers();
		run=!(C_Singleton::M_InputHandler()->M_Get(ESC));
	}
	C_Singleton::M_DestroySingletons();
}
