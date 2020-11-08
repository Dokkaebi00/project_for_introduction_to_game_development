#include "MonoBehaviour.h"

void MonoBehaviour::Awake()
{
}

void MonoBehaviour::Update()
{
}

void MonoBehaviour::Render()
{
}

Time MonoBehaviour::GetDt()
{
    return this->dt;
}

void MonoBehaviour::SetDt(float dt)
{
    this->dt.SetDt(dt);
}


