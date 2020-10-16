#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

#include"Textures.h"
#include"Game.h"

class Sprite
{
	int id;

	int left;
	int top;
	int right;
	int bottom;

	LPDIRECT3DTEXTURE9 texture;

public:
	Sprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 texture);

	void Draw(float x, float y);
};

typedef Sprite* LPSPRITE;