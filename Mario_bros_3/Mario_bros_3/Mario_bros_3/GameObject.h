#pragma once
#include "Debug.h"
#include"Textures.h"

using namespace std;

class GameObject;
typedef GameObject* LPGAMEOBJECT;

struct CollisionEvent;
typedef CollisionEvent* LPCOLLISIONEVENT;


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
protected:
	float x;
	float y;

	float dx;
	float dy;

	float vx;
	float vy;

	DWORD dt;

	Textures* texture;
	
	

public:
	GameObject();
	virtual ~GameObject();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);;
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void Render();
};

