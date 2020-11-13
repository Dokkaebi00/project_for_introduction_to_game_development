#include "Object.h"


// Base Game Object Class
Object::Object()
{
	this->transform.SetPosition(D3DXVECTOR2(0.0f, 0.0f));
	this->transform.SetScale(D3DXVECTOR2(1.0f, 1.0f));
	this->transform.SetRotation(0.0f);
}

void Object::AddAnimationWithState(string state, string id, bool isLoop)
{
	LPANIMATION ani = Animations::GetInstance()->Get(id);

	//animation_set[state] = ani;
	animation_set.insert(make_pair(state, ani));
}

void Object::SetTransformation(Transformation transform)
{
	this->transform = transform;
}

Transformation Object::GetTransformation()
{
	return this->transform;
}

void Object::SetPostion(D3DXVECTOR2 p)
{
	this->transform.SetPosition(p);
}

D3DXVECTOR2 Object::GetPosition()
{
	return this->transform.GetPosition();
}

void Object::SetScale(D3DXVECTOR2 s)
{
	this->transform.SetScale(s);
}

D3DXVECTOR2 Object::GetScale()
{
	return this->transform.GetScale();
}

void Object::SetRotation(float r)
{
	this->transform.SetRotation(r);
}

float Object::GetRotation()
{
	return this->transform.GetRotation();
}

void Object::Awake()
{
}

void Object::Start()
{
}

void Object::Update()
{
}

void Object::Render()
{
}

Object::~Object()
{
}

//Base Mario Class

CMario::CMario() : Object()
{
	this->vx = 0.1f;
}

void CMario::Awake()
{
	Object::Awake();
	AddAnimationWithState(MARIO_WALK_STATE, "ani-small-mario-walk");
	DebugOut(L"Mario_Awake \n");
}

void CMario::Start()
{
	Object::Start();
	this->transform.SetPosition(D3DXVECTOR2(50.0f, 50.0f));
	this->transform.SetScale(D3DXVECTOR2(1.0f, 1.0f));
	this->transform.SetRotation(0.0f);

	DebugOut(L"Mario_start \n");

	this->vx = 0.1f;
}

void CMario::Update()
{
	Object::Update();
	D3DXVECTOR2 p = this->transform.GetPosition();

	float dtime = Game::GetInstance()->GetDeltaTime();

	p.x += vx * dtime;

	if (p.x <= 0 || p.x >= 500)
	{
		vx = -vx;
		if (vx < 0)
		{
			this->transform.SetScale(D3DXVECTOR2(-1, 1));
		}
		else
		{
			this->transform.SetScale(D3DXVECTOR2(1, 1));
		}
	}


	this->transform.SetPosition(D3DXVECTOR2(p.x, p.y));

	float x = this->transform.GetPosition().x;

	DebugOut(L"position: %d", x);
	OutputDebugString(ToLPCWSTR("\n"));
}

void CMario::Render()
{
	LPANIMATION ani = animation_set.find(MARIO_WALK_STATE)->second;
	ani->SetScale(this->transform.GetScale());
	ani->Render(this->transform.GetPosition());
}

CMario::~CMario()
{
}
