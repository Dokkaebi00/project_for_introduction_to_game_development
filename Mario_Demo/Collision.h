#pragma once

#include<d3dx9.h>
#include<d3d9.h>
#include<Windows.h>

#include "GameObject.h"


class Collision;
typedef Collision* LPCollision;

struct CollisionEvent;
typedef CollisionEvent* LPCollisionEvent;

struct BoundingBox
{
	float left;
	float top;
	float right;
	float bottom;

	bool Overlapped(const BoundingBox& otherBox)
	{
		if (this->left <= otherBox.left)
		{
			if (this->top <= otherBox.top)
			{
				if (this->right >= otherBox.right)
				{
					if (this->bottom >= otherBox.bottom)
					{
						return true;
					}
				}
			}
		}
	}

	bool Collide(const BoundingBox& otherBox)
	{
		if (this->left <= otherBox.right)
		{
			if (this->top <= otherBox.bottom)
			{
				if (this->right >= otherBox.left)
				{
					if (this->bottom >= otherBox.top)
					{
						return true;
					}
				}
			}
		}
	}

};

struct CollisionEvent
{
	LPCollision collision;
	D3DXVECTOR2 direction;
	float time;

	CollisionEvent(float time, D3DXVECTOR2 direction, LPCollision collision)
	{
		this->time = time;
		this->direction = direction;
		this->collision = collision;
	}

	static bool compare(const LPCollisionEvent& a, const LPCollisionEvent& b)
	{
		return a->time < b->time;
	}
};

class Collision
{
protected:

};

