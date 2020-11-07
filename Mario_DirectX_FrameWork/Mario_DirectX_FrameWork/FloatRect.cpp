#include "FloatRect.h"

FloatRect::FloatRect()
{
	this->left = 0;
	this->top = 0;
	this->right = 0;
	this->bottom = 0;
}

FloatRect::FloatRect(float left, float top, float right, float bottom)
{
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
}
