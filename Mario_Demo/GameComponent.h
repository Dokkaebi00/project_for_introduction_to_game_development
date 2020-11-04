#pragma once
class GameComponent
{
public:
	virtual void Init() = 0;
	virtual ~GameComponent() = default;
};

typedef GameComponent* LPGameComponent;