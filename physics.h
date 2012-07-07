#pragma once
#include <Box2D/Box2D.h>
#include <Box2D/Common/b2Math.h>
#include <vector>
#include <iostream>
#include "entity.h"

class C_Physics
{
	private:
		static const float32 m_ScaleFactor = 10.0f;
		static const float32 m_TimeStep = 1.0f/60.0f;
		static const int32 m_VelocityIterations = 6; // 8
		static const int32 m_PositionIterations = 3; // 3
		b2World m_World;

		std::vector<b2Body*> m_Bodies;
	public:
		C_Physics();
		void M_CreateBody();
		void M_Simulate(C_Entity* e);
};
