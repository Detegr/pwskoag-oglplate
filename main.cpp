#include <iostream>
#include <stdexcept>
#include "singleton.h"
#include "renderer.h"
#include <cstdlib>

int main()
{
	bool run=true;
	C_Renderer* r = C_Singleton::M_Renderer();
	C_ShaderManager* s = C_Singleton::M_ShaderManager();
	if(s->M_Load("minimal"))
	{
		r->M_Use(s->M_Get("minimal"));
	} else exit(1);
	C_ModelManager* m = C_Singleton::M_ModelManager();
	if(!m->M_Load("triangle", "test.2dmodel")) exit(1);
	C_Entity* e = new C_Entity(m->M_Get("triangle"), 0.285);
	r->M_AddEntity(e);
	while(run)
	{
		r->M_Draw();
		run=!(C_Singleton::M_InputHandler()->M_Get(ESC));
	}
	C_Singleton::M_DestroySingletons();
}
