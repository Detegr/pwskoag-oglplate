#pragma once
#include <GL3/gl3w.h>
#include <GL/glfw.h>
#include <GL3/gl3.h>
#include <vector>
#include <iostream>

class C_Model
{
	friend class C_ModelManager;
	private:
		std::string m_Name;
		GLuint m_Vbo;
		unsigned short m_Vertices;
	public:
		C_Model() : m_Name(), m_Vbo(0), m_Vertices(0) {}
		C_Model(const std::string& name, GLuint vbo, unsigned short verts) :
			m_Name(name), m_Vbo(vbo), m_Vertices(verts) {}
		std::pair<GLuint,unsigned short> M_Get() const;
		void M_Draw() const;
		const std::string& M_Name() const { return m_Name; }
};

class C_ModelManager
{
	friend class C_Singleton;
	public: static const unsigned short COMPONENTS_PER_VERT=2; // Change this to 3 if using 3D models.
	private:
		C_ModelManager() { std::cout << "Initializing modelmanager...OK!" << std::endl; }
		~C_ModelManager() { std::cout << "Destroying modelmanager...OK!" << std::endl; }
		std::vector<C_Model> m_Models;
	public:
		bool M_Load(const std::string& name, const std::string& path);
		const C_Model& M_Get(const std::string& model) const;
};
