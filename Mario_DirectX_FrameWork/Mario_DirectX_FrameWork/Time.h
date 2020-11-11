#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

class Time
{
public:
	static float dt;
	static float fixedDt;
	static float timeScale;

	float GetDt();
	void SetDt(float dt);

	float GetFixedDt();

	float GetTimeScale();
	void SetTimeScale(float timeScale);
};

