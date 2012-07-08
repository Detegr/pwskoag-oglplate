#pragma once
#include "entity.h"
#include <Box2D/Box2D.h>
#include <Box2D/Common/b2Math.h>

class C_PhysicalEntity
{
	protected:
		C_PhysicalEntity() : m_Body(NULL), m_Entity() {}
		b2Body* m_Body;
		C_Entity* m_Entity;
	public:
		b2Body* M_Body() { return m_Body; }
		virtual void M_Sync();
};

class C_StaticEntity : public C_PhysicalEntity
{
	friend class C_PhysicsManager;
	private:
		C_StaticEntity(b2World& w, C_Entity* e, float32 scalefactor);
};

class C_DynamicEntity : public C_PhysicalEntity
{
	friend class C_PhysicsManager;
	private:
		C_DynamicEntity(b2World& w, C_Entity* e, float32 scalefactor);
};
