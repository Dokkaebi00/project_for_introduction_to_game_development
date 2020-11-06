#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <unordered_map>

#include "Game.h"
#include "Utils.h"

using namespace std;

class Textures
{
	static Textures* __instance;

	unordered_map<string, LPDIRECT3DTEXTURE9> textures;

public:
	static Textures* GetInstance();
	~Textures();
	
	void Add(string id, LPCWSTR texturePath, D3DCOLOR transparentColor);
	LPDIRECT3DTEXTURE9 GetTexture(string id);

	void LoadTexutres();
};

