#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

#include "MonoBehaviour.h"
#include"Game.h"
#include"Textures.h"
#include"Animation.h"
#include"Transformation.h"
#include"Camera.h"

class Animation;
typedef Animation* LPANIMATION;

class Camera;

class GameObject : public MonoBehaviour
{
protected:

	int id;

	Transformation transform; //use for set up position, rotation and scale of the gameobj like unity
	string state;

	string tag;

	bool isActive;

	unordered_map<string, LPANIMATION> animation_set;
public:
	GameObject();

	virtual void Init();

	virtual void Clear();

	virtual void Awake();

	virtual void Update(Time dt, Camera* camera);

	virtual void Render(Camera* camera);

	void AddAnimationIntoAnimationSet(string state, LPANIMATION animation, bool isLooping);
	void LoadAnimationSet();

	int GetId();
	void SetId(int id);

	D3DXVECTOR2 GetPosition();
	void SetPosition(D3DXVECTOR2 p);

	string GetState();
	void SetState(string state);

	float GetX();
	float GetY();

	string GetTag();
	void SetTag(string tag);
	bool CompareTag(string tag);

	bool GetActive();
	void SetActive(bool active);


};
typedef GameObject* LPGAMEOBJECT;
