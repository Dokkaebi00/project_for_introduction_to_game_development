#pragma once

#include<Windows.h>
#include<d3dx9.h>
#include<unordered_map>

class Sprite
{
	int id;
	
	int left;
	int top;
	int right;
	int bottom;

	LPDIRECT3DTEXTURE9 texture;

public:
	Sprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex);
	
	void Draw(float x, float y);
};

typedef Sprite* LPSRITE;