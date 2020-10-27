#pragma once

#include"Debug.h"

class Camera
{
protected:
	float x;
	float y;

	int cameraWidth;
	int cameraHeight;

	float cameraEdgeLeft;
	float cameraEdgeRight;

	float vx;
	DWORD dt;

};

