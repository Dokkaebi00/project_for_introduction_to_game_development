#pragma once

#include<Windows.h>
#include<dinput.h>
#include<minwindef.h>

class KeyEventHandler
{
public:
	virtual void OnKeyDown(int KeyCode) = 0;
	virtual void OnKeyUp(int KeyCode) = 0;
	virtual void KeyState() = 0;
};

typedef KeyEventHandler* LPKEYEVENTHANDLER;