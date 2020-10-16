#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<dinput.h>

class KeyBoard
{
public:
	virtual void KeyState(BYTE* state);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
};

typedef KeyBoard * LPKEYEVENTHANDLER;

