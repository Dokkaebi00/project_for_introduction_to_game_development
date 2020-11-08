#include "GameObject.h"

D3DXVECTOR2 GameObject::GetPosition()
{
	return this->transform.GetPosition();
}

void GameObject::SetPosition(D3DXVECTOR2 p)
{
	this->transform.SetPosition(p);
}

string GameObject::GetState()
{
	return this->state;
}

void GameObject::SetState(string state)
{
	this->state = state;
}

float GameObject::GetX()
{
	return this->transform.GetPosition().x;
}

float GameObject::GetY()
{
	return this->transform.GetPosition().y;
}

GameObject::GameObject()
{
}

void GameObject::Init()
{
}

void GameObject::Clear()
{
}

void GameObject::Awake()
{
	MonoBehaviour::Awake();
}

void GameObject::Update(Time dt, Camera* camera)
{
	MonoBehaviour::Update();
}

void GameObject::Render(Camera* camera)
{
	MonoBehaviour::Render();
}

void GameObject::AddAnimationIntoAnimationSet(string state, LPANIMATION animation, bool isLooping)
{
}

void GameObject::LoadAnimationSet()
{
}

int GameObject::GetId()
{
	return 0;
}

void GameObject::SetId(int id)
{
}
