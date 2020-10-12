#include "Mario.h"

Mario::Mario():GameObject()
{
	this->vx = 0.1f;
}

void Mario::Update(DWORD dt)
{
	x += vx * dt;
	if ((vx > 0 && x > 400) || (x < 0 && vx < 0)) vx = -vx;
}

void Mario::Render()
{
	LPANIMATION ani;
	if (vx > 0)
	{
		ani = Animations::GetInstance()->Get(MARIO_GO_LEFT);

	}
	else
	{
		ani = Animations::GetInstance()->Get(MARIO_GO_RIGHT);
	}

	ani->Render(x, y);
}

Mario::~Mario()
{
}

