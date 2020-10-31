#include "AnimationFrame.h"

AnimationFrame::AnimationFrame(LPSPRITE sprite, int time)
{
	this->sprite = sprite;
	this->time = time;
}

DWORD AnimationFrame::GetTime()
{
	return time;
}

LPSPRITE AnimationFrame::GetSprite()
{
	return sprite;
}
