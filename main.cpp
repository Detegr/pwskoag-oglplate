#include <iostream>
#include <stdexcept>
#include "singleton.h"

int main()
{
	bool run=true;
	C_Renderer* r = C_Singleton::M_Renderer();
	C_ShaderManager* s = C_Singleton::M_ShaderManager();
	C_PhysicsManager* p = C_Singleton::M_PhysicsManager();
	C_Timer* t = C_Singleton::M_Timer();

	if(s->M_Load("minimal"))
	{
		r->M_Use(s->M_Get("minimal"));
	} else exit(1);
	C_ModelManager* m = C_Singleton::M_ModelManager();
	if(!m->M_Load("triangle", "test.2dmodel")) exit(1);
	if(!m->M_Load("ground", "ground.2dmodel")) exit(1);
	if(!m->M_Load("box", "box.2dmodel")) exit(1);
	C_Entity* e = C_Entity::M_Create(m->M_Get("triangle"), 0.08f);
	C_Entity* g = C_Entity::M_Create(m->M_Get("ground"), 1.0f);
	C_Entity* g2 = C_Entity::M_Create(m->M_Get("ground"), 1.0f);
	C_Entity* g3 = C_Entity::M_Create(m->M_Get("ground"), 0.585f);
	C_Entity* box1 = C_Entity::M_Create(m->M_Get("box"), 0.08f);
	C_Entity* box2 = C_Entity::M_Create(m->M_Get("box"), 0.04f);
	C_Entity* box3 = C_Entity::M_Create(m->M_Get("box"), 0.02f);
	C_Entity* box4 = C_Entity::M_Create(m->M_Get("box"), 0.10f);

	box1->M_SetPosition(0.4f, -0.2f);
	box2->M_SetPosition(0.2f, -0.4f);
	box3->M_SetPosition(0.0f, -0.6f);
	box4->M_SetPosition(-0.2f, -0.8f);
	e->M_SetPosition(0.0f,0.3f);
	g->M_SetPosition(0.0f,1.0f);
	g2->M_SetPosition(0.0f,-1.0f);
	g3->M_SetPosition(0.0f,0.123f);
	p->M_CreateStaticEntity(g);
	p->M_CreateStaticEntity(g2);
	p->M_CreateStaticEntity(g3);
	p->M_CreateDynamicEntity(box1);
	p->M_CreateDynamicEntity(box2);
	p->M_CreateDynamicEntity(box3);
	p->M_CreateDynamicEntity(box4);
	p->M_CreateDynamicEntity(e)->M_Controllable(true);
	while(run)
	{
		t->M_SetTime();
		p->M_Simulate();
		r->M_Draw();
		run=!(C_Singleton::M_InputHandler()->M_Get(ESC));
		glfwSleep(0.001f);
	}
	C_Singleton::M_DestroySingletons();
}
