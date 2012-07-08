#include <iostream>
#include <stdexcept>
#include "singleton.h"
#include <cstdlib>
#include <cstring>

class C_MSPF
{
	private:
		unsigned m_Frames;
		double m_PrevTime;
		double m_Time;
		char title[64];
	public:
		C_MSPF() : m_Frames(0), m_PrevTime(glfwGetTime()), m_Time(-100.0f)
		{
			memset(title, 0, 64);
		}
		void M_SetTime()
		{
			m_Frames++;
			double t=glfwGetTime();
			if(1.0f + m_PrevTime <= t)
			{
				float mspf=(t-m_PrevTime)*1000 / m_Frames;
				sprintf(title, "ms per frame: %f", mspf);
				glfwSetWindowTitle(title);
				m_PrevTime=t;
				m_Frames=0;
			}
		}
};

int main()
{
	bool run=true;
	C_Renderer* r = C_Singleton::M_Renderer();
	C_ShaderManager* s = C_Singleton::M_ShaderManager();
	C_PhysicsManager* p = C_Singleton::M_PhysicsManager();
	if(s->M_Load("minimal"))
	{
		r->M_Use(s->M_Get("minimal"));
	} else exit(1);
	C_ModelManager* m = C_Singleton::M_ModelManager();
	if(!m->M_Load("triangle", "test.2dmodel")) exit(1);
	if(!m->M_Load("ground", "ground.2dmodel")) exit(1);
	C_Entity* e = C_Entity::M_Create(m->M_Get("triangle"), 0.1f);
	C_Entity* g = C_Entity::M_Create(m->M_Get("ground"), 1.0f);
	C_Entity* g2 = C_Entity::M_Create(m->M_Get("ground"), 1.0f);
	C_Entity* g3 = C_Entity::M_Create(m->M_Get("ground"), 0.585f);
	e->M_SetPosition(0.0f,0.3f);
	g->M_SetPosition(0.0f,1.0f);
	g2->M_SetPosition(0.0f,-1.0f);
	g3->M_SetPosition(0.0f,0.123f);
	p->M_CreateStaticEntity(g);
	p->M_CreateStaticEntity(g2);
	p->M_CreateStaticEntity(g3);
	p->M_CreateDynamicEntity(e);
	C_MSPF timer;
	while(run)
	{
		timer.M_SetTime();
		p->M_Simulate();
		r->M_Draw();
		glfwSleep(0.005);
		run=!(C_Singleton::M_InputHandler()->M_Get(ESC));
	}
	C_Singleton::M_DestroySingletons();
}
