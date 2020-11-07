#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

#include"Game.h"
#include"Textures.h"
#include"Animation.h"
#include"Transformation.h"

class GameObject
{
protected:

	int id;
	DWORD dt;

	Transformation transform;

public:
	GameObject();

	virtual void Init();
	
	virtual void Update();
	virtual void Render();

	int GetId();
	void SetId(int id);

	D3DXVECTOR2 GetPosition();
	void SetPosition(D3DXVECTOR2 p);

	float GetX();
	float GetY();

};
typedef GameObject* LPGAMEOBJECT;
