#pragma once

#include "GameObject.h"
#include "Camera.h"
#include "FloatRect.h"
#include "Game.h"

#include <d3d9.h>
#include <d3dx9.h>
#include <vector>

using namespace std;

struct CollisionEvent;
typedef CollisionEvent* LPCOLLISIONEVENT;

class CollisionBBox;
typedef CollisionBBox* LPCOLLISIONBOX;

struct CollisionEvent
{
	LPCOLLISIONBOX obj;
	float t, nx, ny;

	float dx, dy;		// *RELATIVE* movement distance between this object and obj

	CollisionEvent(float t, float nx, float ny, float dx = 0, float dy = 0, LPCOLLISIONBOX obj = NULL)
	{
		this->t = t;
		this->nx = nx;
		this->ny = ny;
		this->dx = dx;
		this->dy = dy;
		this->obj = obj;
	}

	static bool compare(const LPCOLLISIONEVENT& a, LPCOLLISIONEVENT& b)
	{
		return a->t < b->t;
	}
};

class CollisionBBox : public MonoBehaviour
{
	//the gameobj attach with the box;
	LPGAMEOBJECT gameObj;

	//local position and transformation
	//the position which center of the coordinate is gameobj
	Transformation localTransformation;
	D3DXVECTOR2 localPosition;

	//left, top, right, bottom of the box
	FloatRect Box;

	//size of the collision box
	float width;
	float height;

	//isActive (use it to process the collision of the enemy when it die)
	bool isActive;

	bool isTrigger;

	// velocity of the collision (and of the gameobj too)
	D3DXVECTOR2 v; //vx, vy
	float vx;
	float vy;

	float dx;
	float dy;

	float acceleration;

	//graviy of the collision (use for mario, mushroom, koopas, ...)
	float gravity;
	//some obj doesnt have gravity but have physics collision such as question brick
	bool isUseGravity;

	//use for mario
	float drag;
	//use for Mario

	//use to define which collision is dynamic, which collision is static
	bool Dynamic;

	D3DXVECTOR2 direction;
	//direction.x = -1 ->left
	//direction.x = 1 ->right
	//direction.y = -1 -> up
	//direction.y = 1 ->right

	
public:
	CollisionBBox();

	virtual void Awake();

	virtual void Update();

	virtual void FixedUpdate(vector<LPCOLLISIONBOX>* coObject); 

	virtual void Render(Camera* camera);

	bool CheckAABB(FloatRect b2);

	static void SweptAABB(
		float ml,			// move left 
		float mt,			// move top
		float mr,			// move right 
		float mb,			// move bottom
		float dx,			// 
		float dy,			// 
		float sl,			// static left
		float st,
		float sr,
		float sb,
		float& t,
		float& nx,
		float& ny);

	LPCOLLISIONEVENT SweptAABBEx(LPCOLLISIONBOX other);
	void CalcPotentialCollisions(vector<LPCOLLISIONBOX>* coObjects, vector<LPCOLLISIONEVENT>& coEvents);
	void FilterCollision(
		vector<LPCOLLISIONEVENT>& coEvents,
		vector<LPCOLLISIONEVENT>& coEventsResult,
		float& min_tx,
		float& min_ty,
		float& nx,
		float& ny);

	void SetGameObject(LPGAMEOBJECT gameobj);
	LPGAMEOBJECT GetGameObject();

	void SetCollisionBoxSize(float width, float height);
	void SetCollisionBoxSize(float& width, float& height);
	
	float GetWidth();
	void SetWidth(float width);

	float GetHeight();
	void SetHeight(float height);

	Transformation GetTransformation();
	void SetTransformation(Transformation transform);

	D3DXVECTOR2 GetLocalLocation();
	void SetLocalLocation(D3DXVECTOR2 p);

	D3DXVECTOR2 GetLocalScale();
	void SetLocalScale(D3DXVECTOR2 s);

	float GetLocalRotation();
	void SetLocalRotation(float r);

	FloatRect GetRect();
	//void SetRect(FloatRect r);

	bool Active();
	void SetActive(bool active);

	float GetVx();
	void SetVx(float vx);

	float GetDx();
	void SetDx(float dx);

	float GetDy();
	void GetDy(float dy);

	float GetVy();
	void SetVy(float vy);

	float GetAcceleration();
	void SetAcceleration(float a);

	float GetGravity();
	void SetGravity(float g);

	bool Gravity();
	void UseGravity(bool gravity);

	float DragForce();
	void SetDragForce(float dragforce);

	bool isDynamic();
	void SetDynamic(bool dynamic);

	void SetTrigger(bool trigger);
	bool GetTrigger();

	//because the position of the properties is just local, we need to get the position of the bb in world game for some calculate
	D3DXVECTOR2 GetPositionInGame();
};

