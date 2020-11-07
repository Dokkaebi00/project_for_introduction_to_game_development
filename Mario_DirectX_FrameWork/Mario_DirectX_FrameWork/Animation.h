#pragma once

#include<vector>
#include<d3dx9.h>
#include<d3d9.h>

#include"Utils.h"
#include"Sprite.h"
#include"GameObject.h"
#include"AnimationFrame.h"

using namespace std;

struct Transformation
{
	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;
	float rotation;

	Transformation Transform(D3DXVECTOR2 position, D3DXVECTOR2 scale, float rotation)
	{
		Transformation a;
		a.position = position;
		a.scale = scale;
		a.rotation = rotation;

		return a;
	}
};

class AnimationFrame;
typedef AnimationFrame* LPANIMATION_FRAME;

class GameObject;
typedef GameObject* LPGAMEOBJECT;

class Animation
{
	string id;

	int currentFrame;
	int defaultTime;
	DWORD lastFrameTime;
	
	bool isLooping; //for looping animation, brick, Goomba,...

	bool isEnabled; //some animation just plays when we get into an overlappedBox or triggerBox;

	Transformation transform; //set the position, scale or rotation of the anmation (ex: the leaf item)

	D3DXVECTOR2 relativePosition; //position of the animation with the relative object (for example when we draw attack animation of the racoon,...)


	vector<LPANIMATION_FRAME> frames;

	GameObject* gameobj; //obj that contain the animation of the animation

public:
	Animation(string id, DWORD defaultTime = 100);

	void Add(LPSPRITE sprite, D3DXVECTOR2 position, DWORD frameTime = 0);
	void Render(D3DXVECTOR2 position, int alpha = 255);

	void SetPosition(D3DXVECTOR2 position);

	void SetScale(D3DXVECTOR2 scale);

	void SetRotation(float rotation);

	void SetLoop(bool isLoop);

	void SetRelativePosition(D3DXVECTOR2 relativeposition);

	void SetEnabled(bool enable);

	D3DXVECTOR2 GetPosition();

	D3DXVECTOR2 GetScale();

	float GetRotation();

	bool GetIsLooping();

	LPANIMATION_FRAME GetAnimFrame();

	D3DXVECTOR2 GetRelativePosition();

	void SetGameObject(LPGAMEOBJECT obj);

	LPGAMEOBJECT GetGameObject();

	int GetNumberOfFrames();

	int GetCurrentFrame();
};
typedef Animation* LPANIMATION;
