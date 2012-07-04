#include "singleton.h"

C_Renderer* C_Singleton::m_Renderer;

C_Renderer* C_Singleton::M_Renderer()
{
	if(!m_Renderer) m_Renderer = new C_Renderer(DTGLIB_WINDOW_WIDTH, DTGLIB_WINDOW_HEIGHT);
	return m_Renderer;
}

void C_Singleton::M_DestroySingletons()
{
	if(m_Renderer) delete m_Renderer;
}

