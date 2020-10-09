#pragma once

#include<Windows.h>
#include<d3dx9.h>
#include<vector>

#include"Sprites.h"
#include"Animation.h"
#include"Animations.h"
#include"AnimationFrame.h"

using namespace std;

class GameObject
{
protected:	
	float x;
	float y;

	int currentState;

	vector<LPANIMATION> animations;

public:
	void SetPosition(float x, float y);
	void SetState(int state);

	GameObject();

	virtual void Update(DWORD dt);
	virtual void Render();
	~GameObject();
};

