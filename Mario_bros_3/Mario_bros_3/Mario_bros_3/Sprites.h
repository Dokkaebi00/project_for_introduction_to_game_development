#pragma once

#include<Windows.h>
#include<d3dx9.h>
#include<unordered_map>

#include"Sprite.h"

using namespace std;

class Sprites
{
	static Sprites* __instance;

	unordered_map<int, LPSPRITE> sprites;

public:
	void Add(int id, int left, int top, int width, int height, LPDIRECT3DTEXTURE9 tex);
	LPSPRITE Get(int id);

	void Clear();

	static Sprites* GetInstance();
};

