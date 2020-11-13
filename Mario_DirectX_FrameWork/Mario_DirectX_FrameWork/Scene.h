#pragma once
#include<vector>
#include<vector>
#include<string>

#include "MonoBehaviour.h"
//#include "Camera.h"
#include "Time.h"

class GameObject;
typedef GameObject* LPGAMEOBJECT;

using namespace std;

class Scene : public MonoBehaviour
{
protected:
	//Camera* camera;

	string path;

	string id;

	vector<LPGAMEOBJECT> gameObjects;

public:
	Scene();

	virtual void Awake();
	virtual void Update(Time dt);
	virtual void Render();

	string GetID();
	void SetID(string ID);

	string GetPath();
	void SetPath(string path);

	//Camera* GetCamera();
	//void SetCamera(Camera* camera);

	void AddObjectToScene(LPGAMEOBJECT gameobj);


	~Scene();
};
typedef Scene* LPSCENE;
