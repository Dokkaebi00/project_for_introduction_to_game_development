#pragma once

#include <vector>
#include <d3dx9.h>

#include "Define.h"

using namespace std;

struct Physic
{
	D3DXVECTOR2 Bounce;
	float Fric;
	vector<ObjectType> PhysicObject;



	Physic(D3DXVECTOR2 bounce, float fric)
	{
		this->Bounce = bounce;
		this->Fric = fric;
	}

	void AddPhysicObject(ObjectType ob)
	{
		PhysicObject.push_back(ob);
	}
};

class PhysicCollision
{
};

