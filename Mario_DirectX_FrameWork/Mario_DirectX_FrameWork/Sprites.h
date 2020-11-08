#pragma once

#include<d3d9.h>
#include<d3dx9.h>
#include<unordered_map>

#include"Sprite.h"
#include "tinyxml.h"

using namespace std;

class Sprites;
typedef Sprites* LPSprites;

class Sprite;
typedef Sprite* LPSPRITE;

class Sprites
{
	//singleton
	static Sprites* __instance;

	//sprite database
	unordered_map<string, LPSPRITE> sprites;

public:
	
	Sprites();
	
	void LoadSprites();
	
	void Add(string id, int left, int top, int width, int height, LPDIRECT3DTEXTURE9 texture, int xPivot);
	

	int CreateSprite(string textureName, string filePath);
	
	LPSPRITE Get(string id);

	static Sprites* GetInstance();
	
	~Sprites();

};

