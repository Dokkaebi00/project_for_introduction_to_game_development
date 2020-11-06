#pragma once

#include<unordered_map>
#include "Animation.h"

using namespace std;

class Animation;
typedef Animation* LPANIMATION;

class Animations
{
	static Animations* __instance;

	unordered_map<string, LPANIMATION> animations;

public:
	Animations();

	static Animations* GetInstance();

	void AddAnimation(string id, LPANIMATION ani);

	void LoadAnimations();

	int LoadResource(string textureName, string filePath);

	LPANIMATION Get(string id);

	LPANIMATION Clone(string id);

	~Animations();
};

