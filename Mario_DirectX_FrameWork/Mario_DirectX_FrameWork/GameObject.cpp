#include "GameObject.h"

D3DXVECTOR2 GameObject::GetPosition()
{
	return this->transform.position;
}

void GameObject::SetPosition(D3DXVECTOR2 p)
{
	this->transform.position = p;
}

float GameObject::GetX()
{
	return this->transform.position.x;
}

float GameObject::GetY()
{
	return this->transform.position.y;
}
