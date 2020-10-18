#pragma once
#include "GameObject.h"

//thong so vat ly co ban cua mario (update them)
#define MARIO_WALKING_SPEED		0.1f
#define MARIO_JUMP_SPEED_Y		0.5f
#define MARIO_GRAVITY			0.1f

// cac trang thai co ban cua mario
#define MARIO_STATE_IDLE			0
#define MARIO_STATE_WALKING_RIGHT	100
#define MARIO_STATE_WALKING_LEFT	200
#define MARIO_STATE_JUMP			300

//cac trang thai rieng danh cho mario lon
#define MARIO_STATE_SIT 400
#define MARIO_STATE_HIT_TAIL 500
#define MARIO_STATE_SHOOT_FIRE	600

//animation cua mario nho
#define MARIO_ANI_IDLE_RIGHT		0
#define MARIO_ANI_IDLE_LEFT			1
#define MARIO_ANI_WALKING_RIGHT		2
#define MARIO_ANI_WALKING_LEFT		3
#define MARIO_ANI_JUMP_RIGHT 4
#define MARIO_ANI_JUMP_LEFT 5

//animation cua mario lon
#define MARIO_BIG_ANI_IDLE_RIGHT 6
#define MARIO_BIG_ANI_IDLE_LEFT 7
#define MARIO_BIG_ANI_WALKING_RIGHT 8
#define MARIO_BIG_ANI_WALKING_LEFT 9
#define MARIO_BIG_ANI_JUMP_RIGHT 10
#define MARIO_BIG_ANI_JUMP_LEFT 11
#define MARIO_BIG_ANI_SIT_RIGHT 12
#define MARIO_BIG_ANI_SIT_LEFT 13

//animation tan cong cua mario racoon
#define MARIO_RACOON_ANI_IDLE_RIGHT 14
#define MARIO_RACOON_ANI_IDLE_LEFT 15
#define MARIO_RACOON_ANI_WALKING_RIGHT 16
#define MARIO_RACOON_ANI_WALKING_LEFT 17
#define MARIO_RACOON_ANI_JUMP_RIGHT 18
#define MARIO_RACOON_ANI_JUMP_LEFT 19
#define MARIO_RACOON_ANI_SIT_RIGHT 20
#define MARIO_RACOON_ANI_SIT_LEFT 21
#define MARIO_RACOON_ANI_HIT_TAIL_RIGHT 22
#define MARIO_RACOON_ANI_HIT_TAIL_LEFT 23

//animation ban lua cua mario lua
#define MARIO_FIRE_ANI_IDLE_RIGHT 24
#define MARIO_FIRE_ANI_IDLE_LEFT 25
#define MARIO_FIRE_ANI_WALKING_RIGHT 26
#define MARIO_FIRE_ANI_WALKING_LEFT 27
#define MARIO_FIRE_ANI_JUMP_RIGHT 28
#define MARIO_FIRE_ANI_JUMP_LEFT 29
#define MARIO_FIRE_ANI_SIT_RIGHT 30
#define MARIO_FIRE_ANI_SIT_LEFT 31
#define MARIO_FIRE_ANI_SHOOT_RIGHT 32
#define MARIO_FIRE_ANI_SHOOT_LEFT 33

//cac cap do cua mario
#define MARIO_LEVEL_SMALL 1
#define MARIO_LEVEL_BIG 2
#define MARIO_LEVEL_RACOON 3
#define MARIO_LEVEL_FIRE 4
#define MARIO_LEVEL_STAR 5



class CMario : public CGameObject
{
	int level;
public: 

	void Update(DWORD dt);
	void Render();
	void SetLevel(int level);
	int GetLevel();
	void SetState(int state);
	CMario();
};