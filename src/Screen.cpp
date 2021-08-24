// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#include "Screen.h"
#include <LCGE/lcge.h>

Screen::Screen(LCGE_clock *clock)
{
	m_clock = clock;
}

void Screen::run()
{
	while (lcge_window_is_open())
	{
		lcge_window_clear();

		bool status = update();
		if (!status)
			return;

		lcge_clock_tick(m_clock);
		lcge_window_update();
	}
}