#include "MonoBehaviour.h"

float MonoBehaviour::GetDeltaTime()
{
    return this->dt;
}

void MonoBehaviour::SetDeltaTime(float dt)
{
    this->dt = dt;
}
