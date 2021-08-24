// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#include "Alien.h"
#include "AlienTwo.h"
#include <LCGE/lcge.h>

LCGE_image *AlienTwo::m_sprite = nullptr;

AlienTwo::AlienTwo(float x, float y)
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

void AlienTwo::draw()
{
	_draw(m_sprite);
}

void AlienTwo::delete_sprite()
{
	lcge_image_delete(m_sprite);
}