#include <Windows.h>

#include <d3d9.h>
#include <d3dx9.h>

#include "Sprites.h"
#include "Game.h"

Sprites* Sprites:: __instance = NULL;

void Sprites::Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex)
{
	LPSPRITE s = new Sprite(id, left, top, right, bottom, tex);

	sprites[id] = s;
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
