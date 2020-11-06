#pragma once

#include<Windows.h>
#include<dinput.h>
#include<d3d9.h>
#include<d3dx9.h>

#include"KeyEventHandler.h"
#include"Game.h"

#define DIRECTINPUT_VERSION 0x0800
#define KEYBOARD_BUFFER_SIZE 1024

class KeyboardProcessing
{
private:
	static KeyboardProcessing* __instance;
	
	HWND hWnd;
	
	LPDIRECTINPUT8 di;
	LPDIRECTINPUTDEVICE8 didv;

	BYTE keyStates[256];
	DIDEVICEOBJECTDATA keyEvents[KEYBOARD_BUFFER_SIZE];

	LPKEYEVENTHANDLER keyHandler;
public:
	static KeyboardProcessing* GetInstance();
	~KeyboardProcessing();
	
};
typedef KeyboardProcessing* LPKeyboardProcessing;
