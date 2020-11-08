#pragma once

//dtype of RECT's component is LONG, it's not suit with the coordinate of the game (float)

class FloatRect
{
public:
	float left;
	float top;
	float right;
	float bottom;

	FloatRect();
	FloatRect(float left, float top, float right, float bottom);
};

