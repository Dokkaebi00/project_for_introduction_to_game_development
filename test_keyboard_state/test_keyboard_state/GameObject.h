#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<vector>

#include"Animation.h"
#include"Animations.h"

using namespace std;

class GameObject
{
protected:

	float x;
	float y;

	float vx;
	float vy;

	int nx;

	int state;

	static vector<LPANIMATION> animations;
};

