#pragma once

#include<d3dx9.h>
#include<unordered_map>

#include "Game.h"

using namespace std;

class Textures
{
	static Textures* __instance;

	unordered_map<int, LPDIRECT3DTEXTURE9> textures;

public:
	Textures();
	void Add(int id, LPCWSTR filePath, D3DCOLOR transparentColor);
	LPDIRECT3DTEXTURE9 Get(int i);

	static Textures* GetInstance();
};

