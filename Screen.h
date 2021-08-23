// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#pragma once

#include <LCGE/lcge.h>

class Screen
{
public:
	Screen(LCGE_clock *clock);

	void run();

	virtual bool update() = 0;
private:
	LCGE_clock *m_clock;
};
