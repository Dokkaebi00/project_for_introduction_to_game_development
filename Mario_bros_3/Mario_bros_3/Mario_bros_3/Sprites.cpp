#include "Sprites.h"


Sprites* Sprites::__instance = NULL;

void Sprites::Add(int id, int left, int top, int width, int height, LPDIRECT3DTEXTURE9 tex)
{
	LPSPRITE s = new Sprite(id, left, top, width, height, tex);
	sprites[id] = s;

	OutputDebugString(L"Add Sprite OK");
}

LPSPRITE Sprites::Get(int id)
{
	return sprites[id];
}

void Sprites::Clear()
{
	for (auto x : sprites)
	{
		LPSPRITE s = x.second;
		delete s;
	}

	sprites.clear();
}

Sprites* Sprites::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Sprites();
	}
	return __instance;
}
