// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#include "Laser.h"
#include <LCGE/lcge.h>
#include <vector>

LCGE_image *Laser::m_sprite = nullptr;

Laser::Laser(float x)
{
	if (m_sprite == nullptr)
	{
		m_sprite = lcge_image_load(
			m_sprite_path,
			0,
			0,
			m_sprite_width,
			m_sprite_height
		);
	}

	m_x = x;
	m_y = m_starting_y;
}

void Laser::update()
{
	m_y -= m_speed;
}

void Laser::draw()
{
	lcge_image_set(
		m_sprite,
		m_x,
		m_y,
		m_sprite_width,
		m_sprite_height
	);

	lcge_image_draw(m_sprite);
}

bool Laser::collided(std::vector<Alien*> aliens)
{
	for (auto &a : aliens)
	{
		float l_x = m_x;
		float r_x = m_x + m_sprite_width
		if (a->x() <= l_x && r_x <= (a->x() + a->width()) &&
			a->y() <= m_y && m_y <= (a->y() + a->height()))
		{
			a->kill();
			return true;
		}
	}
	return false;
}

void Laser::delete_sprite()
{
	lcge_image_delete(m_sprite);
}