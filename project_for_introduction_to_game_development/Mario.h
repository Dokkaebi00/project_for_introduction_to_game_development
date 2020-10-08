#pragma once
#include<Windows.h>
#include"Game.h"
#include"GameObject.h"

#define MARIO_WIDTH 14.0f
#define MARIO_VX 0.1f

class Mario : public GameObject
{
	float vx;

public:
	Mario(float x, float y, float vx, LPDIRECT3DTEXTURE9 texture);

	void Update(DWORD dt);
};

typedef Mario* LPMARIO;