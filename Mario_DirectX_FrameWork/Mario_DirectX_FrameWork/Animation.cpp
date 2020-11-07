#include "Animation.h"

Animation::Animation(string id, DWORD defaultTime)
{
	this->id = id;
	this->currentFrame = -1;
	this->defaultTime = defaultTime;
	
	this->isLooping = false;

	this->isEnabled = false;

	this->transform.position = D3DXVECTOR2(0.0f, 0.0f);
}

void Animation::Add(LPSPRITE sprite, D3DXVECTOR2 position, DWORD frameTime)
{
	int t = frameTime;
	
	if (frameTime <= 0)
	{
		t = this->defaultTime;
	}

	LPANIMATION_FRAME frame = new AnimationFrame(sprite, t, position);

	frames.push_back(frame);
}

void Animation::Render(D3DXVECTOR2 position, int alpha)
{
	if (frames.size() == 0)
	{
		return;
	}

	DWORD now = GetTickCount();

	if (currentFrame == -1)
	{
		currentFrame = 0;
		lastFrameTime = now;
	}
	else
	{
		DWORD t = frames[currentFrame]->GetTime();
		if (now - lastFrameTime > t * Game::GetTimeScale())
		{
			if (currentFrame == frames.size() - 1 && isLooping == false)
			{
				//gameobj->EndAnimation();
				isEnabled = false;
			}
			else if (isEnabled == true)
			{
				currentFrame++;
				lastFrameTime = now;
				if (currentFrame >= frames.size())
				{
					currentFrame = 0;
				}
			}
		}
	}

	frames[currentFrame]->GetSprite()->Draw(position.x, position.y, transform.scale, transform.rotation);
}

void Animation::SetPosition(D3DXVECTOR2 position)
{
	this->transform.position = position;
}

void Animation::SetScale(D3DXVECTOR2 scale)
{
	this->transform.scale = scale;
}

void Animation::SetRotation(float rotation)
{
	this->transform.rotation = rotation;
}

void Animation::SetLoop(bool isLoop)
{
	this->isLooping = isLoop;
}

void Animation::SetRelativePosition(D3DXVECTOR2 relativeposition)
{
	this->relativePosition = relativeposition;
}

void Animation::SetEnabled(bool enable)
{
	if (enable == false && isLooping == false)
	{
		currentFrame = -1;
	}
	isEnabled = true;
}

D3DXVECTOR2 Animation::GetPosition()
{
	return this->transform.position;
}

D3DXVECTOR2 Animation::GetScale()
{
	return this->transform.scale;
}

float Animation::GetRotation()
{
	return this->transform.rotation;
}

bool Animation::GetIsLooping()
{
	return this->isLooping;
}

LPANIMATION_FRAME Animation::GetAnimFrame()
{
	if (currentFrame != -1)
	{
		return frames[currentFrame];
	}
	return NULL;
}

D3DXVECTOR2 Animation::GetRelativePosition()
{
	return this->relativePosition;
}

void Animation::SetGameObject(LPGAMEOBJECT obj)
{
	this->gameobj = obj;
}

LPGAMEOBJECT Animation::GetGameObject()
{
	return this->gameobj;
}

int Animation::GetNumberOfFrames()
{
	return frames.size();
}


