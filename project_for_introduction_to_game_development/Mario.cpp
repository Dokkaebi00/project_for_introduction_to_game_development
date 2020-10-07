#include "Mario.h"

Mario::Mario(float x, float y, float vx, LPDIRECT3DTEXTURE9 texture) : GameObject(x, y, texture)
{
	this->vx = vx;
}

void Mario::Update(DWORD dt)
{
	x = x + vx*dt;
	int backBufferWidth = Game::GetInstance()->GetBackBufferWidth();

	if (x <= 0 || x >= backBufferWidth - MARIO_WIDTH)
	{
		vx = -vx;
		if (x <= 0)
		{
			x = 0;
		}
		if (x >= backBufferWidth - MARIO_WIDTH)
		{
			x = (float)(backBufferWidth - MARIO_WIDTH);
		}
	}
}
