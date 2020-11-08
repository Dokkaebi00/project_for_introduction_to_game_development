#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

class Time
{
public:
	static float dt;

	float GetDt();
	void SetDt(float dt);
};

