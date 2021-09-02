// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#pragma once

#include "Alien.h"
#include "Globals.h"
#include <LCGE/lcge.h>
#include <vector>

class Laser
{
public:
	Laser(float x);

	void update();
	void draw();

	bool collided(std::vector<Alien*> aliens, unsigned int &points);

	static void delete_sprite();
private:
	float m_x, m_y;

	static LCGE_image *m_sprite;

	static constexpr char m_sprite_path[] = "assets/images/laser.png";

	static constexpr float m_sprite_width = 14.0f;
	static constexpr float m_sprite_height = 50.0f;

	static constexpr float m_starting_y = Globals::HEIGHT * 0.8f;

	static constexpr float m_speed = 10.0f;
};