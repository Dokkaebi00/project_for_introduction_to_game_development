#pragma once

#include<Windows.h>
#include<d3dx9.h>
#include<vector>

#include"AnimationFrame.h"

using namespace std;

class Animation
{
	DWORD lastFrameTime;
	int currentFrame;
	int defaultTime;
	vector<LPANIMATION_FRAME> frames;

public:
	Animation(int defaultTime = 100);

	void Add(int spriteId, DWORD time = 0);

	void Render(float x, float y, int alpha = 255);
};

typedef Animation* LPANIMATION;

