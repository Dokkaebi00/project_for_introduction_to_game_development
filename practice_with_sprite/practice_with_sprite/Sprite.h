#pragma once
#include"Textures.h"

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

