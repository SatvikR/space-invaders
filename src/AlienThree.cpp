// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#include "Alien.h"
#include "AlienThree.h"
#include <LCGE/lcge.h>

LCGE_image *AlienThree::m_sprite = nullptr;

AlienThree::AlienThree(float x, float y)
	: Alien(x, y)
{
	if (m_sprite == nullptr)
	{
		m_sprite = lcge_image_load(
			m_sprite_path,
			0,
			0,
			sprite_width,
			sprite_height
		);
	}
}

void AlienThree::draw()
{
	_draw(m_sprite);
}

void AlienThree::delete_sprite()
{
	lcge_image_delete(m_sprite);
}

float AlienThree::width()
{
	return sprite_width;
}

float AlienThree::height()
{
	return sprite_height;
}

int AlienThree::points()
{
	return 30;
}