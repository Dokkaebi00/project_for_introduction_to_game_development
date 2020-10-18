#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<vector>

#include"Animation.h"
#include"Animations.h"

using namespace std;

class GameObject
{
protected:

	float x;
	float y;

	float vx;
	float vy;

	int nx;

	int state;

	static vector<LPANIMATION> animations;

public:
	void SetPosition(float x, float y);
	void GetPosition(float& x, float& y);
	
	void SetSpeed(float vx, float vy);
	void GetSpeed(float& vx, float& vy);

	void SetState(int state);
	int GetState();

	static void AddAnimation(int aniId);

	GameObject();

	void Update(DWORD dt);
	void Render();
	~GameObject();
};

