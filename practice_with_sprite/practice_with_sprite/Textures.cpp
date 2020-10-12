#include "Textures.h"

Textures* Textures::__instance = NULL;

Textures::Textures()
{
}

void Textures::Add(int id, LPCWSTR filePath, D3DCOLOR transparentColor)
{
	textures[id] = Game::GetInstance()->LoadTexture(filePath);
}

LPDIRECT3DTEXTURE9 Textures::Get(int i)
{
	return textures[i];
}

Textures* Textures::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Textures();
	}
	return __instance;
}
