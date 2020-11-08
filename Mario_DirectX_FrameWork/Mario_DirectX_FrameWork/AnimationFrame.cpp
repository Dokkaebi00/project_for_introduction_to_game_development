#include "AnimationFrame.h"

AnimationFrame::AnimationFrame(LPSPRITE sprite, DWORD time, D3DXVECTOR2 position)
{
	this->sprite = sprite;
	this->time = time;
	this->localPosition = position;
}

LPSPRITE AnimationFrame::GetSprite()
{
	return this->sprite;
}

DWORD AnimationFrame::GetTime()
{
	return time;
}

AnimationFrame::~AnimationFrame()
{
}
