#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

class Scene
{
public:
	Scene();

	virtual void KeyState(BYTE* state) = 0;
	virtual void OnKeyDown(int KeyCode) = 0;
	virtual void OnKeyUp(int KeyCode) = 0;

	virtual void LoadResources() = 0;
	virtual void Update(DWORD dt) = 0;
	virtual void Render() = 0;
	virtual ~Scene();
};

