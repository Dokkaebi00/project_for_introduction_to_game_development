#pragma once

#include <d3dx9.h>

#include "GameObject.h"
#include "FloatRect.h"

class GameObject;
typedef GameObject* LPGAMEOBJECT;


class Camera
{
	DWORD dt; //dt->need for update function (update camera position with time

	float vx; // = Mario'vx at scen 1 2 3, = const at scene 4

	bool isAuto; // use at scene 4
	float autoDistance; //use at scene 4

	float camWidth; 
	float camHeight;

	D3DXVECTOR2 camPos; // relative with the position of the gameobj

	FloatRect boundary; //set up boundary of the camera, talk more about this in game

	LPGAMEOBJECT gameobj; //mario

public:
	Camera(float width, float height);

	D3DXVECTOR2 TransformWorldPostoCamPos(D3DXVECTOR2 worldPos);
	D3DXVECTOR2 TransformCamPostoWorldPos(D3DXVECTOR2 CamPos);
	
	bool CheckObjectInCameraByPosition(D3DXVECTOR2 objPos, float objWidth, float objHeight);
	bool CheckObjectInCameraByRect(RECT r);


	virtual void Update();
	virtual void Render();

	float GetCamSpeed();
	void SetCamSpeed(float vx);

	D3DXVECTOR2 GetCamPosition();
	void SetCamPosition(D3DXVECTOR2 pos);

	float GetCamWidth();
	void SetCamWidth(float camWidth);

	float GetCamHeight();
	void SetCamHeight(float camHeight);

	FloatRect GetBoundary();
	void SetBoundray(FloatRect r);

	LPGAMEOBJECT GetGameObject();
	void SetGameObject(LPGAMEOBJECT obj);

	~Camera();
};

