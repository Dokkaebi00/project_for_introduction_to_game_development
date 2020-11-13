#pragma once
#include<d3d9.h>
#include<d3dx9.h>
#include<unordered_map>

#include "Animation.h"
#include "Animations.h"
#include "MonoBehaviour.h"
#include "Transformation.h"

using namespace std;

class Animation;
typedef Animation* LPANIMATION;

//BaseGameObject Class
class Object : public MonoBehaviour
{
protected:

	Transformation transform;

	D3DXVECTOR2 direction;

	string state;

	unordered_map<string, LPANIMATION> animation_set;

public:
	Object();
	
	void AddAnimationWithState(string state, string id, bool isLoop = true);

	void SetTransformation(Transformation transform);
	Transformation GetTransformation();

	void SetPostion(D3DXVECTOR2 p);
	D3DXVECTOR2 GetPosition();

	void SetScale(D3DXVECTOR2 s);
	D3DXVECTOR2 GetScale();

	void SetRotation(float r);
	float GetRotation();

	virtual void Awake();
	virtual void Start();
	virtual void Update();
	virtual void Render();


	~Object();
};
typedef Object* LPGAMEOBJECT;

//Mario Class;
class CMario :public Object
{
protected:
	float vx;

public:
	CMario();

	virtual void Awake();

	virtual void Start();

	virtual void Update();

	virtual void Render();

	~CMario();
};
typedef CMario* LPMARIO;