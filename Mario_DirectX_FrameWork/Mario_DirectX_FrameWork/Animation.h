#pragma once

#include<vector>
#include<d3dx9.h>
#include<d3d9.h>

#include"Utils.h"
#include"Sprite.h"
#include"AnimationFrame.h"
#include "Transformation.h"
using namespace std;



class AnimationFrame;
typedef AnimationFrame* LPANIMATION_FRAME;

class Animation
{
	string id;

	int currentFrame;
	int defaultTime;
	DWORD lastFrameTime;
	
	bool isLooping; 
	//for looping animation, brick at the end of the scene game, Goomba, Mario_walk...

	bool isEnabled; 
	//some animation just plays when we get into an overlappedBox or triggerBox, or animation will be disbale when mario interacts with it (brick with the quesion mark);
	//or for object have many animaton in the animation_set
	//ex: Mario have a lot of states with a lot of animations for each states
	//when an state end -> disable the state -> disable the animation of that state

	Transformation transform; 
	//set the position, scale or rotation of the anmation (ex: the leaf item, sync the animation's position with the position of gameobject)

	D3DXVECTOR2 localPosition; 
	//position of the animation with the relative object (for example when we draw attack animation of the racoon, movement animation of the marion -> update animation with the gameobj...)
	//what is the difference between localPostion and Postion(worldPostion)
	//localPostion is the position which is the centerpoint of the coordinate is gameObj
	//for example racoon mario have a tail and it's localPosition is 0,1
	//world postion is the position of component with the world

	// an animation = 1 or alot of frames
	vector<LPANIMATION_FRAME> frames;

	//relative obj with the animation

public:
	Animation(string id, DWORD defaultTime = 100);

	void Add(LPSPRITE sprite, D3DXVECTOR2 position, DWORD frameTime = 0);
	void Render(D3DXVECTOR2 position, int alpha = 255);

	void SetPosition(D3DXVECTOR2 position);
	D3DXVECTOR2 GetPosition();

	void SetScale(D3DXVECTOR2 scale);
	D3DXVECTOR2 GetScale();

	void SetRotation(float rotation);
	float GetRotation();

	void SetLoop(bool isLoop);
	bool GetIsLooping();

	void SetLocalPosition(D3DXVECTOR2 relativeposition);
	D3DXVECTOR2 GetLocalPosition();

	void SetEnabled(bool enable);
	bool CheckIsEnabled();

	LPANIMATION_FRAME GetAnimFrame();

	//void SetGameObject(LPGAMEOBJECT obj);
	//LPGAMEOBJECT GetGameObject();

	int GetNumberOfFrames();
	int GetCurrentFrame();
};
typedef Animation* LPANIMATION;
