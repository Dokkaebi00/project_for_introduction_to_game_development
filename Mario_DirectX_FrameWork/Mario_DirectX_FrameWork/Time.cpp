#include "Time.h"

float Time::dt = 0;

float Time::GetDt()
{
	return this->dt;
}

void Time::SetDt(float dt)
{
	this->dt = dt;
}
