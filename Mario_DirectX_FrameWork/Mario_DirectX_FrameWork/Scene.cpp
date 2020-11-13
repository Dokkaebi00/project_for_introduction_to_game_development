#include "Scene.h"

Scene::Scene()
{
}

void Scene::Awake()
{
}

void Scene::Update(Time dt)
{
}

void Scene::Render()
{
}

string Scene::GetID()
{
	return this->id;
}

void Scene::SetID(string ID)
{
	this->id = ID;
}

string Scene::GetPath()
{
	return this->path;
}

void Scene::SetPath(string path)
{
	this->path;
}

/*
Camera* Scene::GetCamera()
{
	return this->camera;
}

void Scene::SetCamera(Camera* camera)
{
	this->camera = camera;
}
*/
void Scene::AddObjectToScene(LPGAMEOBJECT gameobj)
{
	if (gameobj != NULL)
	{
		gameObjects.push_back(gameobj);
	}
}

Scene::~Scene()
{
}
