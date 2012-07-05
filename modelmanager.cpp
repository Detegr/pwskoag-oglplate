#include "modelmanager.h"
#include "filereader.h"
#include <sstream>
#include <iostream>
#include <stdexcept>

void C_Model::M_Draw() const
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
	glDrawArrays(GL_TRIANGLE_STRIP,0,m_Vertices);
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
	int i=0;
	for(std::vector<std::string>::iterator it=f.begin(); it!=f.end(); ++it, ++i)
	{
		ss.clear();
		ss << *it;
		ss >> val;
		if(i==2)
		{//Every third vertex will be 0.0 as we are supporting 2D only
			verts.push_back(0.0f);
			i=0;
		}
		verts.push_back(val);
	}
	verts.push_back(0.0f);
	GLfloat g[64];
	for(unsigned int i=0; i<verts.size(); ++i)
	{
		g[i]=verts[i];
	}

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*verts.size(), g, GL_STATIC_DRAW);

	m_Models.push_back(C_Model(name, vbo, verts.size()/3));

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
