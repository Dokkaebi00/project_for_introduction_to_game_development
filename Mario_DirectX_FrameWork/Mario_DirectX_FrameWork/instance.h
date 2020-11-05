#pragma once

class instance
{
public:
	virtual void Init() = 0;
	virtual ~instance() = default;
};

typedef instance* LPinstance;