#pragma once
#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>


class MonoBehaviour
{
protected:
	float dt;

public:
	virtual void Update() = 0;
	virtual void Render() = 0;

	float GetDeltaTime();
	void SetDeltaTime(float dt);
};

