#pragma once
#include "KeyEventHandler.h"

class GameKeyEventHandler : public KeyEventHandler
{
public:
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	virtual void KeyState();
};

