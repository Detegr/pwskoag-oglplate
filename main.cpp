#include <iostream>
#include <stdexcept>
#include "singleton.h"
#include "renderer.h"

int main(int argc, char** argv)
{
	bool run=true;
	C_Renderer* r = C_Singleton::M_Renderer();
	C_ShaderManager* s = C_Singleton::M_ShaderManager();
	s->M_Load("minimal");
	s->M_Get("minimal").M_Use();
	GLuint va;
	glGenVertexArrays(1,&va);
	glBindVertexArray(va);
	static const GLfloat d[]={
-1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
  };
	GLuint vb;
	glGenBuffers(1, &vb);
	glBindBuffer(GL_ARRAY_BUFFER, vb);
	glBufferData(GL_ARRAY_BUFFER, sizeof(d), d, GL_STATIC_DRAW);
	while(run)
	{
		//r->M_Draw();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vb);
		glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
		glDrawArrays(GL_TRIANGLES,0,3);
		glDisableVertexAttribArray(0);
		glfwSwapBuffers();
		run=!(C_Singleton::M_InputHandler()->M_Get(ESC));
	}
	C_Singleton::M_DestroySingletons();
}
