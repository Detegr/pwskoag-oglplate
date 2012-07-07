#include <iostream>
#include <stdexcept>
#include "singleton.h"
#include "renderer.h"
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
	if(s->M_Load("minimal"))
	{
		r->M_Use(s->M_Get("minimal"));
	} else exit(1);
	C_ModelManager* m = C_Singleton::M_ModelManager();
	if(!m->M_Load("triangle", "test.2dmodel")) exit(1);
	for(int i=0; i<360; ++i)
	{
		C_Entity* e = new C_Entity(m->M_Get("triangle"));
		e->M_Scale(0.285f);
		e->M_Rotate(i*5);
		r->M_AddEntity(e);
	}
	C_MSPF timer;
	while(run)
	{
		timer.M_SetTime();
		r->M_Draw();
		glfwSleep(0.010);
		run=!(C_Singleton::M_InputHandler()->M_Get(ESC));
	}
	C_Singleton::M_DestroySingletons();
}
