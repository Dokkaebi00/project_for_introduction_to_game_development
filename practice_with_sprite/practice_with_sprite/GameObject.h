#pragma once

#include<Windows.h>
#include<d3dx9.h>
#include<d3d9.h>

#include"Sprite.h"
#include"Sprites.h"
#include"Textures.h"
#include"Animations.h"

class GameObject
{
protected:
	float x;
	float y;

	int currentState;

	vector<LPANIMATION> animations;

public:
	void SetPosition(float x, float y);
	void SetState(int state);

	GameObject();

	virtual void Update(DWORD dt);
	virtual void Render();

	~GameObject();
};

