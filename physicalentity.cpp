#include "physicalentity.h"

void C_PhysicalEntity::M_Sync()
{
	b2Vec2 pos=m_Body->GetPosition();
	float32 ang=m_Body->GetAngle();
	//std::cout << m_Entity->M_ModelName() << " pos: " << pos.x << " " << pos.y << std::endl;
	float entityscale=this->m_Entity->M_Scale();
	m_Entity->M_SetPosition(pos.x/entityscale/10.0f, pos.y/entityscale/10.0f);
	m_Entity->M_SetRotation((180/3.14)*ang);
}

C_StaticEntity::C_StaticEntity(b2World& w, C_Entity* e, float32 s)
{
	this->m_Entity=e;
	b2BodyDef bodydef;
	bodydef.position.Set(m_Entity->m_Posx*s, m_Entity->m_Posy*s);

	this->m_Body = w.CreateBody(&bodydef);

	b2PolygonShape hitshape;
	float entityscale=this->m_Entity->M_Scale();
	hitshape.SetAsBox((m_Entity->m_Model.M_Width()/2)*entityscale*s, (m_Entity->m_Model.M_Height()/2)*entityscale*s);
	this->m_Body->CreateFixture(&hitshape, 0.0f);
};

C_DynamicEntity::C_DynamicEntity(b2World& w, C_Entity* e, float32 s)
{
	this->m_Entity=e;
	float entityscale=this->m_Entity->M_Scale();

	b2BodyDef bodydef;
	bodydef.position.Set(m_Entity->m_Posx*s, m_Entity->m_Posy*s);
	bodydef.type=b2_dynamicBody;
	this->m_Body = w.CreateBody(&bodydef);

	b2PolygonShape hitshape;
	hitshape.SetAsBox((m_Entity->m_Model.M_Width()/2)*entityscale*s, (m_Entity->m_Model.M_Height()/2)*entityscale*s);

	b2FixtureDef fix;
	fix.shape=&hitshape;
	fix.density=1.0f;
	fix.friction=0.3f;
	fix.restitution=0.5f;

	this->m_Body->CreateFixture(&fix);
};
