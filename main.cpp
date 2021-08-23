// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#include "Game.h"
#include <LCGE/lcge.h>
#include <iostream>

int main(int argc, char const *argv[])
{
	Game game;

	bool success = game.setup();
	if (!success) {
		std::cerr << "failed to initialized LCGE" << std::endl;
		return -1;
	}

	game.run();

	return 0;
}
