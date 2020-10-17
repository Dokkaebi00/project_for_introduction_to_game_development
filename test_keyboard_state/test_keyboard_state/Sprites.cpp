#include "Sprites.h"


Sprites* Sprites::__instance = NULL;

void Sprites::Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 texture)
{
	LPSPRITE sprite = new Sprite(id, left, top, right, bottom, texture);

	sprites[id] = sprite;
}

LPSPRITE Sprites::Get(int id)
{
	return sprites[id];
}

Sprites* Sprites::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Sprites();
	}
	return __instance;
}
