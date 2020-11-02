#include "GameObject.h"

GameObject::GameObject()
{
	posX = posY = 0;
	vx = vy = 0;
	direction = 1;
}

GameObject::~GameObject()
{
}

void GameObject::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	this->dt = dt;
	dx = vx * dt;
	dy = vy * dt;
}

void GameObject::SetDirection(int d)
{
	direction = d;
}

int GameObject::GetDirection()
{
	return direction;
}

void GameObject::SetPosition(float x, float y)
{
	posX = x;
	posY = y;
}

void GameObject::GetPosition(float& x, float& y)
{
	x = posX;
	y = posY;
}

void GameObject::GetSpeed(float& VX, float& VY)
{
	VX = vx;
	VY = vy;
}

float GameObject::GetX()
{
	return posX;
}

float GameObject::GetY()
{
	return posY;
}

float GameObject::GetVx()
{
	return vx;
}

float GameObject::GetVy()
{
	return vy;
}

void GameObject::SetX(float x)
{
	posX = x;
}

void GameObject::SetY(float y)
{
	posY = y;
}

void GameObject::SetVx(float VX)
{
	vx = VX;
}

void GameObject::SetVy(float VY)
{
	vy = VY;
}

//void GameObject::RenderingBoudingBox(Camera* camera)
//{
//	float l, t, r, b;
//
//	GetBoundingBox(l, t, r, b);
//	
//	RECT rect;
//	rect.left = 0;
//	rect.right = 0;
//	rect.top = (LONG)r - (LONG)l;
//	rect.bottom = (LONG)b - (LONG)t;
//
//	D3DXVECTOR2 pos = camera->Transform(l, r);
//
//	Game::GetInstance()->Draw(
//		pos.x,
//		pos.y,
//		Textures::GetInstance()->Get(eType::BBOX),
//		rect.left,
//		rect.right,
//		rect.bottom,
//		100
//	);
//}
