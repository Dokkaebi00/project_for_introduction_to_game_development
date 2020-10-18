#include "GameObject.h"

void GameObject::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void GameObject::GetPosition(float& x, float& y)
{
	x = this->x;
	y = this->y;
}

void GameObject::SetSpeed(float vx, float vy)
{
	this->vx = vx;
	this->vy = vy;
}

void GameObject::GetSpeed(float& vx, float& vy)
{
}

void GameObject::SetState(int state)
{
	this->state = state;
}

int GameObject::GetState()
{
	return this->state;
}

void GameObject::AddAnimation(int aniId)
{
	LPANIMATION ani = Animations::GetInstance()->Get(aniId);
	animations.push_back(ani);
}

GameObject::GameObject()
{
	x = y = 0;
	vx = vy = 0;
	nx = 1;
}

void GameObject::Update(DWORD dt)
{
	x = x + vx * dt;
	y = y + vy * dt;
}

void GameObject::Render()
{
}

GameObject::~GameObject()
{
}
