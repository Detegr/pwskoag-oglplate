#pragma once
#include "renderer.h"
#include "inputhandler.h"
#include "shadermanager.h"
#include "modelmanager.h"

#define DTGLIB_WINDOW_WIDTH 800
#define DTGLIB_WINDOW_HEIGHT 600

class C_Singleton
{
	private:
		static C_Renderer* m_Renderer;
		static C_InputHandler* m_InputHandler;
		static C_ShaderManager* m_ShaderManager;
		static C_ModelManager* m_ModelManager;

	public:
		static C_Renderer* M_Renderer();
		static C_InputHandler* M_InputHandler();
		static C_ShaderManager* M_ShaderManager();
		static C_ModelManager* M_ModelManager();
		static void M_DestroySingletons();
};
