#include "GameObject.h"

D3DXVECTOR2 GameObject::GetPosition()
{
	return this->transform.GetPosition();
}

void GameObject::SetPosition(D3DXVECTOR2 p)
{
	this->transform.SetPosition(p);
}

float GameObject::GetRotation()
{
	return this->transform.GetRotation();
}

void GameObject::SetRotation(float r)
{
	this->transform.SetRotation(r);
}

D3DXVECTOR2 GameObject::GetScale()
{
	return this->transform.GetScale();
}

void GameObject::SetScale(D3DXVECTOR2 s)
{
	this->transform.SetScale(s);
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

string GameObject::GetType()
{
	return this->type;
}

void GameObject::SetType(string tag)
{
	this->type = tag;
}

bool GameObject::CompareTag(string type)
{
	if (this->type == type)
	{
		return true;
	}
	return false;
}

bool GameObject::GetActive()
{
	return this->isActive;
}

void GameObject::SetActive(bool active)
{
	this->isActive = active;
}

LPCOLLISIONBOX GameObject::GetCollisionBox()
{
	return this->collision;
}

void GameObject::SetCollisionBox(LPCOLLISIONBOX box)
{
	this->collision = box;
}

vector<LPCOLLISIONBOX>* GameObject::GetCollisions()
{
	return this->collisions;
}

//this is for debug
/*float GameObject::GetVx()
{
	return 0.0f;
}*/


//this is for debug
/*void GameObject::SetVx(float vx)
{
	this->vx = vx;
}*/

GameObject::GameObject()
{
	transform.SetPosition(D3DXVECTOR2(50.0f, 50.0f));
	transform.SetScale(D3DXVECTOR2(1.0f, 1.0f));
	transform.SetRotation(0.0f);

	//this is for debug
	//vx = 0.1f;
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

void GameObject::FixedUpdate(vector<LPGAMEOBJECT>* coObjects)
{
	if (collision->isDynamic() == false)
	{
		return;
	}

	this->collision->Update();

	vector<LPCOLLISIONBOX> others;
	for (LPGAMEOBJECT gameobject : *coObjects)
	{
		vector<LPCOLLISIONBOX>* othercollisions = gameobject->GetCollisions();
		for (LPCOLLISIONBOX collisionbox : *othercollisions)
		{
			others.push_back(collisionbox);
		}
	}

	for (LPCOLLISIONBOX collisionbox : *collisions)
	{
		collisionbox->Update();
		collisionbox->FixedUpdate(&others);
	}
}

void GameObject::Update(Time dt, Camera* camera)
{
	MonoBehaviour::Update();
	
	//this is for debug
	/*D3DXVECTOR2 p = transform.GetPosition();

	p.x = vx * dt.GetDt();

	transform.SetPosition(D3DXVECTOR2(p.x, p.y));*/

}

void GameObject::Render(Camera* camera)
{
	MonoBehaviour::Render();

	//this is for debug
	/*LPANIMATION ani = Animations::GetInstance()->Get("ani-big-mario-walk");

	ani->Render(transform.GetPosition());*/

	if (animation_set.find(state) == animation_set.end() || animation_set.empty())
	{
		return;
	}

	animation_set.find(state)->second->SetRotation(transform.GetRotation());
	animation_set.find(state)->second->SetScale(transform.GetScale());
	

}

void GameObject::AddAnimationIntoAnimationSet(string state, LPANIMATION animation, bool isLooping)
{
	animation->SetLoop(isLooping);

	animation_set.insert(make_pair(state, animation));

	//animation_set[state] = animation;
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
