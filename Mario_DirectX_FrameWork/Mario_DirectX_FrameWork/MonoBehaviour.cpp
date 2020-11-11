#include "MonoBehaviour.h"

void MonoBehaviour::Awake()
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
    return this->time.GetDt();
}

void MonoBehaviour::SetDt(float dt)
{
    this->time.SetDt(dt);
}

float MonoBehaviour::GetFixedDt()
{
    return this->GetFixedDt();
}

float MonoBehaviour::GetTimeScale()
{
    return this->time.GetTimeScale();
}

void MonoBehaviour::SetTimeScale(float ts)
{
    this->time.SetTimeScale(ts);
}

/*void MonoBehaviour::SetFixedDt(float dt)
{
}*/



