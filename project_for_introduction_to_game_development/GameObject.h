#pragma once
#include<Windows.h>
#include<d3dx9.h>
#include"Game.h"

class GameObject
{
protected:
	float x;
	float y;

	LPDIRECT3DTEXTURE9 texture;

public:
	virtual void Update(DWORD dt);
	virtual void Render();

	void SetPostion(float x, float y);
	int GetX();
	int GetY();

	GameObject(float x = 0.0f, float y = 0.0f, LPDIRECT3DTEXTURE9 texture = NULL);

	~GameObject();
};

typedef GameObject* LPGAMEOBJECT;
