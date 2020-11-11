#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

#include "MonoBehaviour.h"
#include "Game.h"
#include "Textures.h"
#include "Animation.h"
#include "Sprites.h"
#include "Transformation.h"
#include "Camera.h"

#include "CollisionBBox.h"

class Animation;
typedef Animation* LPANIMATION;

class Sprite;
typedef Sprite* LPSPRITE;

class CollisionBBox;
typedef CollisionBBox* LPCOLLISIONBOX;

class Camera;

class GameObject : public MonoBehaviour
{
protected:

	int id;

	Transformation transform; //use for set up position, rotation and scale of the gameobj like unity (this is localTransformation)
	
	string state;

	string type;

	bool isActive;

	//this is for debug
	//float vx;

	LPCOLLISIONBOX collision;
	vector<LPCOLLISIONBOX>* collisions;
	
	LPSPRITE sprite;

	unordered_map<string, LPANIMATION> animation_set;
public:
	GameObject();

	virtual void Init();

	virtual void Clear();

	virtual void Awake();

	virtual void FixedUpdate(vector<LPGAMEOBJECT>* coObjects);

	virtual void Update(Time dt, Camera* camera);

	virtual void Render(Camera* camera);

	void AddAnimationIntoAnimationSet(string state, LPANIMATION animation, bool isLooping);
	void LoadAnimationSet();

	int GetId();
	void SetId(int id);

	D3DXVECTOR2 GetPosition();
	void SetPosition(D3DXVECTOR2 p);

	float GetRotation();
	void SetRotation(float r);

	D3DXVECTOR2 GetScale();
	void SetScale(D3DXVECTOR2 s);

	string GetState();
	void SetState(string state);

	float GetX();
	float GetY();

	string GetType();
	void SetType(string tag);
	bool CompareTag(string type);

	bool GetActive();
	void SetActive(bool active);


	LPCOLLISIONBOX GetCollisionBox();
	void SetCollisionBox(LPCOLLISIONBOX box);

	vector<LPCOLLISIONBOX>* GetCollisions();

	
	//this is for debug
	/*
	float GetVx();
	void SetVx(float vx);
	*/
};
typedef GameObject* LPGAMEOBJECT;
