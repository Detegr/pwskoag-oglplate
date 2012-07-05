#include <iostream>
#include <stdexcept>
#include "singleton.h"
#include "renderer.h"
#include <cstdlib>

int main()
{
	bool run=true;
	/*C_Renderer* r = */C_Singleton::M_Renderer();
	C_ShaderManager* s = C_Singleton::M_ShaderManager();
	if(s->M_Load("minimal"))
	{
		s->M_Get("minimal").M_Use();
	} else exit(1);
	C_ModelManager* m = C_Singleton::M_ModelManager();
	if(!m->M_Load("triangle", "test.2dmodel")) exit(1);
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
