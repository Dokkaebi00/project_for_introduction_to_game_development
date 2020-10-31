#include "Animations.h"

Animations* Animations::__instance = NULL;

void Animations::Add(int id, LPANIMATION ani)
{
	animations[id] = ani;
}

LPANIMATION Animations::Get(int id)
{
	LPANIMATION ani = animations[id];
	if (ani == NULL)
	{
		OutputDebugString(L"Error, can not find animation from id");
	}
	return ani;
}

void Animations::Clear()
{
	for (auto x : animations)
	{
		LPANIMATION ani = x.second;
		delete ani;
	}

	animations.clear();
}

Animations* Animations::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Animations();
	}
	return __instance;
}
