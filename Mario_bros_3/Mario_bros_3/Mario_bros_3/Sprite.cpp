#include "Sprite.h"

Sprite::Sprite(int id, int left, int top, int width, int height, LPDIRECT3DTEXTURE9 tex)
{
	this->id = id;
	this->left = left;
	this->top = top;
	this->width = width;
	this->height = height;
	this->texture = tex;
}

void Sprite::Draw(float x, float y, int alpha)
{
	Game* game = Game::GetInstance();
	int right = left + width;
	int bottom = top + height;
	game->Draw(x, y, texture, left, top, right, bottom, alpha);
}
