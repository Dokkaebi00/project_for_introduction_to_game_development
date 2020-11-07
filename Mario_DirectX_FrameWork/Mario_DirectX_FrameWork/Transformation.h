#pragma once
#include<d3dx9.h>
#include<d3d9.h>

class Transformation
{
	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;
	float rotation;

public:
	Transformation (D3DXVECTOR2 position, D3DXVECTOR2 scale, float rotation)
	{
		this->position = position;
		this->scale = scale;
		this->rotation = rotation;
	}

	Transformation();

	D3DXVECTOR2 GetPosition();
	void SetPosition(D3DXVECTOR2 p);

	D3DXVECTOR2 GetScale();
	void SetScale(D3DXVECTOR2 s);

	float GetRotation();
	void SetRotation(float r);
};

