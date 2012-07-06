#include "entity.h"

C_Entity::C_Entity() : m_Model(), m_ModelMatrix(glm::mat4(1.0f)) {}
C_Entity::C_Entity(const C_Model& m) : m_Model(m), m_ModelMatrix(glm::mat4(1.0f)) {}

void C_Entity::M_Translate(float amount)
{
	m_ModelMatrix = glm::translate(m_ModelMatrix, glm::vec3(amount,amount,0.0f));
}
void C_Entity::M_Scale(float amount)
{
	m_ModelMatrix = glm::scale(m_ModelMatrix, glm::vec3(amount));
}
void C_Entity::M_Rotate(float amount)
{
	m_ModelMatrix = glm::rotate(m_ModelMatrix, amount, glm::vec3(0.0f, 0.0f, 1.0f));
}
const glm::mat4& C_Entity::M_ModelMatrix() const
{
	return m_ModelMatrix;
}
