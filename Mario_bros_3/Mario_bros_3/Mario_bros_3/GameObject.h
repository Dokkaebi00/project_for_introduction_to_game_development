#pragma once
#include"Debug.h"
#include"Textures.h"
#include"Animations.h"
#include"Camera.h"
#include"define.h"
#include"Game.h"

#include<vector>

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
 
class GameObject
{
protected:

	int direction;

	float posX;
	float posY;

	float dx;
	float dy;

	float vx;
	float vy;

	int state;

	int status;

	DWORD dt;

	Textures* texture;
	
	vector<LPANIMATION> animations;

public:
	GameObject();
	virtual ~GameObject();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) = 0;
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void Render(Camera* camera) = 0;

	void SetDirection(int d);
	int GetDirection();

	void SetPosition(float x, float y);
	void GetPosition(float& x, float& y);
	void GetSpeed(float& vx, float& vy);

	float GetX();
	float GetY();
	float GetVx();
	float GetVy();
	void SetX(float x);
	void SetY(float y);
	void SetVx(float VX);
	void SetVy(float VY);

	void RenderingBoudingBox(Camera* camera);
	LPCOLLISIONEVENT SweptAABBEx(GameObject* coO);
	void CalcPotentialCollisions(vector<GameObject*>* coObjects, vector<LPCOLLISIONEVENT>& coEvents);
	void FilterCollision
	(
		vector<LPCOLLISIONEVENT>& coEvents,
		vector<LPCOLLISIONEVENT>& coEventsResult,
		float& min_tx,
		float& min_ty,
		float& nx,
		float& ny
	);

};

