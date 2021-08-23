// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#pragma once

#include <LCGE/lcge.h>

class Game
{
public:
	Game() = default;
	~Game();

	bool setup();
	void run();
private:
	LCGE_clock *m_clock;

	static constexpr char LCGE_RES_DIR[] = "assets/LCGE";
};