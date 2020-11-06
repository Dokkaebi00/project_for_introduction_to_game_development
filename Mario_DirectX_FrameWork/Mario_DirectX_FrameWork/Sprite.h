#pragma once

#include<d3d9.h>
#include<d3dx9.h>

#include"Utils.h"
#include"Game.h"

class Sprite
{
	int left;
	int top;
	int right;
	int bottom;
	int width;
	int height;
	int anchorPointx;
	int anchorPointY;
	string id;

	LPDIRECT3DTEXTURE9 texture;

public:
	Sprite(string id, int left, int top, int width, int height, int anchorPointX, int anchorPointY, LPDIRECT3DTEXTURE9 texture);
	void Draw(float x, float y, int alpha = 255);
};

