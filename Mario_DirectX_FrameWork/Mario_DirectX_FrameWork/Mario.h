#pragma once

#include<vector>

#include"GameObject.h"
#include"KeyboardProcessing.h"

using namespace std;

#define MARIO_IDLE "IDLE"
#define MARIO_WALK "WALK"
#define MARIO_RUN "RUN"
#define MARIO_ATTACK "ATTACK"
#define MARIO_SIT "SIT"
#define	MARIO_SKID "SKID"
#define MARIO_KICK "KICK"
#define MARIO_JUMP "JUMP"

#define MARIO_SMALL_LEVEL "SMALL"
#define MARIO_BIG_LEVEL "BIG"
#define MARIO_FIRE_LEVEL "FIRE"
#define MARIO_RACOON_LEVEL "RACOON"
#define MARIO_STAR_LEVEL "STAR"

class Mario : public GameObject
{
protected:
	string mario_level;
	string mario_state;

	bool OnGround;
	bool OnAir;

public:
	Mario();

	void Update(Time time, Camera* camera);
	void Render(Camera* cam);

	void OnCollisionEnter(vector<LPCOLLISIONBOX> others);

	void CrouchButton(LPKeyboardProcessing keyboard);

	void Skid(float vx);

	void HoldButton();
	void HoldKoopasShell();

	void Jump();

	void Kick();

	void KeyState();
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);

	

};

