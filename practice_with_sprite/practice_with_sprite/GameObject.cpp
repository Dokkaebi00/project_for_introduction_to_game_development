#include "GameObject.h"

void GameObject::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void GameObject::SetState(int state)
{
	this->currentState = state;
}

GameObject::GameObject()
{
	this->x = 0;
	this->y = 0;
}

void GameObject::Update(DWORD dt)
{
}

void GameObject::Render()
{
	
}

GameObject::~GameObject()
{
}
