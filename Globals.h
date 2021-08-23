// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#pragma once

class Globals
{
public:
	struct Color {
		float r;
		float g;
		float b;
	};

	static constexpr unsigned int WIDTH = 800;
	static constexpr unsigned int HEIGHT = 800;

	static constexpr char TITLE[] = "Space Invaders";

	static constexpr unsigned int FPS = 60;

	static constexpr Color GREEN = { 0.0f, 255.0f, 0.0f };
};
