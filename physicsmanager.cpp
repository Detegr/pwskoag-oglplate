#include "physicsmanager.h"
#include "singleton.h"
#include <typeinfo>

C_PhysicsManager::C_PhysicsManager() :
	m_World(b2Vec2(0.0f, -0.0f))
{
	m_World.SetAllowSleeping(true);
}
C_PhysicsManager::~C_PhysicsManager()
{
	for(std::vector<C_PhysicalEntity*>::iterator it=m_Bodies.begin(); it!=m_Bodies.end(); ++it)
	{
		delete *it;
	}
}
C_StaticEntity* C_PhysicsManager::M_CreateStaticEntity(C_Entity* e)
{
	C_StaticEntity* re=new C_StaticEntity(m_World,e,m_ScaleFactor);
	m_Bodies.push_back(re);
	return re;
}
C_DynamicEntity* C_PhysicsManager::M_CreateDynamicEntity(C_Entity* e)
{
	C_DynamicEntity* re=new C_DynamicEntity(m_World,e,m_ScaleFactor);
	m_Bodies.push_back(re);
	return re;
}

void C_PhysicsManager::M_Simulate()
{
	m_World.Step(m_TimeStep, m_VelocityIterations, m_PositionIterations);
	for(std::vector<C_PhysicalEntity*>::iterator it=m_Bodies.begin(); it!=m_Bodies.end(); ++it)
	{
		(*it)->M_Sync();
		C_DynamicEntity* de = dynamic_cast<C_DynamicEntity*>(*it);
		if(de)
		{
			b2Body* b=de->M_Body();
			float a = b->GetAngle();
			b2Vec2 force = b2Vec2(-sin(a), cos(a));
			force*=4.0f;

			if(C_Singleton::M_InputHandler()->M_Get(LEFT))
			{
				b->SetAngularVelocity(1.0f);
			}
			else if(C_Singleton::M_InputHandler()->M_Get(RIGHT))
			{
				b->SetAngularVelocity(-1.0f);
			}
			else b->SetAngularVelocity(0.0f);

			if(C_Singleton::M_InputHandler()->M_Get(UP))
			{
				b->ApplyForceToCenter(force);
			}
		}
	}
}
