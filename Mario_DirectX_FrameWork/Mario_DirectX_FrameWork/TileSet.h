#pragma once
#include<unordered_map>
#include<d3d9.h>
#include<d3dx9.h>

class TileSet
{
public:
	int firstgid;
	
	int with;
	int hieght;
	
	int colums;

	LPDIRECT3DTEXTURE9 texture;
};

