#pragma once
#include <GL3/gl3w.h>
#include <GL/glfw.h>
#include <GL3/gl3.h>
#include <vector>
#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

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

class C_Entity
{
	friend class C_Renderer;
	private:
		C_Model m_Model;
		glm::mat4 m_ModelMatrix;
	public:
		C_Entity() : m_Model(), m_ModelMatrix(glm::mat4(1.0f)) {}
		C_Entity(const C_Model& m) : m_Model(m), m_ModelMatrix(glm::mat4(1.0f)) {}
		C_Entity(const C_Model& m, float initialscale) :
			m_Model(m),
			m_ModelMatrix(glm::mat4(1.0f))
		{
			M_Scale(initialscale);
		}

		void M_Translate(float amount)
		{
			m_ModelMatrix = glm::translate(m_ModelMatrix, glm::vec3(amount,amount,0.0f));
		}

		void M_Scale(float amount)
		{
			m_ModelMatrix = glm::scale(m_ModelMatrix, glm::vec3(amount));
		}

		void M_Rotate(float amount)
		{
			m_ModelMatrix = glm::rotate(m_ModelMatrix, amount, glm::vec3(0.0f, 0.0f, 1.0f));
		}
		const glm::mat4& M_ModelMatrix() const
		{
			return m_ModelMatrix;
		}
};
