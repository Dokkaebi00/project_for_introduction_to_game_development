#include "GameComponentHandling.h"

void GameComponentHandling::AddService(LPGameComponent gamecomponent)
{
	GameComponents.push_back(gamecomponent);
}

void GameComponentHandling::ClearGameComponents()
{
	for (auto gamecomponent : GameComponents)
	{
		delete gamecomponent;
	}
	GameComponents.clear();
}
