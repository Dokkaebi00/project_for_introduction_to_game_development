#include "Sprite.h"

Sprite::Sprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 texture)
{
	this->id = id;
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
	this->texture = texture;
}

void Sprite::Draw(float x, float y)
{
	Game* game = Game::GetInstance();
	game->Draw(x, y, this->texture, this->left, this->top, this->right, this->bottom);
}
