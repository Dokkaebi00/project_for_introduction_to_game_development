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
	//static Time time;

public:
	static float dt;
	static float fixeddt;
	static float timeScale;
	
	virtual void Awake();

	virtual void Start();

	virtual void Update();

	//use for physicUpdate
	virtual void FixedUpdate();

	//use for cameraUpdate
	virtual void LateUpdate();

	virtual void Render();

	float GetDt();
	void SetDt(float dt);

	float GetFixedDt();
	//void SetFixedDt(float dt);

	float GetTimeScale();
	void SetTimeScale(float ts);
};

