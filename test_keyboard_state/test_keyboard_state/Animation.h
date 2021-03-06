#pragma once

#include<vector>

#include"AnimationFrame.h"
#include"Sprites.h"

using namespace std;

class Animation
{
	DWORD lastFrameTime;
	int defaultTime;
	int currentFrame;
	vector<LPANIMATION_FRAME> frames;

public:
	Animation(int defaultTime);
	void Add(int spirteId, DWORD time = 0);
	void Render(float x, float y);
};

typedef Animation* LPANIMATION;

typedef vector<LPANIMATION> AnimationSet;

typedef AnimationSet* LPANIMATION_SET;