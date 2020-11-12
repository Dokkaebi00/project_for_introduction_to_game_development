#include "Sprite.h"



Sprite::Sprite(string id, int xPivot, int left, int top, int width, int height, LPDIRECT3DTEXTURE9 texture)
{
	this->id = id;

	this->left = left;
	this->top = top;
	this->width = width;
	this->height = height;
	this->right = this->left + this->width;
	this->bottom = this->top + this->height;

	this->texture = texture;

	if (xPivot == -3)
	{
		this->anchorPointX = this->width * 0.5;
		this->anchorPointY = this->height * 0.5;
	}
	else
	{
		this->anchorPointX = xPivot;
		this->anchorPointY = this->height * 0.5;
	}
}

void Sprite::Draw(float x, float y, D3DXVECTOR2 flipD, float rotation, int alpha)
{
	Game* game = Game::GetInstance();

	RECT r;
	r.left = this->left;
	r.top = this->top;
	r.right = this->right;
	r.bottom = this->bottom;

	if (flipD.x < 0)
	{
		game->FlipDrawX(x, y, anchorPointX, anchorPointY, texture, r);
	}
	else if (flipD.y < 0)
	{
		game->FlipDrawY(x, y, anchorPointX, anchorPointY, texture, r);
	}
	else
	{
		game->Draw(x, y, anchorPointX, anchorPointY, texture, r);
	}
}

/*void Sprite::SetR(int left, int top, int right, int bottom)
{
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
	this->width = this->right - this->left;
	this->height = this->bottom - this->top;
}*/

RECT Sprite::GetRect()
{
	RECT r;
	r.left = this->left;
	r.top = this->top;
	r.right = this->right;
	r.bottom = this->bottom;

	return r;
}

D3DXVECTOR2 Sprite::GetAnchorPoint()
{
	return D3DXVECTOR2(this->anchorPointX, this->anchorPointY);
}

void Sprite::SetAnchorPoint(float x, float y)
{
	this->anchorPointX = x;
	this->anchorPointY = y;
}

void Sprite::SetWidth(int w)
{
	this->width = w;
}

int Sprite::GetWidth()
{
	return this->width;
}

void Sprite::SetHeight(int h)
{
	this->height = h;
}

int Sprite::GetHeight()
{
	return this->height;
}

Sprite::~Sprite()
{
}

void Sprite::SetR(int left, int top, int width, int height)
{
	this->left = left;
	this->top = top;
	this->width = width;
	this->height = height;
	this->right = this->left + width;
	this->bottom = this->top + height;
}