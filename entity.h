#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "model.h"

class C_Entity
{
	friend class C_Renderer;
	friend class C_DynamicEntity;
	friend class C_StaticEntity;
	private:
		float m_Posx;
		float m_Posy;
		C_Entity();
		C_Entity(const C_Model& m, float scale);
	protected:
		C_Model m_Model;
		float m_Scale;
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
		static C_Entity* M_Create(const C_Model& m, float scale=1.0f);
		virtual void M_Translate(float amount, unsigned char axis);
		virtual void M_SetPosition(float x, float y);
		void M_Scale(float amount);
		float M_Scale() const { return m_Scale; }
		void M_SetScale(float amount);
		virtual void M_Rotate(float amount);
		virtual void M_SetRotation(float amount);
		const std::string& M_ModelName() const;
		virtual const glm::mat4& M_ModelMatrix();
};
