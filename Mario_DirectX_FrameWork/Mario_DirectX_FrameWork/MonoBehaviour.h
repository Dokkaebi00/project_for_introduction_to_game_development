#pragma once
#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

#include "Time.h"

class Time;

//basic class of all component class in framework (Game, GameObject, Camera, ...)

class MonoBehaviour
{
protected:
	//dt (time between 2 frame, define a dt variable in Game class so that we can use this dt 
	//for all object in game like GameObject, Scene, more easy to handle than each update have an invidual dt
	Time dt;

public:
	
	virtual void Awake();

	virtual void Update();
	virtual void Render();

	Time GetDt();
	void SetDt(float dt);
};

