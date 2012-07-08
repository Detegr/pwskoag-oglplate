#include "entity.h"
#include "singleton.h"

C_Entity::C_Entity() : m_Model(), m_Scale(1.0f), m_ModelMatrix(glm::mat4(1.0f)) {}
C_Entity::C_Entity(const C_Model& m, float scale) : m_Model(m), m_Scale(scale), m_ModelMatrix(glm::mat4(1.0f))
{
	M_Scale(scale);
}

C_Entity* C_Entity::M_Create(const C_Model& m, float scale)
{
	C_Entity* e=new C_Entity(m, scale);
	C_Renderer* r=C_Singleton::M_Renderer();
	r->M_AddEntity(e);
	return e;
}

void C_Entity::M_Translate(float amount, unsigned char axis)
{
	bool x=(axis|0xFE) == 0xFF;
	bool y=(axis|0xFD) == 0xFF;
	float xamount = x?amount:0.0f;
	float yamount = y?amount:0.0f;
	m_TranslationMatrix = glm::translate(m_TranslationMatrix, glm::vec3(xamount,yamount,0.0f));
}

void C_Entity::M_SetPosition(float x, float y)
{
	m_TranslationMatrix = glm::translate(glm::mat4(1.0), glm::vec3(x,y,0.0f));
	m_Posx=x; m_Posy=y;
}

void C_Entity::M_Scale(float amount)
{
	m_ScaleMatrix = glm::scale(m_ScaleMatrix, glm::vec3(amount));
}

void C_Entity::M_SetScale(float amount)
{
	m_ScaleMatrix = glm::scale(glm::mat4(1.0), glm::vec3(amount));
}

void C_Entity::M_Rotate(float amount)
{
	m_RotationMatrix = glm::rotate(m_RotationMatrix, amount, glm::vec3(0.0f, 0.0f, 1.0f));
}

void C_Entity::M_SetRotation(float amount)
{
	m_RotationMatrix = glm::rotate(glm::mat4(1.0), amount, glm::vec3(0.0f, 0.0f, 1.0f));
}
const glm::mat4& C_Entity::M_ModelMatrix()
{
	m_ModelMatrix = m_ScaleMatrix * m_TranslationMatrix * m_RotationMatrix;
	return m_ModelMatrix;
}

const std::string& C_Entity::M_ModelName() const
{
	return m_Model.M_Name();
}
