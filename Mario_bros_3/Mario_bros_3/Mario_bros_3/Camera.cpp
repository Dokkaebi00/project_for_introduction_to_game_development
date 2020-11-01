#include "Camera.h"

Camera::Camera(int width, int height)
{
	cameraWidth = width;
	cameraHeight = height;
	followMario = true;
	isAuto = false;

	cameraEdgeLeft = 0;
	cameraEdgeRight = 0;
	xPrev = yPrev = 0;

	SetPrevCameraEdge(cameraEdgeLeft, cameraEdgeRight);

	vx = 0;
}

Camera::~Camera()
{
}

void Camera::Update(DWORD dt)
{
	this->dt = dt;

	if (isAuto)
	{
		float dx;
		dx = vx * dt;
		posX = posX + dx;
	}

	if (isAuto == true)
	{
		if (abs(posX - autoXPrev) >= autoDistance)
		{
			posX = posX - (abs(posX - autoXPrev) - autoDistance);
			isAuto = false;
		}
	}

	if (posX < cameraEdgeLeft)
	{
		posX = cameraEdgeLeft;
	}

	if (posX > cameraEdgeRight)
	{
		posX = cameraEdgeRight;
	}
}

D3DXVECTOR2 Camera::Transform(float xWorld, float yWorld)
{
	return D3DXVECTOR2(xWorld - posX, yWorld - posY);
}

void Camera::SetPosition(float x, float y)
{
	posX = x;
	posY = y;
}

float Camera::GetX()
{
	return posX;
}

float Camera::GetY()
{
	return posY;
}

int Camera::GetWidth()
{
	return cameraWidth;
}

int Camera::GetHeight()
{
	return cameraHeight;
}

bool Camera::checkObjectInCamera(float x, float y, float w, float h)
{
	if (x + w < posX || posX + cameraWidth < x)
	{
		return false;
	}
	if (y + h < posY || posY + cameraHeight < y)
	{
		return false;
	}
	return true;
}

bool Camera::isFollowMario()
{
	return followMario;
}

void Camera::SetFollowMario(bool follow)
{
	followMario = follow;
}

void Camera::SetAuto(float distance, float speed)
{
	if (isAuto == true)
	{
		return;
	}

	vx = speed;
	autoXPrev = posX;
	autoDistance = distance;
	isAuto = true;
	followMario = false;
}

void Camera::StopAuto()
{
	isAuto = false;
}

bool Camera::GetIsAuto()
{
	return isAuto;
}

void Camera::SetCameraEdge(float LeftEdge, float RightEdge)
{
	cameraEdgeLeft = LeftEdge;
	cameraEdgeRight = RightEdge;
}

float Camera::GetCameraEdgeLeft()
{
	return cameraEdgeLeft;
}

float Camera::GetCameraEdgeRight()
{
	return cameraEdgeRight;
}

void Camera::SetPrevPosition(float x, float y)
{
	xPrev = x;
	yPrev = y;
}

void Camera::ResetPosition()
{
	posX = xPrev;
	posY = yPrev;

	cameraEdgeLeft = cameraEdgeLeftPrev;
	cameraEdgeRight = cameraEdgeRightPrev;
}

void Camera::SetPrevCameraEdge(float left, float right)
{
	cameraEdgeLeftPrev = left;
	cameraEdgeRightPrev = right;
}

void Camera::ResetCameraEdge()
{
	cameraEdgeLeft = cameraEdgeLeftPrev;
	cameraEdgeRight = cameraEdgeRightPrev;
}
