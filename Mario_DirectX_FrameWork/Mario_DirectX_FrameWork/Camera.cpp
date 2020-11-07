#include "Camera.h"
#include "FloatRect.h"

Camera::Camera(float width, float height)
{
	this->camHeight = height;
	this->camWidth = width;

	this->boundary = FloatRect();

	this->vx = 0.0f;
}

D3DXVECTOR2 Camera::TransformWorldPostoCamPos(D3DXVECTOR2 worldPos)
{
	float x;
	float y;
	x = worldPos.x - camPos.x;
	y = worldPos.y - camPos.y;
	return D3DXVECTOR2(x, y);
}

D3DXVECTOR2 Camera::TransformCamPostoWorldPos(D3DXVECTOR2 CamPos)
{
	float x;
	float y;
	x = CamPos.x + this->camPos.x;
	y = CamPos.y + this->camPos.y;
	return D3DXVECTOR2(x, y);
}

bool Camera::CheckObjectInCameraByPosition(D3DXVECTOR2 objPos, float objWidth, float objHeight)
{
	if (objPos.x + objWidth < camPos.x || camPos.x + camWidth < objPos.x)
	{
		return false;
	}
	if (objPos.y + objHeight < camPos.y || camPos.y + camHeight < objPos.y)
	{
		return false;
	}
	return true;
}

bool Camera::CheckObjectInCameraByRect(RECT r)
{
	int width = r.right - r.left;
	int height = r.bottom - r.top;
	
	return r.left >= camPos.x - width && 
		r.right <= camPos.x + camWidth + width &&
		r.top >= camPos.y - height && 
		r.bottom <= camPos.y + camHeight + height;
}

void Camera::Update()
{
}

void Camera::Render()
{
}

