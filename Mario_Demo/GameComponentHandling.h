#pragma once
#include<typeinfo>
#include<vector>
#include"GameComponent.h"

using namespace std;

class GameComponentHandling
{
	vector<LPGameComponent> GameComponents;

public:
	template<typename T> T* GetGameComponent();
	void AddService(LPGameComponent gamecomponent);

	void ClearGameComponents();
};

template<typename T>
inline T* GameComponentHandling::GetGameComponent()
{
	for (auto gamecomponent : GameComponents)
	{
		T* gc = dynamic_cast<T*>(gamecomponent);
		if (gc)
		{
			return gc;
		}
	}
	return nullptr;
}
