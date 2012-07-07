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
		glm::mat4 m_TranslationMatrix;
		glm::mat4 m_ScaleMatrix;
		glm::mat4 m_RotationMatrix;
	public:
		enum
		{
			x=1,
			y=2
		};
		C_Entity();
		C_Entity(const C_Model& m);
		void M_Translate(float amount, unsigned char axis);
		void M_SetPosition(float amount, unsigned char axis);
		void M_Scale(float amount);
		void M_SetScale(float amount);
		void M_Rotate(float amount);
		void M_SetRotation(float amount);
		const std::string& M_ModelName() const;
		const glm::mat4& M_ModelMatrix();
};
