#include "Transformation.h"

Transformation::Transformation()
{
    this->position = D3DXVECTOR2(0.0f, 0.0f);
    this->scale = D3DXVECTOR2(1.0f, 1.0f);
    this->rotation = 0.0f;
}

D3DXVECTOR2 Transformation::GetPosition()
{
    return this->position;
}

void Transformation::SetPosition(D3DXVECTOR2 p)
{
    this->position = p;
}

D3DXVECTOR2 Transformation::GetScale()
{
    return this->scale;
}

void Transformation::SetScale(D3DXVECTOR2 s)
{
    this->scale = s;
}

float Transformation::GetRotation()
{
    return this->rotation;
}

void Transformation::SetRotation(float r)
{
    this->rotation = r;
}
