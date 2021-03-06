// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#include "Alien.h"
#include "AlienOne.h"
#include <LCGE/lcge.h>

LCGE_image *AlienOne::m_sprite = nullptr;

AlienOne::AlienOne(float x, float y)
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

void AlienOne::draw()
{
	_draw(m_sprite);
}

void AlienOne::delete_sprite()
{
	lcge_image_delete(m_sprite);
}

float AlienOne::width()
{
	return sprite_width;
}

float AlienOne::height()
{
	return sprite_height;
}

int AlienOne::points()
{
	return 10;
}