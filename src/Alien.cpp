// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#include "Alien.h"
#include <LCGE/lcge.h>

Alien::Alien(float x, float y)
{
	m_x = x;
	m_y = y;

	m_vel_x = m_speed;
	m_curr_frame = 0.0f;
}

void Alien::update_pos()
{
	m_x += m_vel_x;

	if (m_curr_frame++ >= m_move_frames)
	{
		m_vel_x = -m_vel_x;
		m_curr_frame = 0;
	}
}

float Alien::x()
{
	return m_x;
}

float Alien::y()
{
	return m_y;
}

void Alien::_draw(LCGE_image *sprite)
{
	lcge_image_set(
		sprite,
		m_x,
		m_y,
		lcge_image_get_width(sprite),
		lcge_image_get_height(sprite)
	);
	lcge_image_draw(sprite);
}
