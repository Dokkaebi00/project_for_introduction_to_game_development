#pragma once
#include<vector>
#include"instance.h"

using namespace std;

class instanceManager
{
	vector<LPinstance> instances;
	
public:
	
	void AddInstance(LPinstance instance);

	template <typename T>T* GetAnInstance();

	void ClearInstances();
};

template<typename T>
inline T* instanceManager::GetAnInstance()
{
	for (auto instance : instances)
	{
		T* i = dynamic_cast<T*>(instance);
		if (i)
		{
			return i;
		}
	}
	return nullptr;
}
