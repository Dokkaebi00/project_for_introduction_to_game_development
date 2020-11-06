#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

#include"Game.h"
#include"Textures.h"

class GameObject
{
protected:
	int id;
	DWORD dt;

public:
	GameObject();

	virtual void Init();
	
	virtual void Update();
	virtual void Render();
};
typedef GameObject* LPGAMEOBJECT;
