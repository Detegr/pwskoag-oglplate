#pragma once
#include <GL3/gl3w.h>
#include <GL/glfw.h>
#include <GL3/gl3.h>
#include <iostream>

class C_Model
{
	friend class C_ModelManager;
	public: static const unsigned short COMPONENTS_PER_VERT=2; // Change this to 3 if using 3D models.
	private:
		std::string m_Name;
		GLuint m_Vbo;
		float m_Width;
		float m_Height;
		unsigned short m_Vertices;
	public:
		C_Model();
		C_Model(const std::string& name, GLuint vbo, float width, float height, unsigned short verts);
		std::pair<GLuint,unsigned short> M_Get() const;
		void M_Draw() const;
		const std::string& M_Name() const;
		float M_Width() const;
		float M_Height() const;
};
