#include "Mario.h"

Mario::Mario() :GameObject()
{
	this->vx = 0.1f;
}

void Mario::Update(DWORD dt)
{
	x = x + vx * dt;
	if ((vx > 0 && x > 290) || (x < 0 && vx < 0))
	{
		vx = -vx;
	}
}

void Mario::Render()
{
	LPANIMATION ani;

	if (vx > 0)
	{
		ani = Animations::GetInstance()->Get(MARIO_GO_RIGHT);
	}
	else
	{
		ani = Animations::GetInstance()->Get(MARIO_GO_LEFT);
	}

	ani->Render(x, y);
}

Mario::~Mario()
{

}