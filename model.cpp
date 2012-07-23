#include "model.h"

C_Model::C_Model() : m_Name(), m_Vbo(0), m_Vertices(0) {}
C_Model::C_Model(const std::string& name, GLuint vbo, float width, float height, unsigned short verts) :
	m_Name(name), m_Vbo(vbo), m_Width(width), m_Height(height), m_Vertices(verts) {}

std::pair<GLuint,unsigned short> C_Model::M_Get() const
{
	return std::make_pair(m_Vbo, m_Vertices);
}

void C_Model::M_Draw() const
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
	glVertexAttribPointer(0,C_Model::COMPONENTS_PER_VERT,GL_FLOAT,GL_FALSE,0,(void*)0);
	glDrawArrays(GL_TRIANGLE_STRIP,0,m_Vertices);
	glDisableVertexAttribArray(0);
}

const std::string& C_Model::M_Name() const
{
	return m_Name;
}

float C_Model::M_Width() const
{
	return m_Width;
}

float C_Model::M_Height() const
{
	return m_Height;
}
