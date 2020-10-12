#pragma once

#include"GameObject.h"

#define MARIO_GO_LEFT 0
#define MARIO_GO_RIGHT 1

class Mario : public GameObject
{
protected:
	float vx;
public:
	Mario();
	void Update(DWORD dt);
	void Render();

	~Mario();
};

