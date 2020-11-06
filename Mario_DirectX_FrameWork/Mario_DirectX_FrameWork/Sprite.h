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
	
	float anchorPointX;
	float anchorPointY;
	
	string id;

	LPDIRECT3DTEXTURE9 texture;

public:
	Sprite(string id, int xPivot, int left, int top, int width, int height, LPDIRECT3DTEXTURE9 texture);
	void Draw(float x, float y, D3DXVECTOR2 flipD, float rotation, int alpha = 255);

	//void SetR(int left, int top, int right, int bottom);
	void SetR(int left, int top, int width, int height);
	RECT GetRect();

	D3DXVECTOR2 GetAnchorPoint();
	void SetAnchorPoint(float x, float y);

	void SetWidth(int w);
	int GetWidth();

	void SetHeight(int h);
	int GetHeight();

	~Sprite();
};
typedef Sprite* LPSPRITE;
