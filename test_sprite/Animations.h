#pragma once
#include"Animation.h"
#include"AnimationFrame.h"
#include"Game.h"
#include"Sprite.h"

#include<Windows.h>
#include<d3dx9.h>

class Animations
{
	static Animations* __instance;

	unordered_map<int, LPANIMATION> animations;

public:
	void Add(int id, LPANIMATION ani);
	LPANIMATION Get(int id);

	static Animations* GetInstance();
};

