#include <iostream>
#include <stdexcept>
#include "singleton.h"
#include "renderer.h"
#include "physics.h"
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
	C_Physics p;
	p.M_CreateBody();
	if(s->M_Load("minimal"))
	{
		r->M_Use(s->M_Get("minimal"));
	} else exit(1);
	C_ModelManager* m = C_Singleton::M_ModelManager();
	if(!m->M_Load("triangle", "test.2dmodel")) exit(1);
	if(!m->M_Load("ground", "ground.2dmodel")) exit(1);
	C_Entity* e = new C_Entity(m->M_Get("triangle"));
	C_Entity* g = new C_Entity(m->M_Get("ground"));
	e->M_Scale(0.1f);
	r->M_AddEntity(e);
	r->M_AddEntity(g);
	C_MSPF timer;
	while(run)
	{
		timer.M_SetTime();
		p.M_Simulate(e);
		r->M_Draw();
		glfwSleep(0.005);
		run=!(C_Singleton::M_InputHandler()->M_Get(ESC));
	}
	C_Singleton::M_DestroySingletons();
}
