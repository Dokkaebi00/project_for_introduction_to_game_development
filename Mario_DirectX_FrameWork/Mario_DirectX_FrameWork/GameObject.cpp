#include "GameObject.h"

D3DXVECTOR2 GameObject::GetPosition()
{
	return this->transform.GetPosition();
}

void GameObject::SetPosition(D3DXVECTOR2 p)
{
	this->transform.SetPosition(p);
}

float GameObject::GetX()
{
	return this->transform.GetPosition().x;
}

float GameObject::GetY()
{
	return this->transform.GetPosition().y;
}
