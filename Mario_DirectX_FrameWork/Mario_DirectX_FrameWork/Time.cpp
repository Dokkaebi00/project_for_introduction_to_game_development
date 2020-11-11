#include "Time.h"

float Time::dt = 0;
float Time::fixedDt = 0.02f;
float Time::timeScale = 1.0f;

float Time::GetDt()
{
	return this->dt;
}

void Time::SetDt(float dt)
{
	this->dt = dt;
}

float Time::GetFixedDt()
{
	return 0.02f;
}

float Time::GetTimeScale()
{
	return this->timeScale;
}

void Time::SetTimeScale(float timeScale)
{
	this->timeScale = timeScale;
}
