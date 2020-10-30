#pragma once

#include <d3d9.h>
#include<d3dx9.h>
#include<unordered_map>

#include"Game.h"

using namespace std;

class Textures
{
	static Textures* __instance;
	unordered_map<int, LPDIRECT3DTEXTURE9> textures;

public:
	Textures();

	void Add(int id, LPCWSTR filePath, D3DCOLOR transparentColor);
	void Clear();

	LPDIRECT3DTEXTURE9 Get(unsigned int id);
	static Textures* GetInstance();
};

