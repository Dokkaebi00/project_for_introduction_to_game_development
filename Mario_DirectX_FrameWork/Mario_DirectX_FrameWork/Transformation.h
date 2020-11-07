#pragma once
#include<d3dx9.h>
#include<d3d9.h>

struct Transformation
{
	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;
	float rotation;

	Transformation Transform(D3DXVECTOR2 position, D3DXVECTOR2 scale, float rotation)
	{
		Transformation a;
		a.position = position;
		a.scale = scale;
		a.rotation = rotation;

		return a;
	}
};

