#include "Sprite.h"

Sprite::Sprite(string id, int left, int top, int width, int height, int anchorPointX, int anchorPointY, LPDIRECT3DTEXTURE9 texture)
{
	this->id = id;
	this->left = left;
	this->top = top;
	this->width = width;
	this->height = height;
	this->right = this->left + this->width;
	this->bottom = this->top + this->height;
	this->anchorPointx = anchorPointX;
	this->anchorPointY = anchorPointY;
	this->texture = texture;
}

void Sprite::Draw(float x, float y, int alpha)
{
	Game* game = Game::GetInstance();

	game->Draw(x, y, this->anchorPointx, this->anchorPointY, this->texture, left, top, right, bottom, 255);
}
