#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "model.h"

class C_Entity
{
	friend class C_Renderer;
	private:
		C_Model m_Model;
		glm::mat4 m_ModelMatrix;
	public:
		C_Entity();
		C_Entity(const C_Model& m);
		void M_Translate(float amount);
		void M_Scale(float amount);
		void M_Rotate(float amount);
		const glm::mat4& M_ModelMatrix() const;
};
