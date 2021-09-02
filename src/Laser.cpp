// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#include "Laser.h"
#include "Util.h"
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

bool Laser::collided(std::vector<Alien*> aliens, unsigned int &points)
{
	if (m_y + m_sprite_height < 0)
		return true;

	for (auto &a : aliens)
	{

		if (Util::rect_collding(a->x(), a->y(), a->width(), a->height(),
					m_x, m_y, m_sprite_width,
					m_sprite_height))
		{
			points += a->points();
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