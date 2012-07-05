#include "singleton.h"

C_Renderer* C_Singleton::m_Renderer;
C_InputHandler* C_Singleton::m_InputHandler;
C_ShaderManager* C_Singleton::m_ShaderManager;

C_Renderer* C_Singleton::M_Renderer()
{
	if(!m_Renderer) m_Renderer = new C_Renderer(DTGLIB_WINDOW_WIDTH, DTGLIB_WINDOW_HEIGHT);
	return m_Renderer;
}
C_InputHandler* C_Singleton::M_InputHandler()
{
	if(!m_InputHandler) m_InputHandler = new C_InputHandler;
	return m_InputHandler;
}
C_ShaderManager* C_Singleton::M_ShaderManager()
{
	if(!m_ShaderManager) m_ShaderManager = new C_ShaderManager;
	return m_ShaderManager;
}

void C_Singleton::M_DestroySingletons()
{
	if(m_Renderer) delete m_Renderer;
	if(m_InputHandler) delete m_InputHandler;
	if(m_ShaderManager) delete m_ShaderManager;
}

