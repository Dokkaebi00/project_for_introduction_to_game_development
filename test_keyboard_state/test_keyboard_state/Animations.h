#pragma once

#include<Windows.h>
#include<unordered_map>

#include"Animation.h"

using namespace std;

class Animations
{
	static Animations* __instance;

	unordered_map<int, LPANIMATION> animations;

public:
	void Add(int id, LPANIMATION ani);
	LPANIMATION Get(int id);

	static Animations* GetInstance();
};

