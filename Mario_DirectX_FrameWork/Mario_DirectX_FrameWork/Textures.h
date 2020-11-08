#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <unordered_map>

#include "Game.h"
#include "Utils.h"
#include "Define.h"

using namespace std;

class Textures
{
	//singleton
	static Textures* __instance;

	//database of texture
	unordered_map<string, LPDIRECT3DTEXTURE9> textures;

public:
	//singleton
	static Textures* GetInstance();
	//delete all texture in the database when game is finished
	~Textures();
	//add an texture into the database
	void Add(string id, LPCWSTR texturePath, D3DCOLOR transparentColor);
	//get a texture with id
	LPDIRECT3DTEXTURE9 GetTexture(string id);
	//load all texture in the database
	void LoadTextures();
};

