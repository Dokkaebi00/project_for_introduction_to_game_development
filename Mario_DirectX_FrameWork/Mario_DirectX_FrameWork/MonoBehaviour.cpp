#include "MonoBehaviour.h"

float MonoBehaviour::dt = 0;
float MonoBehaviour::fixeddt = 0.02;
float MonoBehaviour::timeScale = 1.0f;

void MonoBehaviour::Awake()
{
}

void MonoBehaviour::Start()
{
}

void MonoBehaviour::Update()
{
}

void MonoBehaviour::FixedUpdate()
{
}

void MonoBehaviour::LateUpdate()
{
}

void MonoBehaviour::Render()
{
}

float MonoBehaviour::GetDt()
{
    return this->dt;
}

void MonoBehaviour::SetDt(float dt)
{
    this->dt = dt;
}

float MonoBehaviour::GetFixedDt()
{
    return this->fixeddt;
}

float MonoBehaviour::GetTimeScale()
{
    return this->timeScale;
}

void MonoBehaviour::SetTimeScale(float ts)
{
    this->timeScale = ts;
}

/*
void MonoBehaviour::SetTimeScale(float ts)
{
    this->time.timeScale = ts;
}
*/

/*void MonoBehaviour::SetFixedDt(float dt)
{
}*/



