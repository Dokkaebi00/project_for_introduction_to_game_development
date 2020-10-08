#pragma once

#include"Sprite.h"
#include<unordered_map>

using namespace std;

class Sprites
{
	static Sprites* __instance;

	unordered_map <int, LPSPRITE> sprites;

public:
	void Add(int  id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex);

	LPSPRITE Get(int id);

	static Sprites* GetInstance();
};

