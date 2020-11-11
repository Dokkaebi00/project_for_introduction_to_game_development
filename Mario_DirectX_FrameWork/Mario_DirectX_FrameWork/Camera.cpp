#include "Camera.h"
#include "FloatRect.h"

Camera::Camera(float width, float height)
{
	this->camHeight = height;
	this->camWidth = width;

	this->boundary = FloatRect();

	this->vx = 0.0f;
}

Camera::Camera()
{
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
	
	if (r.left >= camPos.x - width && r.right <= camPos.x + camWidth + width && r.top >= camPos.y - height && r.bottom <= camPos.y + camHeight + height)
	{
		return true;
	}
	
	return false;
}

void Camera::Awake()
{
}

void Camera::Update()
{
	MonoBehaviour::Update();

	this->time = Game::GetInstance()->GetTime();

	float x;

	float y;

	if (isAuto)
	{
		float dx = vx * this->time.GetDt();
		camPos.x += dx;
	}
	else
	{
		x = gameobj->GetX();
		y = gameobj->GetY();

		camPos.x = x - camWidth * 0.5f;

		camPos.y = y - camHeight * 0.5f;

		if (camPos.x < boundary.left)
		{
			camPos.x = boundary.left;
		}
		if (camPos.x > boundary.right - camWidth)
		{
			camPos.x = boundary.right - camWidth;
		}
		if (camPos.y < boundary.top)
		{
			camPos.y = boundary.top;
		}
		if (camPos.y > boundary.bottom - camHeight)
		{
			camPos.y = boundary.bottom - camHeight;
		}
	}

	gameobj->SetPosition(D3DXVECTOR2(x, y));
}

void Camera::Render()
{
}

float Camera::GetCamSpeed()
{
	return this->vx;
}

void Camera::SetCamSpeed(float vx)
{
	this->vx = vx;
}

D3DXVECTOR2 Camera::GetCamPosition()
{
	return this->camPos;
}

void Camera::SetCamPosition(D3DXVECTOR2 pos)
{
	this->camPos = pos;
}

float Camera::GetCamWidth()
{
	return this->camWidth;
}

void Camera::SetCamWidth(float camWidth)
{
	this->camWidth = camWidth;
}

float Camera::GetCamHeight()
{
	return this->camHeight;
}

void Camera::SetCamHeight(float camHeight)
{
	this->camHeight = camHeight;
}

FloatRect Camera::GetBoundary()
{
	return this->boundary;
}

void Camera::SetBoundray(FloatRect r)
{
	this->boundary = r;
}

LPGAMEOBJECT Camera::GetGameObject()
{
	return this->gameobj;
}

void Camera::SetGameObject(LPGAMEOBJECT obj)
{
	this->gameobj = obj;
}

Camera::~Camera()
{
}

