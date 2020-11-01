#pragma once

#include"Debug.h"
#include"Game.h"
#include<d3dx9.h>
#include<d3d9.h>


class Camera
{
protected:
	//toa do cua camera
	float posX;
	float posY;

	//toa do khoi diem cua camera trong scene (khi mario chet thi camera se quay lai day)
	float xPrev;
	float yPrev;

	//chieu dai va rong cua camera (mac dinh bang kich thuoc cua game window)
	int cameraWidth;
	int cameraHeight;

	//toa do bien cua camera (mac dinh bang gioi han cua map)
	float cameraEdgeLeft;
	float cameraEdgeRight;

	//toa do khoi diem cua bien camera (luu lai de phong truong hop chung ta thay doi toa do Edge)
	float cameraEdgeLeftPrev;
	float cameraEdgeRightPrev;

	//toc do cua camera (doi voi cac scene nhu 1 2 3 thi = toc do cua mario, doi voi scene 4 thi toa do nay se dc cai mac dinh de tu dong di chuyen)
	float vx;
	DWORD dt;

	// dung cho scene 4
	bool isAuto;
	float autoDistance;
	float autoXPrev; // tuong tu nhu xPrev, do dung de luu lai toa do ban dau cua camera trong scene

	//dung cho cac scene 1 2 3
	bool followMario;

public:
	Camera(int width, int height);
	~Camera();

	void Update(DWORD dt);

	D3DXVECTOR2 Transform(float xWorld, float yWorld);

	void SetPosition(float x, float y);

	float GetX();
	float GetY();
	int GetWidth();
	int GetHeight();

	bool checkObjectInCamera(float x, float y, float w, float h);

	bool isFollowMario();
	void SetFollowMario(bool follow);

	void SetAuto(float distance, float speed);
	void StopAuto();
	bool GetIsAuto();

	void SetCameraEdge(float LeftEdge, float RightEdge);
	float GetCameraEdgeLeft();
	float GetCameraEdgeRight();

	void SetPrevPosition(float x, float y);
	void ResetPosition();

	void SetPrevCameraEdge(float left, float right);
	void ResetCameraEdge();
};

