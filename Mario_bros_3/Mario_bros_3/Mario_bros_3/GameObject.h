#pragma once
#include "Debug.h"

using namespace std;

struct CollisionEvent
{
	LPGAMEOBJECT obj;
	float t;
	float nx;
	float ny;
	CollisionEvent(float t, float nx, float ny, LPGAMEOBJECT obj = NULL)
	{
		this->t = t;
		this->nx = nx;
		this->ny = ny;
		this->obj = obj;
	}

	static bool compare(const LPCOLLISIONEVENT& a, LPCOLLISIONEVENT& b)
	{
		return a->t < b->t;
	}
};
typedef CollisionEvent* LPCOLLISIONEVENT;

class GameObject
{
	float x;
	float y;

	float dx;
	float dy;

	float vx;
	float vy;

	DWORD dt;

};
typedef GameObject* LPGAMEOBJECT;
