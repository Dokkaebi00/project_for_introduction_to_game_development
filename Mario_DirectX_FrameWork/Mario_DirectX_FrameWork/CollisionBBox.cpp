#include "CollisionBBox.h"

void CollisionBBox::SetGameObject(LPGAMEOBJECT gameobj)
{
	this->gameObj = gameobj;
}

LPGAMEOBJECT CollisionBBox::GetGameObject()
{
	return this->gameObj;
}

void CollisionBBox::SetCollisionBoxSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

void CollisionBBox::SetCollisionBoxSize(float& width, float& height)
{
	width = this->width;
	height = this->height;
}

float CollisionBBox::GetWidth()
{
	return this->width;
}

void CollisionBBox::SetWidth(float width)
{
	this->width;
}

float CollisionBBox::GetHeight()
{
	return this->height;
}

void CollisionBBox::SetHeight(float height)
{
	this->height = height;
}

Transformation CollisionBBox::GetTransformation()
{
	return this->localTransformation;
}

void CollisionBBox::SetTransformation(Transformation transform)
{
	this->localTransformation = transform;
}

D3DXVECTOR2 CollisionBBox::GetLocalLocation()
{
	return this->localTransformation.GetPosition();
}

void CollisionBBox::SetLocalLocation(D3DXVECTOR2 p)
{
	this->localTransformation.SetPosition(p);
}

D3DXVECTOR2 CollisionBBox::GetLocalScale()
{
	return this->localTransformation.GetScale();
}

void CollisionBBox::SetLocalScale(D3DXVECTOR2 s)
{
	this->localTransformation.SetScale(s);
}

float CollisionBBox::GetLocalRotation()
{
	return this->localTransformation.GetRotation();
}

void CollisionBBox::SetLocalRotation(float r)
{
	this->localTransformation.SetRotation(r);
}

FloatRect CollisionBBox::GetRect()
{
	D3DXVECTOR2 p = GetPositionInGame();

	FloatRect rect;
	
	rect.left = p.x - width * 0.5f;
	rect.top = p.y - height * 0.5f;
	rect.right = p.x + width * 0.5f;
	rect.bottom = p.y + height * 0.5f;

	return rect;
}

/*void CollisionBBox::SetRect(FloatRect r)
{
	this->Box = r;
}*/

bool CollisionBBox::Active()
{
	return this->isActive;
}

void CollisionBBox::SetActive(bool active)
{
	this->isActive = active;
}

float CollisionBBox::GetVx()
{
	return this->vx;
}

void CollisionBBox::SetVx(float vx)
{
	this->vx = vx;
}

float CollisionBBox::GetVy()
{
	return this->vy;
}

void CollisionBBox::SetVy(float vy)
{
	this->vy = vy;
}

float CollisionBBox::GetAcceleration()
{
	return this->acceleration;
}

void CollisionBBox::SetAcceleration(float a)
{
	this->acceleration = a;
}

float CollisionBBox::GetGravity()
{
	return this->gravity;
}

void CollisionBBox::SetGravity(float g)
{
	this->gravity = g;
}

bool CollisionBBox::Gravity()
{
	return this->isUseGravity;
}

void CollisionBBox::UseGravity(bool gravity)
{
	this->isUseGravity = gravity;
	if (this->isUseGravity == false)
	{
		this->gravity = 0;
	}
}

float CollisionBBox::DragForce()
{
	return this->drag;
}

void CollisionBBox::SetDragForce(float dragforce)
{
	this->drag = dragforce;
}

bool CollisionBBox::isDynamic()
{
	return this->Dynamic;
}

void CollisionBBox::SetDynamic(bool dynamic)
{
	this->Dynamic = dynamic;
}

void CollisionBBox::SetTrigger(bool trigger)
{
	this->isTrigger = trigger;
}

bool CollisionBBox::GetTrigger()
{
	return this->isTrigger;
}

void CollisionBBox::SetDirection(D3DXVECTOR2 d)
{
	this->direction = d;
}

D3DXVECTOR2 CollisionBBox::GetDirection()
{
	return this->direction;
}

float CollisionBBox::GetDx()
{
	return this->dx;
}

void CollisionBBox::SetDx(float dx)
{
	this->dx = dx;
}

float CollisionBBox::GetDy()
{
	return this->dy;
}

void CollisionBBox::GetDy(float dy)
{
	this->dy = dy;
}

D3DXVECTOR2 CollisionBBox::GetPositionInGame()
{
	D3DXVECTOR2 p;
	p = gameObj->GetPosition() + localTransformation.GetPosition();
	return p;
}

void CollisionBBox::SyncTransform()
{
}

CollisionBBox::CollisionBBox()
{
	localTransformation.SetPosition(D3DXVECTOR2(0, 0));
	localTransformation.SetScale(D3DXVECTOR2(1, 1));
	localTransformation.SetRotation(0.0f);

	width = 1.0f;
	height = 1.0f;

	this->isActive = true;

}

void CollisionBBox::Awake()
{
}

void CollisionBBox::Update()
{
	MonoBehaviour::Update();

	if (gameObj == NULL || gameObj->GetActive() == false)
	{
		return;
	}

	float dt = Game::GetInstance()->GetDeltaTime();

	this->dx = vx * dt;
	this->dy = dy * dt;

}

void CollisionBBox::FixedUpdate(vector<LPCOLLISIONBOX>* coObject)
{
	MonoBehaviour::FixedUpdate();

	Game* game = Game::GetInstance();

	if (gameObj == NULL || gameObj->GetActive() == false)
	{
		return;
	}

	float dt = game->GetFixedDeltaTime();

	LPCOLLISIONBOX collision = gameObj->GetCollisionBox();

	float vy = collision->GetVy();
	
	vy += collision->GetGravity() * dt;

	collision->SetVy(vy);

	vector<CollisionEvent*> coEvents;
	vector<CollisionEvent*> coEventsResult;

	coEvents.clear();
	coEventsResult.clear();

	CalcPotentialCollisions(coObject, coEvents);

	D3DXVECTOR2 position = gameObj->GetPosition();

	if (coEvents.size() == 0)
	{
		position.x += dx;
		position.y += dy;

		gameObj->SetPosition(position);
	}
	else
	{
		float min_tx;
		float min_ty;
		float nx = 0;
		float ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		position = gameObj->GetPosition();

		if (isTrigger == false)
		{
			position.x += min_tx * dx + nx * 0.4f;
			position.y += min_ty * dy + ny * 0.4f;
			gameObj->SetPosition(position);

		}

		if (nx != 0)
		{
			if (isTrigger == true)
			{
				//OnCollision
			}
			else
			{
				//OnTrigger
			}
			this->vx = 0;
		}

		if (ny != 0)
		{
			if (isTrigger == true)
			{
				//OnCollision
			}
			else
			{
				//OnTrigger
			}
			//if(gravity == 0)
		}
	
	}

	for (unsigned i = 0; i < coEvents.size(); i++)
	{
		delete coEvents[i];
	}

	coEvents.clear();
}

void CollisionBBox::Render(Camera* camera)
{
	D3DXVECTOR2 position = GetPositionInGame();

	LPDIRECT3DTEXTURE9 texture = Textures::GetInstance()->GetTexture(BBOX_TEXTURE);

	FloatRect bbox;
	bbox.left = 0;
	bbox.top = 0;
	bbox.right = width;
	bbox.bottom = height;

	D3DXVECTOR2 localpositioninCamera;
	D3DXVECTOR2 positionofcamera;

	positionofcamera = camera->GetCamPosition();

	localpositioninCamera.x = position.x - positionofcamera.x;
	localpositioninCamera.y = position.y - positionofcamera.y;

	RECT r;
	r.left = bbox.left;
	r.top = bbox.top;
	r.right = bbox.right;
	r.bottom = bbox.bottom;

	Game::GetInstance()->Draw(localpositioninCamera.x, localpositioninCamera.y, width * 0.5f, height * 0.5f, texture, r);
}

bool CollisionBBox::CheckAABB(FloatRect b2)
{
	return false;
}

void CollisionBBox::SweptAABB(float ml, float mt, float mr, float mb, float dx, float dy, float sl, float st, float sr, float sb, float& t, float& nx, float& ny)
{
	float dx_entry, dx_exit, tx_entry, tx_exit;
	float dy_entry, dy_exit, ty_entry, ty_exit;

	float t_entry;
	float t_exit;

	t = -1.0f;			// no collision
	nx = ny = 0;

	//
	// Broad-phase test 
	//

	float bl = dx > 0 ? ml : ml + dx;
	float bt = dy > 0 ? mt : mt + dy;
	float br = dx > 0 ? mr + dx : mr;
	float bb = dy > 0 ? mb + dy : mb;

	if (br < sl || bl > sr || bb < st || bt > sb) return;


	if (dx == 0 && dy == 0) return;		// moving object is not moving > obvious no collision

	if (dx > 0)
	{
		dx_entry = sl - mr;
		dx_exit = sr - ml;
	}
	else if (dx < 0)
	{
		dx_entry = sr - ml;
		dx_exit = sl - mr;
	}


	if (dy > 0)
	{
		dy_entry = st - mb;
		dy_exit = sb - mt;
	}
	else if (dy < 0)
	{
		dy_entry = sb - mt;
		dy_exit = st - mb;
	}

	if (dx == 0)
	{
		tx_entry = -999999.0f;
		tx_exit = 999999.0f;
	}
	else
	{
		tx_entry = dx_entry / dx;
		tx_exit = dx_exit / dx;
	}

	if (dy == 0)
	{
		ty_entry = -99999.0f;
		ty_exit = 99999.0f;
	}
	else
	{
		ty_entry = dy_entry / dy;
		ty_exit = dy_exit / dy;
	}


	if ((tx_entry < 0.0f && ty_entry < 0.0f) || tx_entry > 1.0f || ty_entry > 1.0f) return;

	t_entry = max(tx_entry, ty_entry);
	t_exit = min(tx_exit, ty_exit);

	if (t_entry > t_exit) return;

	t = t_entry;

	if (tx_entry > ty_entry)
	{
		ny = 0.0f;
		dx > 0 ? nx = -1.0f : nx = 1.0f;
	}
	else
	{
		nx = 0.0f;
		dy > 0 ? ny = -1.0f : ny = 1.0f;
	}
}

LPCOLLISIONEVENT CollisionBBox::SweptAABBEx(LPCOLLISIONBOX other)
{
	float sl, st, sr, sb;		// static object bbox
	float ml, mt, mr, mb;		// moving object bbox
	float t, nx, ny;

	FloatRect RectOfOther = other->GetRect();
	sl = RectOfOther.left;
	st = RectOfOther.top;
	sr = RectOfOther.right;
	sb = RectOfOther.bottom;

	float svx, svy;
	svx = other->GetVx();
	svy = other->GetVy();

	float sdx;
	float sdy;

	sdx = svx * Game::GetInstance()->GetDeltaTime();
	sdy = svy * Game::GetInstance()->GetDeltaTime();

	float rdx = this->dx - sdx;
	float rdy = this->dy - sdy;

	ml = GetRect().left;
	mt = GetRect().top;
	mr = GetRect().right;
	mb = GetRect().bottom;

	SweptAABB(
		ml, mt, mr, mb,
		rdx, rdy,
		sl, st, sr, sb,
		t,
		nx,
		ny
	);

	LPCOLLISIONEVENT e = new CollisionEvent(t, nx, ny, rdx, rdy, other);
	return e;
}

void CollisionBBox::CalcPotentialCollisions(vector<LPCOLLISIONBOX>* coObjects, vector<LPCOLLISIONEVENT>& coEvents)
{
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		//update logic of collision in here
	}
}

void CollisionBBox::FilterCollision(vector<LPCOLLISIONEVENT>& coEvents, vector<LPCOLLISIONEVENT>& coEventsResult, float& min_tx, float& min_ty, float& nx, float& ny)
{
	min_tx = 1.0f;
	min_ty = 1.0f;
	int min_ix = -1;
	int min_iy = -1;

	nx = 0.0f;
	ny = 0.0f;

	coEventsResult.clear();

	for (UINT i = 0; i < coEvents.size(); i++)
	{
		LPCOLLISIONEVENT c = coEvents[i];

		if (c->t < min_tx && c->nx != 0) {
			min_tx = c->t;
			nx = c->nx;
			min_ix = i;
		}

		if (c->t < min_ty && c->ny != 0) {
			min_ty = c->t;
			ny = c->ny;
			min_iy = i;
		}
	}

	if (min_ix >= 0)
	{
		coEventsResult.push_back(coEvents[min_ix]);
	}
	if (min_iy >= 0)
	{
		coEventsResult.push_back(coEvents[min_iy]);
	}
}
