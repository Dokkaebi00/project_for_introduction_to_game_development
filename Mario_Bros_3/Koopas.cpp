#include "Koopas.h"

Koopas::Koopas()
{
	SetState(KOOPAS_STATE_WALKING);
}

void Koopas::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + KOOPAS_BBOX_WIDTH;

	if (state == KOOPAS_STATE_DIE)
		bottom = y + KOOPAS_BBOX_HEIGHT_DIE;
	else
		bottom = y + KOOPAS_BBOX_HEIGHT;
}

void Koopas::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	GameObject::Update(dt, coObjects);


	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventResult;

	coEvents.clear();


	//vy += KOOPAS_GRAVITY * dt;

	if (state == KOOPAS_STATE_WALKING)
	{
		/*x += dx;
		y += dy;*/

		if (vx < 0 && x < 0) {
			x = 0; vx = -vx;
		}

		if (vx > 0 && x > 290) {
			x = 290; vx = -vx;
		}
	}

	if (state == KOOPAS_STATE_DIE_MOVING_RIGHT || state == KOOPAS_STATE_DIE_MOVING_LEFT)
	{
		/*x += dx;
		y += dy;*/

		if (vx < 0 && x < 0) {
			x = 0; vx = -vx;
		}

		if (vx > 0 && x > 290) {
			x = 290; vx = -vx;
		}
	}

	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;
		float rdx = 0;
		float rdy = 0;
		FilterCollision(coEvents, coEventResult, min_tx, min_ty, nx, ny, rdx, rdy);

		x += min_tx * dx + nx * 0.4f;
		y += min_ty * dy + ny * 0.4f;

		if (nx != 0) vx = 0;
		if (ny != 0) vy = 0;

		for (UINT i = 0; i < coEventResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventResult[i];
			
			if (dynamic_cast<Mario*>(e->obj))
			{
				Mario* mario = dynamic_cast<Mario*>(e->obj);

				if (state == KOOPAS_STATE_DIE)
				{
					if (e->nx > 0)
					{
						//SetState(KOOPAS_STATE_DIE_MOVING);
						//DebugOut(L"[INFO] Koopas Speed: %d\n", vx);
					}
				}
			}
		}
	}

	//
	// TO-DO: make sure Koopas can interact with the world and to each of them too!
	// 
	

}

void Koopas::Render()
{
	int ani = KOOPAS_ANI_WALKING_LEFT;
	if (state == KOOPAS_STATE_DIE) 
	{
		ani = KOOPAS_ANI_DIE;
	}

	if (state == KOOPAS_STATE_DIE_MOVING_RIGHT)
	{
		ani = KOOPAS_ANI_DIE;
	}

	if (state == KOOPAS_STATE_DIE_MOVING_LEFT)
	{
		ani = KOOPAS_ANI_DIE;
	}

	if (state == KOOPAS_STATE_WALKING)
	{
		if (vx > 0)
		{
			ani = KOOPAS_ANI_WALKING_RIGHT;
		}
		else if (vx <= 0)  
		{
			ani = KOOPAS_ANI_WALKING_LEFT;
		}
	}

	animation_set->at(ani)->Render(x, y);

	RenderBoundingBox();
}

void Koopas::SetState(int state)
{
	GameObject::SetState(state);
	switch (state)
	{
	case KOOPAS_STATE_DIE:
		y += KOOPAS_BBOX_HEIGHT - KOOPAS_BBOX_HEIGHT_DIE + 1;
		vx = 0;
		vy = 0;
		break;
	case KOOPAS_STATE_DIE_MOVING_RIGHT:
		vx = 0.4f;
		break;
	case KOOPAS_STATE_DIE_MOVING_LEFT:
		vx = -0.4f;
		break;
	case KOOPAS_STATE_WALKING:
		vx = KOOPAS_WALKING_SPEED;
		break;
	}

}