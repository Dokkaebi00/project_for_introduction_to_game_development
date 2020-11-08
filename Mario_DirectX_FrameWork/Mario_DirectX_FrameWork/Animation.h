#pragma once

#include<vector>
#include<d3dx9.h>
#include<d3d9.h>

#include"Utils.h"
#include"Sprite.h"
#include"GameObject.h"
#include"AnimationFrame.h"
#include "Transformation.h"
using namespace std;



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
	
	bool isLooping; //for looping animation, brick at the end of the scene game, Goomba,...

	bool isEnabled; //some animation just plays when we get into an overlappedBox or triggerBox, or animation will be disbale when mario interacts with it (brick with the quesion mark);

	Transformation transform; //set the position, scale or rotation of the anmation (ex: the leaf item)

	D3DXVECTOR2 localPosition; //position of the animation with the relative object (for example when we draw attack animation of the racoon, movement animation of the marion -> update animation with the gameobj...)


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

	void SetLocalPosition(D3DXVECTOR2 relativeposition);
	D3DXVECTOR2 GetLocalPosition();

	void SetEnabled(bool enable);

	D3DXVECTOR2 GetPosition();

	D3DXVECTOR2 GetScale();

	float GetRotation();

	bool GetIsLooping();

	LPANIMATION_FRAME GetAnimFrame();

	

	void SetGameObject(LPGAMEOBJECT obj);

	LPGAMEOBJECT GetGameObject();

	int GetNumberOfFrames();

	int GetCurrentFrame();
};
typedef Animation* LPANIMATION;
