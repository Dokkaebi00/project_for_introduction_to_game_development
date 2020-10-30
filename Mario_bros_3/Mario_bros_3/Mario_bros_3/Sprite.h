#pragma once

#include<Windows.h>
#include<d3dx9.h>

#include"Game.h"

class Sprite
{
	int id;

	int left;
	int top;
	int width;
	int height;

	LPDIRECT3DTEXTURE9 texture;

public:
	Sprite(int id, int left, int top, int width, int height, LPDIRECT3DTEXTURE9 tex);

	void Draw(float x, float y, int alpha = 255);
};

typedef Sprite* LPSPRITE;

