#include "physics.h"
#include <cmath>

C_Physics::C_Physics() :
	m_World(b2Vec2(0.0f, 0.0f))
{
	m_World.SetAllowSleeping(true);
}

void C_Physics::M_CreateBody()
{
	b2BodyDef gnddef;
	gnddef.position.Set(0.0f, -1.0f*m_ScaleFactor);
	b2Body* gnd = m_World.CreateBody(&gnddef);

	b2PolygonShape gndbox;
	gndbox.SetAsBox(1.0f*m_ScaleFactor, 0.1f*m_ScaleFactor);
	
	gnd->CreateFixture(&gndbox, 0.0f);

	b2BodyDef bodydef;
	bodydef.type = b2_dynamicBody; // Move in response to forces.
	bodydef.position.Set(0.0f, 0.0f);
	b2Body* body = m_World.CreateBody(&bodydef);

	b2PolygonShape dynamicbox;
	dynamicbox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fix;
	fix.shape = &dynamicbox;
	fix.density = 1.0f;
	fix.friction = 0.3f;
	fix.restitution=0.8f;

	body->CreateFixture(&fix);
	m_Bodies.push_back(body);
}

void C_Physics::M_Simulate(C_Entity* e)
{
	m_World.Step(m_TimeStep, m_VelocityIterations, m_PositionIterations);
	b2Vec2 pos = m_Bodies[0]->GetPosition();
	float32 a = m_Bodies[0]->GetAngle();

	b2Vec2 force = b2Vec2(-sin(a), cos(a));
	force*=4.0f;

	if(C_Singleton::M_InputHandler()->M_Get(LEFT))
	{
		m_Bodies[0]->SetAngularVelocity(1.0f);
	}
	else if(C_Singleton::M_InputHandler()->M_Get(RIGHT))
	{
		m_Bodies[0]->SetAngularVelocity(-1.0f);
	}
	else m_Bodies[0]->SetAngularVelocity(0.0f);

	if(C_Singleton::M_InputHandler()->M_Get(UP))
	{
		m_Bodies[0]->ApplyForceToCenter(force);
	}

	e->M_SetPosition(pos.x, pos.y);
	e->M_SetRotation((180/3.14)*a);
}
