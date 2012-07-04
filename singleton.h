#pragma once
#include "renderer.h"

#define DTGLIB_WINDOW_WIDTH 800
#define DTGLIB_WINDOW_HEIGHT 600

class C_Singleton
{
	private:
		static C_Renderer* m_Renderer;

	public:
		static C_Renderer* M_Renderer();
		static void M_DestroySingletons();
};
