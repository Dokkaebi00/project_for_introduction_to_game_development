#include "instanceManager.h"

void instanceManager::AddInstance(LPinstance instance)
{
	instances.push_back(instance);
}

void instanceManager::ClearInstances()
{
	for (auto i : instances)
	{
		delete i;
	}
	instances.clear();
}
