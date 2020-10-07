#include "GameObject.h"

void GameObject::Update(DWORD dt)
{
}

void GameObject::Render()
{
	Game::GetInstance()->Draw(x, y, texture);
}

void GameObject::SetPostion(float x, float y)
{
	this->x = x;
	this->y = y;
}

int GameObject::GetX()
{
	return this->x;
}

int GameObject::GetY()
{
	return this->y;
}

GameObject::GameObject(float x, float y, LPDIRECT3DTEXTURE9 texture)
{
	this->x = x;
	this->y = y;
	this->texture = texture;
}

GameObject::~GameObject()
{
	if (texture != NULL) texture->Release();
}
