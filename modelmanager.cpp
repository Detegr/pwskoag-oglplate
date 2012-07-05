#include "modelmanager.h"
#include "filereader.h"
#include <sstream>
#include <iostream>
#include <stdexcept>

void C_Model::M_Draw() const
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
	glVertexAttribPointer(0,m_Vertices,GL_FLOAT,GL_FALSE,0,(void*)0);
	glDrawArrays(GL_TRIANGLES,0,m_Vertices);
	glDisableVertexAttribArray(0);
}

std::pair<GLuint,unsigned short> C_Model::M_Get() const
{
	return std::make_pair(m_Vbo, m_Vertices);
}

bool C_ModelManager::M_Load(const std::string& name, const std::string& path)
{
	std::vector<std::string> f=C_FileReader::M_ReadToArray(path);
	std::stringstream ss;
	ss.precision(2);
	float val=0;
	std::vector<GLfloat> verts;
	for(std::vector<std::string>::iterator it=f.begin(); it!=f.end(); ++it)
	{
		ss.clear();
		ss << *it;
		ss >> val;
		verts.push_back(val);
	}
	m_Models.push_back(C_Model(name, 0, verts.size()/3));

	glGenBuffers(1, &m_Models.back().m_Vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_Models.back().m_Vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*verts.size(), &verts[0], GL_STATIC_DRAW);

	return true;
}

const C_Model& C_ModelManager::M_Get(const std::string& name) const
{
	for(std::vector<C_Model>::const_iterator it=m_Models.begin(); it!=m_Models.end(); ++it)
	{
		if(it->M_Name() == name) return *it;
	}
	throw std::runtime_error("Model " + name + " does not exist!");
}
