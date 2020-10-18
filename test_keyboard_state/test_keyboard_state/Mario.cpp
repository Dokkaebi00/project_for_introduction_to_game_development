#include "Mario.h"

void Mario::Update(DWORD dt)
{
	GameObject::Update(dt);

	vy += MARIO_GRAVITY;

	if (y > 100)
	{
		vy = 0; 
		y = 100.0f;
	}

}

void Mario::Render()
{
	int ani = -1;
	if (state == MARIO_DIE_STATE)
	{
		ani = MARIO_SMALL_DIE;
	}
	else
	{
		if (state == MARIO_SMALL_STATE)
		{
			if (vx == 0)
			{
				if (nx > 0)
				{
					ani = MARIO_SMALL_STATE_IDLE_RIGHT;
				}
				else
				{
					ani = MARIO_SMALL_STATE_IDLE_LEFT;
				}
			}
		}
	}
}

void Mario::SetState(int state)
{
	GameObject::SetState(state);
	switch (state)
	{
		case
	}
}
