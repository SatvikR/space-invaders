// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#pragma once

#include "Alien.h"
#include <LCGE/lcge.h>

class AlienThree : public Alien
{
public:
	AlienThree(float x, float y);

	void draw();
	float width();
	float height();
	int points();

	static void delete_sprite();

	static constexpr float sprite_width = 32.0f;
	static constexpr float sprite_height = 31.0f;
private:
	static LCGE_image *m_sprite;
	static constexpr char m_sprite_path[] =
		"assets/images/invader3-small.png";
};