#pragma once

#include<d3d9.h>
#include<d3dx9.h>

#include"Utils.h"
#include"Game.h"

class Sprite
{
	//position of the sprite on the texture file
	int left;
	int top;
	int right;
	int bottom;

	//width, height of the sprite
	int width;
	int height;
	
	//use this for flip, rotation, localPosition, ...
	float anchorPointX;
	float anchorPointY;
	
	//id of the sprite in the database
	string id;

	//texture, where the sprite locates on
	LPDIRECT3DTEXTURE9 texture;

public:
	Sprite(string id, int xPivot, int left, int top, int width, int height, LPDIRECT3DTEXTURE9 texture);

	//Draw function
	void Draw(float x, float y, D3DXVECTOR2 flipD, float rotation, int alpha = 255);

	//void SetR(int left, int top, int right, int bottom);
	void SetR(int left, int top, int width, int height);
	RECT GetRect();

	//Get anchorpoint, use for flipping, rotation, ...
	D3DXVECTOR2 GetAnchorPoint();
	void SetAnchorPoint(float x, float y);

	void SetWidth(int w);
	int GetWidth();

	void SetHeight(int h);
	int GetHeight();

	~Sprite();
};
typedef Sprite* LPSPRITE;
