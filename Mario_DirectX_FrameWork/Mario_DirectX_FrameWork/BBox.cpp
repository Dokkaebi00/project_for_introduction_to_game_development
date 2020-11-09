#include "BBox.h"

BBox::BBox()
{
	this->gameObject = NULL;
	this->localTransform.SetPosition(D3DXVECTOR2(0,0));
	this->localTransform.SetScale(D3DXVECTOR2(1, 1));
	this->localTransform.SetRotation(0);
	this->Box.left = 1;
	this->Box.top = 1;
	this->Box.right = 1;
	this->Box.bottom = 1;
	this->width = 0;
	this->height = 0;
}

void BBox::SetTransformation(Transformation transform)
{
	this->localTransform = transform;
}

Transformation BBox::GetTransformation()
{
	return this->localTransform;
}

void BBox::SetLocalPosition(D3DXVECTOR2 position)
{
	this->localTransform.SetPosition(position);
}

D3DXVECTOR2 BBox::GetLocalPosition()
{
	return this->localTransform.GetPosition();
}

void BBox::SetLocalRotation(float rotation)
{
	this->localTransform.SetRotation(rotation);
}

float BBox::GetLocalRotation()
{
	return this->localTransform.GetRotation();
}

void BBox::SetLocalScale(D3DXVECTOR2 scale)
{
	this->localTransform.SetScale(scale);
}

D3DXVECTOR2 BBox::GetLocalScale()
{
	return this->localTransform.GetScale();
}

FloatRect BBox::GetBoundingBox()
{
	D3DXVECTOR2 position = GetPositionInGame();
	FloatRect rect;
	rect.left = position.x - width * 0.5f;
	rect.top = position.y - height * 0.5f;
	rect.right = position.x + width * 0.5f;
	rect.bottom = position.y + height * 0.5f;

	return rect;
}

void BBox::SetSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

void BBox::GetSize(float& width, float& height)
{
	width = this->width;
	height = this->height;
}

void BBox::SetWidth(float width)
{
	this->width = width;
}

float BBox::GetWidth()
{
	return this->width;
}

void BBox::SetHeight(float height)
{
	this->height = height;
}

float BBox::GetHeight()
{
	return this->height;
}

void BBox::SetGameObject(LPGAMEOBJECT gameobj)
{
	this->gameObject = gameobj;
}

LPGAMEOBJECT BBox::GetGameObject()
{
	return this->gameObject;
}

D3DXVECTOR2 BBox::GetPositionInGame()
{
	D3DXVECTOR2 position = gameObject->GetPosition() + localTransform.GetPosition();
	return position;
}

void BBox::Render(Camera* camera)
{
	LPDIRECT3DTEXTURE9 texture = Textures::GetInstance()->GetTexture(BBOX_TEXTURE);
	
	
	FloatRect bb;
	bb.left = 0;
	bb.top = 0;
	bb.right = width;
	bb.bottom = height;
}

BBox::~BBox()
{
}

