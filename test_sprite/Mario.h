#pragma once

#include"GameObject.h"
#include"Game.h"
#include<d3dx9.h>

#define MARIO_GO_LEFT 2
#define MARIO_GO_RIGHT 1

class Mario : public GameObject
{
	float vx;
public:
	void Update(DWORD dt);
	void Render();
	Mario();
	~Mario();
};

