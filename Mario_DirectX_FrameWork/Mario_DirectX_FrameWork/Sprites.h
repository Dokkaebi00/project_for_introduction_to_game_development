#pragma once

#include<d3d9.h>
#include<d3dx9.h>
#include<unordered_map>

#include"Sprite.h"

class Sprites
{
	static Sprites* __instance;

	unordered_map<string, LPSPRITE> sprites;

public:
	
	Sprites();
	
	void LoadResources();
	
	void Add(string id, int left, int top, int width, int height, LPDIRECT3DTEXTURE9 texture, int xPivot);
	
	int LoadSprite(string textureName, LPCWSTR filePath);
	
	LPSPRITE GetSprite(string id);

	static Sprites* GetInstance();
	
	~Sprites();

};

