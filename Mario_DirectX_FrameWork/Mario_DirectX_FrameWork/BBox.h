#pragma once

#include<Windows.h>
#include<d3dx9.h>
#include<d3d9.h>

#include"Transformation.h"
#include"GameObject.h"
#include"FloatRect.h"
#include"Camera.h"
#include"Define.h"

class Transformation;

class BBox
{
	Transformation localTransform; //local position, transform and scale
	LPGAMEOBJECT gameObject;
	//tag in the gameObject
	FloatRect Box;

	float width;
	float height;

public:
	BBox();

	void SetTransformation(Transformation transform);
	Transformation GetTransformation();

	void SetLocalPosition(D3DXVECTOR2 position);
	D3DXVECTOR2 GetLocalPosition();

	void SetLocalRotation(float rotation);
	float GetLocalRotation();

	void SetLocalScale(D3DXVECTOR2 scale);
	D3DXVECTOR2 GetLocalScale();

	FloatRect GetBoundingBox();

	void SetSize(float width, float height);
	void GetSize(float& width, float& height);

	void SetWidth(float width);
	float GetWidth();

	void SetHeight(float height);
	float GetHeight();

	void SetGameObject(LPGAMEOBJECT gameobj);
	LPGAMEOBJECT GetGameObject();

	D3DXVECTOR2 GetPositionInGame();

	//why we need to pass camera in this function
	//we just render box in the camera, and render it with the localPosition which camera is the coordinate
	void Render(Camera* camera);

	~BBox();
};

