#include "Animations.h"

Animations* Animations::__instance = NULL;

void Animations::Add(int id, LPANIMATION ani)
{
	animations[id] = ani;
}

LPANIMATION Animations::Get(int id)
{
	return animations[id];
}

Animations* Animations::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Animations();
	}
	return __instance;
}
